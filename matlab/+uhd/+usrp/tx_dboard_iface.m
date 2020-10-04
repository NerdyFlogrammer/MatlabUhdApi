classdef tx_dboard_iface
    
    properties
        device
    end
    
    methods
        function obj = tx_dboard_iface(device)
            obj.device = device;
        end
        
        function specialProps = getSpecialProps(obj)
            specialProps = uhdapi("get_tx_special_props", obj.device);
        end
        
        function writeAuxDac(obj, unit, whichDac, value)
            uhdapi("write_tx_aux_dac", obj.device, unit, whichDac, value);
        end
        
        function value = readAuxAdc(obj, unit, whichAdc)
            value = uhdapi("read_tx_aux_adc", obj.device, unit, whichAdc);
        end 
        
        function setPinCtrl(obj, unit, value, mask)
            switch nargin
                case 3
                    uhdapi("set_tx_pin_ctrl", obj.device, unit, value);
                case 4
                    uhdapi("set_tx_pin_ctrl", obj.device, unit, value, mask);
                otherwise
                    narginchk(3,4);             
            end
        end
        
        function value = getPinCtrl(obj, unit)
            value = uhdapi("get_tx_pin_ctrl", obj.device, unit);
        end
        
        function setAtrReg(obj, unit, reg, value, mask)
            switch nargin
                case 4
                    uhdapi("set_tx_atr_reg", obj.device, unit, reg, value);
                case 5
                    uhdapi("set_tx_atr_reg", obj.device, unit, reg, value, mask);
                otherwise
                    narginchk(4,5);             
            end
        end
        
        function value = getAtrReg(obj, unit, reg)
            value = uhdapi("get_tx_atr_reg", obj.device, unit, reg);
        end
        
        function setGpioDdr(obj, unit, value, mask)
            switch nargin
                case 3
                    uhdapi("set_tx_gpio_ddr", obj.device, unit, value);
                case 4
                    uhdapi("set_tx_gpio_ddr", obj.device, unit, value, mask);
                otherwise
                    narginchk(3,4);             
            end
        end
        
        function value = getGpioDdr(obj, unit)
            value = uhdapi("get_tx_gpio_ddr", obj.device, unit);
        end
        
        function setGpioOut(obj, unit, value, mask)
            switch nargin
                case 3
                    uhdapi("set_tx_gpio_out", obj.device, unit, value);
                case 4
                    uhdapi("set_tx_gpio_out", obj.device, unit, value, mask);
                otherwise
                    narginchk(3,4);             
            end
        end

        function value = getGpioOut(obj, unit)
            value = uhdapi("get_tx_gpio_out", obj.device, unit);
        end 
        
        function value = readGpio(obj, unit)
            value = uhdapi("read_tx_gpio", obj.device, unit);
        end

        function writeSpi(obj, unit, config, data, numBits)
            uhdapi("write_tx_spi", obj.device, unit, config, data, numBits);
        end

        function spiVal = readWriteSpi(obj, unit, config, data, numBits)
            spiVal = uhdapi("read_write_tx_spi", obj.device, unit, config, data, numBits);
        end
        
        function setClockRate(obj, unit, rate)
            uhdapi("set_tx_clock_rate", obj.device, unit, rate);
        end
        
        function clkRate = getClockRate(obj, unit)
            clkRate = uhdapi("get_tx_clock_rate", obj.device, unit);
        end
        
        function clkRates = getClockRates(obj, unit)
            clkRates = uhdapi("get_tx_clock_rates", obj.device, unit);
        end 
        
        function setClockEnabled(obj, unit, enb)
            uhdapi("set_tx_clock_enabled", obj.device, unit, enb);
        end
        
        function codecRate = getCodecRate(obj, unit)
            codecRate = uhdapi("get_tx_codec_rate", obj.device, unit);
        end
        
        function setFeConnection(obj, unit, feName, feConn)
            uhdapi("set_tx_fe_connection", obj.device, unit, feName, feConn);
        end
        
        function feConn = hasSetFeConnection(obj, unit)
            feConn = uhdapi("has_set_tx_fe_connection", obj.device, unit);
        end
        
        function cmdTime = getCommandTime(obj)
            cmdTime = uhdapi("get_tx_command_time", obj.device);
        end 
        
        function setCommandTime(obj, time)
            uhdapi("set_tx_command_time", obj.device, time);
        end
        
        function sleep(obj, time)
            uhdapi("tx_sleep", obj.device, time);
        end
          
    end
end
