#ifndef _GET_TX_FREQ_HPP_
#define _GET_TX_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_tx_freq (size_t chan=0)
class GetTxFreq : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double txFreq{ };
		if (inputs.size() == 0) {
			txFreq = uhd->getUhd()->get_tx_freq();
		}
		else
		{
			const size_t chan{ inputs[0][0][0] };
			txFreq = uhd->getUhd()->get_tx_freq();
		}
		outputs[0] = factory.createScalar(txFreq);
    }
};

#endif