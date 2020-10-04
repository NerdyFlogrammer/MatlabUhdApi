#ifndef _GET_RX_LO_SOURCE_HPP_
#define _GET_RX_LO_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual const std::string 	get_rx_lo_source (const std::string &name=ALL_LOS, size_t chan=0)
class GetRxLoSource : public MexObjectRunner<STRING, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::string rxLoSource {};
        if(inputs.size() == 0) {
            rxLoSource = uhd->getUhd()->get_rx_lo_source();
        }
        else if(inputs.size() == 1) {
            const std::string name = inputs[0][0][0];
            rxLoSource = uhd->getUhd()->get_rx_lo_source(name);
        }
        else {
            const std::string name = inputs[0][0][0];
			const size_t chan{ inputs[1][0][0] };
            rxLoSource = uhd->getUhd()->get_rx_lo_source(name, chan);
        }
        outputs[0] = factory.createCharArray(rxLoSource);
    }
};

#endif