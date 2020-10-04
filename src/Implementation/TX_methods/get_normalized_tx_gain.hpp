#ifndef _GET_NORMALIZED_TX_GAIN_HPP_
#define _GET_NORMALIZED_TX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_normalized_tx_gain (size_t chan=0)
class GetNormalizedTxGain : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double normalizedGain{ };
		if (inputs.size() == 0) {
			normalizedGain = uhd->getUhd()->get_normalized_tx_gain();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			normalizedGain = uhd->getUhd()->get_normalized_tx_gain();
		}
		outputs[0] = factory.createScalar(normalizedGain);
	}
};

#endif