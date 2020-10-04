#ifndef _GET_RX_BANDWIDTH_HPP_
#define _GET_RX_BANDWIDTH_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual double 	get_rx_bandwidth (size_t chan=0)=0
class GetRxBandwidth : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double bandwidth{ };
		if (inputs.size() == 0) {
			bandwidth = uhd->getUhd()->get_rx_bandwidth();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			bandwidth = uhd->getUhd()->get_rx_bandwidth(chan);
		}
		outputs[0] = factory.createScalar(bandwidth);
    }
};

#endif