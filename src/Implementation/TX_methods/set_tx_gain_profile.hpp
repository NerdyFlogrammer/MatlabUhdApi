#ifndef _SET_TX_GAIN_PROFILE_HPP_
#define _SET_TX_GAIN_PROFILE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_gain_profile (const std::string &profile, const size_t chan=0)
class SetTxGainProfile : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string profile = inputs[0][0][0];
		if (inputs.size() == 1) {
			uhd->getUhd()->set_tx_gain_profile(profile);
		}
		else {
			const size_t chan { inputs[1][0][0] };
			uhd->getUhd()->set_tx_gain_profile(profile, chan);
		}
    }
};

#endif