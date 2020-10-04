#ifndef _SET_RX_BANDWIDTH_HPP_
#define _SET_RX_BANDWIDTH_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_bandwidth (double bandwidth, size_t chan=0)
class SetRxBandwidth : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double bandwidth { inputs[0][0][0] };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_rx_bandwidth(bandwidth);
		}
		else {
			const size_t chan { inputs[1][0][0] };
			uhd->getUhd()->set_rx_bandwidth(bandwidth, chan);
		}
    }
};

#endif