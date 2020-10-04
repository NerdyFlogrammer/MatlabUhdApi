#ifndef _SET_TX_ANTENNA_HPP_
#define _SET_TX_ANTENNA_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_antenna (const std::string &ant, size_t chan=0)
class SetTxAntenna : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string ant = inputs[0][0][0];
		if (inputs.size() == 1) {
			uhd->getUhd()->set_tx_antenna(ant);
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->set_tx_antenna(ant, chan);
		}
	}
};

#endif