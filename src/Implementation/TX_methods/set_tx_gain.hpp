#ifndef _SET_TX_GAIN_HPP_
#define _SET_TX_GAIN_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void set_tx_gain(double gain, const std::string& name, size_t chan = 0)
class SetTxGain : public MexObjectRunner<DOUBLE_REQUIRED, STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double gain{ inputs[0][0][0] };
		const std::string name = inputs[1][0][0];
        if(inputs.size() == 2) {
            uhd->getUhd()->set_tx_gain(gain, name);
        }
        else {
			const size_t chan{ inputs[2][0][0] };
             uhd->getUhd()->set_tx_gain(gain, name, chan);
        }   
    }
};

#endif