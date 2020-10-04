classdef wb_iface
    %WB_IFACE Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        device
    end
    
    methods
        function obj = wb_iface(device)
            %WB_IFACE Construct an instance of this class
            %   Detailed explanation goes here
            obj.device = device;
        end
        
        function poke64(obj, addr, data)
            uhdapi("poke64", obj.device, addr, data);
        end
        
        function data = peek64(obj, addr)
            data = uhdapi("poke64", obj.device, addr);
        end
        
        function poke32(obj, addr, data)
            uhdapi("poke64", obj.device, addr, data);
        end
        
        function data = peek32(obj, addr)
            data = uhdapi("poke32", obj.device, addr);
        end
        
        function poke16(obj, addr, data)
            uhdapi("poke64", obj.device, addr, data);
        end
        
        function data = peek16(obj, addr)
            data = uhdapi("poke16", obj.device, addr);
        end
        
    end
end

