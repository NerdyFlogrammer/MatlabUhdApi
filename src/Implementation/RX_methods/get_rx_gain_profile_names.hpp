#ifndef _GET_RX_GAIN_PROFILE_NAMES_HPP_
#define _GET_RX_GAIN_PROFILE_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_rx_gain_profile_names (const size_t chan=0)
class GetRxGainProfileNames : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> profileNames {};
        if(inputs.size() == 0) {
            profileNames = uhd->getUhd()->get_rx_gain_profile_names();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            profileNames = uhd->getUhd()->get_rx_gain_profile_names(chan);
        }
        outputs[0] = factory.createArray({ 1, profileNames.size() }, profileNames.begin(), profileNames.end());
    }
};

#endif