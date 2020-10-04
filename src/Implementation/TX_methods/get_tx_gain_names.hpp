#ifndef _GET_TX_GAIN_NAMES_HPP_
#define _GET_TX_GAIN_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual std::vector< std::string > 	get_tx_gain_names (size_t chan=0)
class GetTxGainNames : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::string> gainNames{ };
		if (inputs.size() == 0) {
			gainNames = uhd->getUhd()->get_tx_gain_names();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			gainNames = uhd->getUhd()->get_tx_gain_names(chan);
		}
		outputs[0] = factory.createArray({ 1, gainNames.size() }, gainNames.begin(), gainNames.end());
	}
};

#endif