#ifndef _GET_RX_ANTENNA_HPP_
#define _GET_RX_ANTENNA_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_rx_antenna (size_t chan=0)
class GetRxAntenna : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::string rxAntenna { };
        if(inputs.size() == 0) {
            rxAntenna = uhd->getUhd()->get_rx_antenna();            
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            rxAntenna = uhd->getUhd()->get_rx_antenna(chan);                             
        }
		outputs[0] = factory.createCharArray(rxAntenna);
    }
};

#endif