#ifndef _SET_RX_CLOCK_ENABLED_HPP_
#define _SET_RX_CLOCK_ENABLED_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_clock_enabled(unit_t unit, bool enb)
class SetRxClockEnabled : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setClockEnabled(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif