classdef multi_usrp < matlab.System
    % This class facilitates ease-of-use for most use-case scenarios. 
    % The wrapper provides convenience functions to tune the devices, set 
    % the dboard gains, antennas, filters, and other properties. This class 
    % can be used to interface with a single USRP with one or more channels, 
    % or multiple USRPs in a homogeneous setup. All members take an optional 
    % parameter for board number or channel number. In the single device, 
    % single channel case, these parameters can be unspecified.
    
    properties (Access = private)
      device
      logfile
    end
     
    methods (Static)
        function devices = findDevices() 
            devices = uhdapi("find_devices");
        end
        
        function closeAll()
            uhdapi("close_all");
        end
    end
    
    methods (Access = public)
        
        function obj = multi_usrp(device, logfile)
            % multiusrp Creates a multiusrp object.
            % Inputs:
            %   device the arguments string 
            %          Ex: addr=192.168.10.2
            %          Ex: addr=192.168.10.2, recv_buff_size=1e6
            %   enableLogger if true: creates a log file in the working directory
            %          default = true
            switch nargin
                case 1
                    obj.device = uhdapi("init_uhd", device);
                case 2
                    obj.device = uhdapi("init_uhd", device, logfile);
                    obj.logfile = logfile;
                otherwise
                     narginchk(1,2);
            end
        end
        
        function delete(obj)
            % delete Destroys the current object in uhdapi (C++ Wrapper)
            uhdapi("close", obj.device);
        end
        
        function openLogfile(obj)
            % openLogfile Opens the logfile of this object in matlab editor,
            % if a logfile exists
            if  isempty(obj.logfile) 
                disp("no logfile exists");
            else
                open(obj.logfile);
            end
        end
        
        %% General methods
        
        function rxStreamer =  getRxStream(obj, streamArgs)
            %getRxStream Creates a rx stream object with given args
            %Inputs:
            %   streamArgs See class stream_args
            %Returns:
            %   rx_streamer object
            uhdapi("create_rx_stream", obj.device, streamArgs);
            rxStreamer = uhd.usrp.rx_streamer(obj.device);
        end
        
        function txStreamer = getTxStream(obj, streamArgs)
            % getTxStream Creates a tx stream object with given args
            % Inputs:
            %   streamArgs See class stream_args
            % Returns:
            %   tx_streamer object
            uhdapi("create_tx_stream", obj.device, streamArgs);
            txStreamer = uhd.usrp.tx_streamer(obj.device);
        end
                
        function rxInfo = getUsrpRxInfo(obj, chan)
            % getUsrpRxInfo Returns identifying information about this USRP's 
            % configuration. Returns motherboard ID, name, and serial. Returns 
            % daughterboard RX ID, subdev name and spec, serial, and antenna.
            % Inputs:
            %   chan channel index 0 to N-1
            % Returns:
            %   RX info
            switch nargin
                case 1
                    rxInfo = uhdapi("get_usrp_rx_info", obj.device);
                case 2
                    rxInfo = uhdapi("get_usrp_rx_info", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function txInfo = getUsrpTxInfo(obj, chan)
            % getUsrpTxInfo Returns identifying information about this USRP's 
            % configuration. Returns motherboard ID, name, and serial. Returns 
            % daughterboard TX ID, subdev name and spec, serial, and antenna.
            % Inputs:
            %   chan channel index 0 to N-1
            % Returns:
            %   TX info
             switch nargin
                case 1
                    txInfo = uhdapi("get_usrp_tx_info", obj.device);
                case 2
                    txInfo = uhdapi("get_usrp_tx_info", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        %% Mboard methods
        
        function setMasterClockRate(obj, rate, mboard)
            % setMasterClockRate Sets the master clock rate.
            % Inputs:
            %   rate	the new master clock rate in Hz
            %   mboard	the motherboard index 0 to M-1 (optional, default = ALL_MBOARDS)
            switch nargin
                case 2
                    uhdapi("set_master_clock_rate",obj.device, rate);
                case 3
                    uhdapi("set_master_clock_rate",obj.device, rate, mboard);
                otherwise
                    narginchk(2,3);
            end       
        end
        
        function clkRate = getMasterClockRate(obj, mboard) 
            % getMasterClockRate Gets the master clock rate.
            % Inputs:
            %   mboard	the motherboard index 0 to M-1 (optional, default = 0)
            % Returns:    
            %           the master clock rate in Hz.
            switch nargin
                case 1
                    clkRate = uhdapi("get_master_clock_rate",obj.device);
                case 2
                    clkRate = uhdapi("get_master_clock_rate",obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function range = getMasterClockRateRange(obj, mboard) 
            switch nargin
                case 1
                    range = uhdapi("get_master_clock_rate_range",obj.device);
                case 2
                    range = uhdapi("get_master_clock_rate_range",obj.device, mboard);
                otherwise
                    nargin(1,2);
            end 
        end
        
        function pp = getPpString(obj)
            pp = uhdapi("get_pp_string",obj.device);
        end
        
        function mboard = getMBoardName(obj, mboard)
            switch nargin
                case 1
                    mboard = uhdapi("get_mboard_name",obj.device);
                case 2
                    mboard = uhdapi("get_mboard_name",obj.device, mboard);
                otherwise
                    nargin(1,2);
            end
        end
        
        function time = getTimeNow(obj, mboard)
            switch nargin
                case 1
                    time = uhdapi("get_time_now", obj.device);
                case 2
                    time = uhdapi("get_time_now", obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function time = getTimeLastPps(obj, mboard)
            switch nargin
                case 1
                    time = uhdapi("get_time_last_pps", obj.device);
                case 2
                    time = uhdapi("get_time_last_pps", obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end
        end      
        
        function setTimeNow(obj, time, mboard)
            switch nargin
                case 2
                    uhdapi("set_time_now", obj.device, time);
                case 3
                    uhdapi("set_time_now", obj.device, time, mboard);
                otherwise
                    narginchk(2,3);
            end            
        end
        
        function setTimeNextPps(obj, timeSpec, mboard)
            switch nargin
                case 2
                    uhdapi("set_time_next_pps", obj.device, timeSpec);
                case 3
                    uhdapi("set_time_next_pps", obj.device, timeSpec, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function setTimeUnknownPps(obj, timeSpec)
            uhdapi("set_time_unknown_pps",obj.device, timeSpec);
        end
        
        function isSync = getTimeSynchronized(obj)
            isSync = uhdapi("get_time_synchronized",obj.device);
        end
        
        function setCommandTime(obj, time, mboard)
            switch nargin
                case 2
                    uhdapi("set_command_time", obj.device, time);
                case 3
                    uhdapi("set_command_time", obj.device, time , mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function clearCommandTime(obj, mboard)
            switch nargin
                case 1
                    uhdapi("clear_command_time", obj.device);
                case 2
                    uhdapi("clear_command_time", obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end
        end
        
      function issueStreamCmd(obj, streamCmd, chan)
          switch nargin
              case 2
                  uhdapi("issue_stream_cmd", obj.device, streamCmd);
              case 3
                  uhdapi("issue_stream_cmd", obj.device, streamCmd, chan);
              otherwise
                  narginchk(2,3);    
          end
      end
        
        function setTimeSource(obj, timeSrc, mboard)
            switch nargin
                case 2
                    uhdapi("set_time_source",obj.device, timeSrc);
                case 3
                    uhdapi("set_time_source",obj.device, timeSrc, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function timeSrc = getTimeSource(obj, mboard)
            timeSrc = uhdapi("get_time_source", obj.device, mboard);
        end
        
        function timeSrc = getTimeSources(obj, mboard)
            timeSrc = uhdapi("get_time_sources", obj.device, mboard);
        end
        
        function setClockSource(obj, clkSrc, mboard)
            switch nargin
                case 2
                    uhdapi("set_clock_source",obj.device, clkSrc); 
                case 3
                    uhdapi("set_clock_source",obj.device, clkSrc, mboard); 
                otherwise
                    narginchk(2,3);
            end
        end
        
        function clkSrc = getClockSource(obj, mboard)
            clkSrc = uhdapi("get_clock_source",obj.device, mboard); 
        end
        
        function clkSrcs = getClockSources(obj, mboard)
            clkSrcs = uhdapi("get_clock_sources",obj.device, mboard); 
        end
        
        function setSyncSource(obj, clkSrc, timeSrc, mboard)
            switch nargin
                case 3
                    uhdapi("set_sync_source",obj.device, clkSrc, timeSrc);
                case 4
                    uhdapi("set_sync_source",obj.device, clkSrc, timeSrc, mboard);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function syncSrc = getSyncSource(obj, mboard)
            syncSrc = uhdapi("get_sync_source",obj.device, mboard);
        end
        
        function syncSrcs = getSyncSources(obj, mboard)
            syncSrcs = uhdapi("get_sync_sources", obj.device, mboard);
        end
        
        function setClockSourceOut(obj, enb, mboard)
            switch nargin
                case 2
                    uhdapi("set_clock_source_out", obj.device, enb);
                case 3
                    uhdapi("set_clock_source_out", obj.device, enb, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function setTimeSourceOut(obj, enb, mboard)
            switch nargin
                case 2
                    uhdapi("set_time_source_out", obj.device, enb);
                case 3
                    uhdapi("set_time_source_out", obj.device, enb, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function numMboard = getNumMboards(obj)
            numMboard = uhdapi("get_num_mboards", obj.device);
        end
        
        function sensor = getMboardSensor(obj, name, mboard)
            switch nargin
                case 2
                    sensor = uhdapi("get_mboard_sensor", obj.device, name);
                case 3
                    sensor = uhdapi("get_mboard_sensor", obj.device, name, mboard);
                otherwise
                    narginchk(2,3); 
            end
        end
        
        function sensorNames = getMboardSensorNames(obj, mboard) 
            switch nargin
                case 1
                   sensorNames = uhdapi("get_mboard_sensor_names", obj.device);
                case 2
                   sensorNames = uhdapi("get_mboard_sensor_names", obj.device, mboard);
                otherwise
                    narginchk(1,2);                        
            end
        end
        
        function setUserRegister(obj, addr, data, mboard)
            switch nargin
                case 3
                    uhdapi("set_user_register", obj.device, addr, data);
                case 4
                    uhdapi("set_user_register", obj.device, addr, data, mboard);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function wbIface = getUserSettingsIface(obj, chan)
            switch nargin
                case 1
                    uhdapi("create_user_settings_iface", obj.device);
                    wbIface = uhd.usrp.wb_iface(obj.device);
                case 2
                    uhdapi("create_user_settings_iface", obj.device, chan);
                    wbIface = uhd.usrp.wb_iface(obj.device);
                otherwise
                    narginchk(1,2);
            end
        end
        
        
        %% Rx methods
        
        function setRxSubdevSpec(obj, subdevSpec, mboard)
            switch nargin
                case 2
                    uhdapi("set_rx_subdev_spec",obj.device, subdevSpec);
                case 3
                    uhdapi("set_rx_subdev_spec",obj.device, subdevSpec, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function subdevSpec = getRxSubdevSpec(obj, mboard)
            switch nargin
                case 1
                    subdevSpec = uhdapi("get_rx_subdev_spec",obj.device);
                case 2
                    subdevSpec = uhdapi("get_rx_subdev_spec",obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end  
        end
        
        function rxNumChan = getRxNumChannels(obj)
            rxNumChan = uhdapi("get_rx_num_channels", obj.device);
        end
        
        function rxSubdevName = getRxSubdevName(obj, chan)
            switch nargin
                case 1
                    rxSubdevName = uhdapi("get_rx_subdev_name", obj.device);
                case 2
                    rxSubdevName = uhdapi("get_rx_subdev_name", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setRxRate(obj, rxRate, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_rate", obj.device,rxRate);
                case 3
                    uhdapi("set_rx_rate", obj.device,rxRate, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function rxRate = getRxRate(obj, chan)
            switch nargin
                case 1
                    rxRate = uhdapi("get_rx_rate", obj.device);
                case 2
                    rxRate = uhdapi("get_rx_rate", obj.device, chan);
                otherwise
                    narginchk(1,2)  
            end  
        end
        
        function rxRates = getRxRates(obj, chan)
            switch nargin
                case 1
                    rxRates = uhdapi("get_rx_rates", obj.device);
                case 2
                    rxRates = uhdapi("get_rx_rates", obj.device, chan);
                otherwise
            end
        end
        
        function tuneResult = setRxFreq(obj, tuneRequest, chan)
            switch nargin
                case 2
                    tuneResult = uhdapi("set_rx_freq",obj.device, tuneRequest);
                case 3
                    tuneResult = uhdapi("set_rx_freq",obj.device, tuneRequest, chan);
                otherwise
                    narginchk(2,3)
            end
        end
        
        function rxFreq = getRxFreq(obj, chan)
            switch nargin
                case 1
                    rxFreq = uhdapi("get_rx_freq",obj.device);
                case 2
                    rxFreq = uhdapi("get_rx_freq",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end   
        
        function freqRange = getRxFreqRange(obj, chan)
            switch nargin
                case 1
                    freqRange = uhdapi("get_rx_freq_range",obj.device);
                case 2
                    freqRange = uhdapi("get_rx_freq_range",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end    
        
        function feRxFreqRange = getFeRxFreqRange(obj, chan)
            switch nargin
                case 1
                    feRxFreqRange = uhdapi("get_fe_rx_freq_range",obj.device);
                case 2
                    feRxFreqRange = uhdapi("get_fe_rx_freq_range",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end   
        
        %% LO controls
        
        function rxLoNames = getRxLoNames(obj, chan)
            switch nargin
                case 1
                    rxLoNames = uhdapi("get_rx_lo_names",obj.device);
                case 2
                    rxLoNames = uhdapi("get_rx_lo_names",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end  
        
        
        function setRxLoSource(obj, src, name, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_lo_source",obj.device, src);
                case 3
                    uhdapi("set_rx_lo_source",obj.device, src, name);
                case 4
                    uhdapi("set_rx_lo_source",obj.device, src, name, chan);
                otherwise
                    narginchk(2,4);
            end   
        end  
        
        function rxLoSource = getRxLoSource(obj, name, chan)
            switch nargin
                case 1
                    rxLoSource = uhdapi("get_rx_lo_source",obj.device);
                case 2
                    rxLoSource = uhdapi("get_rx_lo_source",obj.device, name);
                case 3
                    rxLoSource = uhdapi("get_rx_lo_source",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end   
        end  
        
        function rxLoSources = getRxLoSources(obj, name, chan)
            switch nargin
                case 1
                    rxLoSources = uhdapi("get_rx_lo_sources",obj.device);
                case 2
                    rxLoSources = uhdapi("get_rx_lo_sources",obj.device, name);
                case 3
                    rxLoSources = uhdapi("get_rx_lo_sources",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end   
        end  
        
        function setRxLoExportEnabled(obj, enabled, name, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_lo_export_enabled", obj.device, enabled);
                case 3
                    uhdapi("set_rx_lo_export_enabled", obj.device, enabled, name);
                case 4
                    uhdapi("set_rx_lo_export_enabled", obj.device, enabled, name, chan);
                otherwise
                    narginchk(2,4);
            end
        end
        
        function rxLoExportEnab = getRxLoExportEnabled(obj, name, chan)
            switch nargin
                case 1
                    rxLoExportEnab = uhdapi("get_rx_lo_export_enabled", obj.device);
                case 2
                    rxLoExportEnab = uhdapi("get_rx_lo_export_enabled",obj.device, name);
                case 3
                    rxLoExportEnab = uhdapi("get_rx_lo_export_enabled",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end
        end
        
        function rxLoFreq = setRxLoFreq(obj, freq, name, chan)
            switch nargin
                case 3
                    rxLoFreq = uhdapi("set_rx_lo_freq", obj.device, freq, name);
                case 4
                    rxLoFreq = uhdapi("set_rx_lo_freq", obj.device, freq, name, chan);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function rxLoFreq = getRxLoFreq(obj, name, chan)
            switch nargin
                case 2
                    rxLoFreq = uhdapi("get_rx_lo_freq", obj.device, name);
                case 3
                    rxLoFreq = uhdapi("get_rx_lo_freq", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxLoFreqRange = getRxLoFreqRange(obj, name, chan)
            switch nargin
                case 2
                    rxLoFreqRange = uhdapi("get_rx_lo_freq_range", obj.device, name);
                case 3
                    rxLoFreqRange = uhdapi("get_rx_lo_freq_range", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txLoNames = getTxLoNames(obj, chan)
            switch nargin
                case 1
                    txLoNames = uhdapi("get_tx_lo_names",obj.device);
                case 2
                    txLoNames = uhdapi("get_tx_lo_names",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end  
        
        
        function setTxLoSource(obj, src, name, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_lo_source",obj.device, src);
                case 3
                    uhdapi("set_tx_lo_source",obj.device, src, name);
                case 4
                    uhdapi("set_tx_lo_source",obj.device, src, name, chan);
                otherwise
                    narginchk(2,4);
            end   
        end  
        
        function txLoSource = getTxLoSource(obj, name, chan)
            switch nargin
                case 1
                    txLoSource = uhdapi("get_tx_lo_source",obj.device);
                case 2
                    txLoSource = uhdapi("get_tx_lo_source",obj.device, name);
                case 3
                    txLoSource = uhdapi("get_tx_lo_source",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end   
        end  
        
        function txLoSources = getTxLoSources(obj, name, chan)
            switch nargin
                case 1
                    txLoSources = uhdapi("get_tx_lo_sources",obj.device);
                case 2
                    txLoSources = uhdapi("get_tx_lo_sources",obj.device, name);
                case 3
                    txLoSources = uhdapi("get_tx_lo_sources",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end   
        end  
        
        function setTxLoExportEnabled(obj, enabled, name, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_lo_export_enabled", obj.device, enabled);
                case 3
                    uhdapi("set_tx_lo_export_enabled", obj.device, enabled, name);
                case 4
                    uhdapi("set_tx_lo_export_enabled", obj.device, enabled, name, chan);
                otherwise
                    narginchk(2,4);
            end
        end
        
        function txLoExportEnab = getTxLoExportEnabled(obj, name, chan)
            switch nargin
                case 1
                    txLoExportEnab = uhdapi("get_tx_lo_export_enabled", obj.device);
                case 2
                    txLoExportEnab = uhdapi("get_tx_lo_export_enabled",obj.device, name);
                case 3
                    txLoExportEnab = uhdapi("get_tx_lo_export_enabled",obj.device, name, chan);
                otherwise
                    narginchk(1,3);
            end
        end
        
        function txLoFreq = setTxLoFreq(obj, freq, name, chan)
            switch nargin
                case 3
                    txLoFreq = uhdapi("set_tx_lo_freq", obj.device, freq, name);
                case 4
                    txLoFreq = uhdapi("set_tx_lo_freq", obj.device, freq, name, chan);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function txLoFreq = getTxLoFreq(obj, name, chan)
            switch nargin
                case 2
                    txLoFreq = uhdapi("get_tx_lo_freq", obj.device, name);
                case 3
                    txLoFreq = uhdapi("get_tx_lo_freq", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txLoFreqRange = getTxLoFreqRange(obj, name, chan)
            switch nargin
                case 2
                    txLoFreqRange = uhdapi("get_tx_lo_freq_range", obj.device, name);
                case 3
                    txLoFreqRange = uhdapi("get_tx_lo_freq_range", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        %% Gain Controls
        
        function setRxGain(obj, gain, name, chan)
            switch nargin
                case 3
                    uhdapi("set_rx_gain", obj.device, gain, name);
                case 4
                    uhdapi("set_rx_gain", obj.device, gain, name, chan);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function rxGainProfileNames = getRxGainProfileNames(obj, chan)
            switch nargin
                case 1
                    rxGainProfileNames = uhdapi("get_rx_gain_profile_names", obj.device);
                case 2
                    rxGainProfileNames = uhdapi("get_rx_gain_profile_names", obj.device, chan);
                otherwise
                    narginchk(1,2);                        
            end
        end
        
        function setRxGainProfile(obj, profile, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_gain_profile", obj.device, profile);
                case 3
                    uhdapi("set_rx_gain_profile", obj.device, profile, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxGainProfile = getRxGainProfile(obj, chan)
            switch nargin
                case 1
                    rxGainProfile = uhdapi("get_rx_gain_profile", obj.device);
                case 2
                    rxGainProfile = uhdapi("get_rx_gain_profile", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end 
        
        function setNormalizedRxGain(obj, gain, chan)
            switch nargin
                case 2
                    uhdapi("set_normalized_rx_gain", obj.device, gain);
                case 3
                    uhdapi("set_normalized_rx_gain", obj.device, gain, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function setRxAgc(obj, enable, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_agc", obj.device, enable);
                case 3
                    uhdapi("set_rx_agc", obj.device, enable, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxGain = getRxGain(obj, name, chan) 
            switch nargin
                case 2
                    rxGain = uhdapi("get_rx_gain", obj.device, name);
                case 3
                    rxGain = uhdapi("get_rx_gain", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function normRxGain = getNormalizedRxGain(obj, chan)
            switch nargin
                case 1
                    normRxGain = uhdapi("get_normalized_rx_gain", obj.device);
                case 2
                    normRxGain = uhdapi("get_normalized_rx_gain", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function rxGainRange = getRxGainRange(obj, name, chan) 
            switch nargin
                case 2
                    rxGainRange = uhdapi("get_rx_gain_range", obj.device, name);
                case 3
                    rxGainRange = uhdapi("get_rx_gain_range", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxGainNames = getRxGainNames(obj, chan) 
            switch nargin
                case 1
                    rxGainNames = uhdapi("get_rx_gain_names", obj.device);
                case 2
                    rxGainNames = uhdapi("get_rx_gain_names", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setRxAntenna(obj, ant, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_antenna",obj.device, ant);
                case 3
                    uhdapi("set_rx_antenna",obj.device, ant, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function rxAntenna = getRxAntenna(obj, chan)
            switch nargin
                case 1
                    rxAntenna = uhdapi("get_rx_antenna",obj.device);
                case 2
                    rxAntenna = uhdapi("get_rx_antenna",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function rxAntennas = getRxAntennas(obj, chan)
            switch nargin
                case 1
                    rxAntennas = uhdapi("get_rx_antennas", obj.device);
                case 2
                    rxAntennas = uhdapi("get_rx_antennas", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function setRxBandwidth(obj, bandwidth, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_bandwidth", obj.device, bandwidth);
                case 3
                    uhdapi("get_rx_bandwidth", obj.device, bandwidth, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxBandwidth = getRxBandwidth(obj, chan)
            switch nargin
                case 1
                    rxBandwidth = uhdapi("get_rx_bandwidth", obj.device);
                case 2
                    rxBandwidth = uhdapi("get_rx_bandwidth", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function rxBandwidthRange = getRxBandwidthRange(obj, chan)
            switch nargin
                case 1
                    rxBandwidthRange = uhdapi("get_rx_bandwidth_range", obj.device);
                case 2
                    rxBandwidthRange = uhdapi("get_rx_bandwidth_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function dboardIface = getRxBoardIface(obj, chan)
            switch nargin
                case 1
                    uhdapi("create_rx_dboard_iface", obj.device);
                    dboardIface = uhd.usrp.rx_dboard_iface(obj.device);
                case 2
                    uhdapi("create_rx_dboard_iface", obj.device, chan);
                    dboardIface = uhd.usrp.rx_dboard_iface(obj.device);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function rxSensor = getRxSensor(obj, name, chan)
            switch nargin
                case 2
                    rxSensor = uhdapi("get_rx_sensor", obj.device, name);
                case 3
                    rxSensor = uhdapi("get_rx_sensor", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function rxSensorNames = getRxSensorNames(obj, chan)
            switch nargin
                case 1
                    rxSensorNames = uhdapi("get_rx_sensor_names", obj.device);
                case 2
                    rxSensorNames = uhdapi("get_rx_sensor_names", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setRxDcOffset(obj, enb, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_dc_offset", obj.device, enb);
                case 3
                    uhdapi("set_rx_dc_offset", obj.device, enb, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function setRxDcOffsetComplex(obj, offset, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_dc_offset_complex", obj.device, offset);
                case 3
                    uhdapi("set_rx_dc_offset_complex", obj.device, offset, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function rxDcOffsetRange = getRxDcOffsetRange(obj, chan)
            switch nargin
                case 1
                    rxDcOffsetRange = uhdapi("get_rx_dc_offset_range", obj.device);
                case 2
                    rxDcOffsetRange = uhdapi("get_rx_dc_offset_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function setRxIqBalance(obj, enb, chan)
            uhdapi("set_rx_iq_balance",obj.device, enb, chan);
        end
        
        function setRxIqBalanceComplex(obj, correction, chan)
            switch nargin
                case 2
                    uhdapi("set_rx_iq_balance_complex",obj.device, correction);
                case 3
                    uhdapi("set_rx_iq_balance_complex",obj.device, correction, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        %% Tx methods
        
        function setTxSubdevSpec(obj, subdevSpec, mboard)
            switch nargin
                case 2
                    uhdapi("set_tx_subdev_spec", obj.device, subdevSpec);
                case 3
                    uhdapi("set_tx_subdev_spec",obj.device, subdevSpec, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function subdevSpec = getTxSubdevSpec(obj, mboard)
            switch nargin 
                case 1
                    subdevSpec = uhdapi("get_tx_subdev_spec", obj.device);
                case 2
                    subdevSpec = uhdapi("get_tx_subdev_spec", obj.device, mboard);
                otherwise
                    narginchk(1,2);
            end 
        end
        
        function txNumChannels = getTxNumChannels(obj)
            txNumChannels = uhdapi("get_tx_channels", obj.device);
        end
        
        function txSubdevName = getTxSubdevName(obj, chan)
            switch nargin
                case 1
                    txSubdevName = uhdapi("get_tx_subdev_name", obj.device);
                case 2
                    txSubdevName = uhdapi("get_tx_subdev_name", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end     
        
        function setTxRate(obj, txRate, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_rate",obj.device,txRate);
                case 3
                    uhdapi("set_tx_rate",obj.device,txRate, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function txRate = getTxRate(obj, chan)
            switch nargin
                case 1
                    txRate = uhdapi("get_tx_rate", obj.device);
                case 2
                    txRate = uhdapi("get_tx_rate", obj.device, chan);
                otherwise
                    narginchk(1,2);  
            end  
        end
        
        function txRates = getTxRates(obj, chan)
            switch nargin
                case 1
                    txRates = uhdapi("get_tx_rates", obj.device);
                case 2
                    txRates = uhdapi("get_tx_rates", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function tuneResult = setTxFreq(obj, tuneRequest, chan)
            switch nargin
                case 2
                    tuneResult = uhdapi("set_tx_freq",obj.device, tuneRequest);
                case 3
                    tuneResult = uhdapi("set_tx_freq",obj.device, tuneRequest, chan);
                otherwise
                    narginchk(2,3)
            end
        end
        
        function txFreq = getTxFreq(obj, chan)
            switch nargin
                case 1
                    txFreq = uhdapi("get_tx_freq", obj.device);
                case 2
                    txFreq = uhdapi("get_tx_freq", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function txFreqRange = getFreqRange(obj, chan)
            switch nargin
                case 1
                    txFreqRange = uhdapi("get_freq_range", obj.device);
                case 2
                    txFreqRange = uhdapi("get_freq_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function feTxFreqRange = getFeTxFreqRange(obj, chan)
            switch nargin
                case 1
                    feTxFreqRange = uhdapi("get_fe_tx_freq_range", obj.device);
                case 2
                    feTxFreqRange = uhdapi("get_fe_tx_freq_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setTxGain(obj, txGain, name, chan)
            switch nargin
                case 3
                    uhdapi("set_tx_gain",obj.device, txGain, name);
                case 4
                    uhdapi("set_tx_gain",obj.device, txGain, name, chan);
                otherwise
                    narginchk(3,4);
            end
        end
        
        function txGainProfileNames = getTxGainProfileNames(obj, chan)
            switch nargin
                case 1
                    txGainProfileNames = uhdapi("get_tx_gain_profile_names", obj.device);
                case 2
                    txGainProfileNames = uhdapi("get_tx_gain_profile_names", obj.device, chan);
                otherwise
                    narginchk(1,2);                        
            end
        end
        
        function setTxGainProfile(obj, profile, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_gain_profile", obj.device, profile);
                case 3
                    uhdapi("set_tx_gain_profile", obj.device, profile, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txGainProfile = getTxGainProfile(obj, chan)
            switch nargin
                case 1
                    txGainProfile = uhdapi("get_tx_gain_profile", obj.device);
                case 2
                    txGainProfile = uhdapi("get_tx_gain_profile", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end 
        
        function setNormalizedTxGain(obj, gain, chan)
            switch nargin
                case 2
                    uhdapi("set_normalized_tx_gain", obj.device, gain);
                case 3
                    uhdapi("set_normalized_tx_gain", obj.device, gain, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txGain = getTxGain(obj, name, chan) 
            switch nargin
                case 2
                    txGain = uhdapi("get_tx_gain", obj.device, name);
                case 3
                    txGain = uhdapi("get_tx_gain", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function normTxGain = getNormalizedTxGain(obj, chan)
            switch nargin
                case 1
                    normTxGain = uhdapi("get_normalized_tx_gain", obj.device);
                case 2
                    normTxGain = uhdapi("get_normalized_tx_gain", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function txGainRange = getTxGainRange(obj, name, chan) 
            switch nargin
                case 2
                    txGainRange = uhdapi("get_tx_gain_range", obj.device, name);
                case 3
                    txGainRange = uhdapi("get_tx_gain_range", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txGainNames = getTxGainNames(obj, chan) 
            switch nargin
                case 1
                    txGainNames = uhdapi("get_tx_gain_names", obj.device);
                case 2
                    txGainNames = uhdapi("get_tx_gain_names", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setTxAntenna(obj, ant, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_antenna",obj.device, ant);
                case 3
                    uhdapi("set_tx_antenna",obj.device, ant, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function txAntenna = getTxAntenna(obj, chan)
            switch nargin
                case 1
                    txAntenna = uhdapi("get_tx_antenna",obj.device);
                case 2
                    txAntenna = uhdapi("get_tx_antenna",obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function txAntennas = getTxAntennas(obj, chan)
            switch nargin
                case 1
                    txAntennas = uhdapi("get_tx_antennas", obj.device);
                case 2
                    txAntennas = uhdapi("get_tx_antennas", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function setTxBandwidth(obj, bandwidth, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_bandwidth", obj.device, bandwidth);
                case 3
                    uhdapi("get_tx_bandwidth", obj.device, bandwidth, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txBandwidth = getTxBandwidth(obj, chan)
            switch nargin
                case 1
                    txBandwidth = uhdapi("get_tx_bandwidth", obj.device);
                case 2
                    txBandwidth = uhdapi("get_tx_bandwidth", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function txBandwidthRange = getTxBandwidthRange(obj, chan)
            switch nargin
                case 1
                    txBandwidthRange = uhdapi("get_tx_bandwidth_range", obj.device);
                case 2
                    txBandwidthRange = uhdapi("get_tx_bandwidth_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function dboardIface = getTxBoardIface(obj, chan)
            switch nargin
                case 1
                    uhdapi("create_tx_board_iface", obj.device);
                    dboardIface = uhd.usrp.tx_dboard_iface(obj.device);  
                case 2
                    uhdapi("create_tx_board_iface", obj.device, chan);
                     dboardIface = uhd.usrp.tx_dboard_iface(obj.device);   
                otherwise
                    narginchk(1,2);
            end
        end
        
        function txSensor = getTxSensor(obj, name, chan)
            switch nargin
                case 2
                    txSensor = uhdapi("get_tx_sensor", obj.device, name);
                case 3
                    txSensor = uhdapi("get_tx_sensor", obj.device, name, chan);
                otherwise
                    narginchk(2,3);
            end
        end
        
        function txSensorNames = getTxSensorNames(obj, chan)
            switch nargin
                case 1
                    txSensorNames = uhdapi("get_tx_sensor_names", obj.device);
                case 2
                    txSensorNames = uhdapi("get_tx_sensor_names", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end
        end
        
        function setTxDcOffset(obj, offset, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_dc_offset", obj.device, offset);
                case 3
                    uhdapi("set_tx_dc_offset", obj.device, offset, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
        function txDcOffsetRange = getTxDcOffsetRange(obj, chan)
            switch nargin
                case 1
                    txDcOffsetRange = uhdapi("get_tx_dc_offset_range", obj.device);
                case 2
                    txDcOffsetRange = uhdapi("get_tx_dc_offset_range", obj.device, chan);
                otherwise
                    narginchk(1,2);
            end   
        end
        
        function setTxIqBalance(obj, correction, chan)
            switch nargin
                case 2
                    uhdapi("set_tx_iq_balance", obj.device, correction);
                case 3
                    uhdapi("set_tx_iq_balance", obj.device, correction, chan);
                otherwise
                    narginchk(2,3);
            end   
        end
        
      %% GPIO methods
      
      function gpioBanks = getGpioBanks(obj, mboard)
          gpioBanks = uhdapi("get_gpio_banks", obj.device, mboard);
      end
      
      function setGpioAttr(obj, bank, attr, value, mask, mboard)
          switch nargin
              case 4
                  uhdapi("set_gpio_attr", obj.device, bank, attr, value);
              case 5
                  uhdapi("set_gpio_attr", obj.device, bank, attr, value, mask);
              case 6
                  uhdapi("set_gpio_attr", obj.device, bank, attr, value, mask, mboard);
              otherwise
                  narginchk(4,6);
          end
      end
      
      function gpioAttr = getGpioAttr(obj, bank, attr, mboard)
          switch nargin
              case 3
                  gpioAttr = uhdapi("get_gpio_attr", obj.device, bank, attr);
              case 4
                  gpioAttr = uhdapi("get_gpio_attr", obj.device, bank, attr, mboard);
              otherwise
                  narginchk(3,4);
          end
      end
      
      function gpioStringAttr = getGpioStringAttr(obj, bank, attr, mboard)
          switch nargin
              case 3
                  gpioStringAttr = uhdapi("get_gpio_string_attr", obj.device, bank, attr);
              case 4
                  gpioStringAttr = uhdapi("get_gpio_string_attr", obj.device, bank, attr, mboard);                  
              otherwise
                narginchk(3,4);
          end
      end
      
      %% Register IO methods
      
      function registers = enumerateRegisters(obj, mboard)
          switch nargin
              case 1
                  registers = uhdapi("enumerate_registers", obj.device);
              case 2
                  registers = uhdapi("enumerate_registers", obj.device, mboard);
              otherwise
                narginchk(1,2);
          end
      end
      
      function registerInfo = getRegisterInfo(obj, path, mboard)
          switch nargin
              case 2
                  registerInfo = uhdapi("get_register_info", obj.device, path);
              case 3
                  registerInfo = uhdapi("get_register_info", obj.device, path, mboard);
              otherwise
                  narginchk(2,3);
          end
      end
      
      function writeRegister(obj, path, field, value, mboard)
          switch nargin
              case 4
                  uhdapi("write_register", obj.device, path, field, value); 
              case 5
                  uhdapi("write_register", obj.device, path, field, value, mboard); 
              otherwise
                  narginchk(4,5);
          end
      end
      
      function register = readRegister(obj, path, field, mboard)
          switch nargin
              case 3
                  register = uhdapi("read_register", obj.device, path, field); 
              case 4
                  register = uhdapi("read_register", obj.device, path, field, mboard); 
              otherwise
                  narginchk(3,4);
          end
      end
      
      
      %% Filter API methods
      
      function filterNames = getFilterNames(obj, searchMask)
          switch nargin
              case 1
                  filterNames = uhdapi("get_filter_names", obj.device);
              case 2
                  filterNames = uhdapi("get_filter_names", obj.device, searchMask);
              otherwise
                  narginchk(1,2);
          end
      end
        
      function filter = getFilter(obj, path)
         filter = uhdapi("get_filter", obj.device, path); 
      end
        
    end
end

