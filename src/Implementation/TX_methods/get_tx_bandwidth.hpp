#ifndef _GET_TX_BANDWIDTH_HPP_
#define _GET_TX_BANDWIDTH_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_tx_bandwidth (size_t chan=0)
class GetTxBandwidth : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double bandwidth{ };
		if (inputs.size() == 0) {
			bandwidth = uhd->getUhd()->get_tx_bandwidth();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			bandwidth = uhd->getUhd()->get_tx_bandwidth(chan);
		}
		outputs[0] = factory.createScalar(bandwidth);
	}
};

#endif