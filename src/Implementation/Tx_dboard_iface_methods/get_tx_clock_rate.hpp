#ifndef _GET_TX_CLOCK_RATE_HPP_
#define _GET_TX_CLOCK_RATE_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual double get_clock_rate(unit_t unit)
class GetTxClockRate : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getClockRate(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif