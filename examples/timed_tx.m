close all; clear all; clc;

addpath('../matlab')
import uhd.usrp.*;
import uhd.types.*;

% gerneral config
channel0 = int64(0);
channel1 = int64(1);
masterClockRate = 5e6;
% tx config
txFreq = 2.4e9;
txRate = masterClockRate/10;
txGain = 65;

try
    devices = multi_usrp.findDevices()
    usrp = multi_usrp(devices(1));

    %% usrp config
    usrp.setTxSubdevSpec(subdev_spec.RF_AA_AB);
    readTxSubDevSpec = usrp.getTxSubdevSpec()
    
    usrp.setMasterClockRate(masterClockRate);
    readClk = usrp.getMasterClockRate()

    txTuneRequest = tune_request(txFreq);
    txTuneResult = usrp.setTxFreq(txTuneRequest)
    
    usrp.setTxRate(txRate);
    readTxRate = usrp.getTxRate()
        
    usrp.setTxGain(txGain,"",channel0);
    usrp.setTxGain(txGain,"",channel1);

    usrp.setClockSource(clock_source.EXTERNAL);
    usrp.setTimeSource(time_source.EXTERNAL);
    
    lastPpsTime = usrp.getTimeLastPps().real_secs;
    while lastPpsTime == usrp.getTimeLastPps().real_secs
		%sleep 100 milliseconds (give or take)
        pause(0.1);
    end

    %% create streamer
    streamArgs = stream_args(cpu_format.COMPLEX_DOUBLE, otw_format.Q16_I16);
    streamArgs.channels = [0, 1];
    txStreamer = usrp.getTxStream(streamArgs);

    %% create message 
    bpskmod = comm.BPSKModulator;
    data = randi([0 1],2000,1);
    modData = bpskmod(data);
    
    misoMessage = [modData;modData];
    messageLen = int64(length(modData));
      
    usrp.setTimeNextPps(0);
    pause(1);
    
    %% setup transmitter
    sendTime = 3;
    txMetadata = struct;
    txMetadata.has_time_spec = true;
    txMetadata.time_spec = sendTime;
    txMetadata.start_burst = true;
      
    %% send message 
    timeout = sendTime + 0.2;
    [~,mdtx] = txStreamer.send(misoMessage, messageLen, txMetadata, timeout);
          
    %% close usrp
    usrp.delete();
    
catch ex
    if isa( usrp, 'multi_usrp' )
        usrp.delete();
        disp("usrp closed");
    end
    disp(ex.identifier);
    rethrow(ex);
end