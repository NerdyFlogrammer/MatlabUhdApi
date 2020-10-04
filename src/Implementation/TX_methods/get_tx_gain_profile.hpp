#ifndef _GET_TX_GAIN_PROFILE_HPP_
#define _GET_TX_GAIN_PROFILE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_tx_gain_profile (const size_t chan=0)
class GetTxGainProfile : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::string txGainProfile{ };
		if (inputs.size() == 0) {
			txGainProfile = uhd->getUhd()->get_tx_gain_profile();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			txGainProfile = uhd->getUhd()->get_tx_gain_profile(chan);
		}
		outputs[0] = factory.createScalar(txGainProfile);
    }
};

#endif