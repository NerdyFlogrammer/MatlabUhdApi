#ifndef _GET_RX_GAIN_NAMES_HPP_
#define _GET_RX_GAIN_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_rx_gain_names (size_t chan=0)
class GetRxGainNames : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> gainNames { };
        if(inputs.size() == 0) {
            gainNames = uhd->getUhd()->get_rx_gain_names();
        }
        else {
            const size_t chan { inputs[0][0][0] };
            gainNames = uhd->getUhd()->get_rx_gain_names(chan);
        }
        outputs[0] = factory.createArray({1, gainNames.size()}, gainNames.begin(), gainNames.end());
    }
};

#endif