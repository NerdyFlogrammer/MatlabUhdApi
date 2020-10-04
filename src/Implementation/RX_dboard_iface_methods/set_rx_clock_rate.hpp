#ifndef _SET_RX_CLOCK_RATE_HPP_
#define _SET_RX_CLOCK_RATE_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_clock_rate(unit_t unit, double rate)
class SetRxClockRate : public MexObjectRunner<INT32_REQUIRED, DOUBLE_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setClockRate(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif