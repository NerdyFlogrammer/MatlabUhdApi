classdef tx_streamer
    
    properties(Access = private)
        device
    end
    
    methods
        function obj = tx_streamer(device)
            obj.device = device;
        end
        
        function numChan = getNumChannels(obj)
            numChan = uhdapi("get_tx_stream_num_channels", obj.device);
        end
        
        function maxNumSamps = getMaxNumSamps(obj)
            maxNumSamps = uhdapi("get_tx_max_num_samps", obj.device);
        end
               
        function [numSamps, md] = send(obj, buff, nSampsPerBuff, md, timeout)
            switch nargin
                case 4
                    [numSamps, md] = uhdapi("send", obj.device, buff, nSampsPerBuff, md); 
                case 5
                    [numSamps, md] = uhdapi("send", obj.device, buff, nSampsPerBuff, md, timeout);
                otherwise
                    narginchk(4,5);
            end
        end
        
        function [recv, md] = recvAsyncMsg(obj, md, timeout)
            switch nargin
                case 2
                    [recv, md] = uhdapi("recv_async_msg", obj.device, md); 
                case 3
                    [recv, md] = uhdapi("recv_async_msg", obj.device, md, timeout);
                otherwise
                    narginchk(2,3);
            end
        end
        
    end
end

