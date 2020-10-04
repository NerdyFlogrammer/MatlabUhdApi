close all; clear all; clc;

addpath('../matlab')
import uhd.usrp.*;
import uhd.types.*;

% gerneral config
channel0 = int64(0);
masterClockRate = 5e6;
% rx config
rxFreq = 2.4e9;
rxRate = masterClockRate/10;
rxGain = 45;


try
    devices = multi_usrp.findDevices()
    usrp = multi_usrp(devices(1));

    %% usrp config
    usrp.setRxSubdevSpec(subdev_spec.RF_AA);
    readRxSubDevSpec = usrp.getRxSubdevSpec()

    usrp.setMasterClockRate(masterClockRate);
    readClk = usrp.getMasterClockRate()

    rxTuneRequest = tune_request(rxFreq);
    rxTuneResult = usrp.setRxFreq(rxTuneRequest)

    usrp.setRxRate(rxRate);
    readRxRate = usrp.getRxRate()
 
    usrp.setRxGain(rxGain,"",channel0);
    readRxGain = usrp.getRxGain("",channel0)

    usrp.setClockSource(clock_source.EXTERNAL);
    usrp.setTimeSource(time_source.EXTERNAL);

    %% create streamer
    streamArgs = stream_args(cpu_format.COMPLEX_DOUBLE, otw_format.Q16_I16);
    rxStreamer = usrp.getRxStream(streamArgs); 
    
    %% setup receiver 
    lastPpsTime = usrp.getTimeLastPps().real_secs;
    while lastPpsTime == usrp.getTimeLastPps().real_secs
		%sleep 100 milliseconds (give or take)
        pause(0.1);
    end
    
    usrp.setTimeNextPps(0);
    pause(1);
        
    
    
    rxMetadata = struct;
    recvTime = 3;
    streamCmd.stream_mode = stream_mode.STREAM_MODE_NUM_SAMPS_AND_DONE;
    streamCmd.stream_now = false;
    streamCmd.time_spec = recvTime;
    rxStreamer.issueStreamCmd(streamCmd);
  
    %% send and receive message 
    messageLen = int64(4000);
    timeout = recvTime + 0.2;
    [md, numSamps, buff] = rxStreamer.recv(messageLen, rxMetadata, timeout);
    
    %% close usrp
    usrp.delete();
	
catch ex
    if isa( usrp, 'multi_usrp' )
        usrp.delete();
        disp("uhd closed");
    end
    disp(ex.identifier);
    rethrow(ex);
end

