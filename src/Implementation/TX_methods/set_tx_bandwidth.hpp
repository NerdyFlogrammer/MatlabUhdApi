#ifndef _SET_TX_BANDWIDTH_HPP_
#define _SET_TX_BANDWIDTH_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_bandwidth (double bandwidth, size_t chan=0)
class SetTxBandwidth : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double bandwidth{ inputs[0][0][0] };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_tx_bandwidth(bandwidth);
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->set_tx_bandwidth(bandwidth, chan);
		}
	}
};

#endif