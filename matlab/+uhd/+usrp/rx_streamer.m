classdef rx_streamer
    
    properties (Access = private)
        device
    end
    
    methods
        function obj = rx_streamer(device)
            obj.device = device;
        end
        
        function numChannels = getNumChannels(obj)
            numChannels = uhdapi("get_rx_stream_num_channels", obj.device);
        end
        
        function maxNumSamps = getMaxNumSamps(obj)
            maxNumSamps = uhdapi("get_rx_max_samps", obj.device);
        end
        
        function [md, numSamps, buff] = recv(obj, sampsPerBuff, metaData, timeout, onePacket)
            switch nargin
                case 3
                    [md, numSamps, buff] = uhdapi("recv", obj.device, sampsPerBuff, metaData);
                case 4
                   [md, numSamps, buff] = uhdapi("recv", obj.device, sampsPerBuff, metaData, timeout);
                case 5
                    [md, numSamps, buff] = uhdapi("recv", obj.device, sampsPerBuff, metaData, timeout, onePacket);
                otherwise
                    narginchk(3,5);
            end
        end
        
        function issueStreamCmd(obj, streamCmd, mboard)
            switch nargin
                case 2
                    uhdapi("rx_issue_stream_cmd", obj.device, streamCmd);
                case 3
                    uhdapi("rx_issue_stream_cmd", obj.device, streamCmd, mboard);
                otherwise
                    narginchk(2,3);
            end
        end
    end
end

