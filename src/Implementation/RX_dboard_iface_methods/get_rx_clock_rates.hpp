#ifndef _GET_RX_CLOCK_RATES_HPP_
#define _GET_RX_CLOCK_RATES_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual std::vector<double> get_clock_rates(unit_t unit)
class GetRxClockRates : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getClockRates(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif