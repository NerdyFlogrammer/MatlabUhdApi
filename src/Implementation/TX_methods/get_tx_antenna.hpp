#ifndef _GET_TX_ANTENNA_HPP_
#define _GET_TX_ANTENNA_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_tx_antenna (size_t chan=0)
class GetTxAntenna : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::string txAntenna{ };
		if (inputs.size() == 0) {
			txAntenna = uhd->getUhd()->get_tx_antenna();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			txAntenna = uhd->getUhd()->get_tx_antenna(chan);
		}
		outputs[0] = factory.createCharArray(txAntenna);
	}
};

#endif