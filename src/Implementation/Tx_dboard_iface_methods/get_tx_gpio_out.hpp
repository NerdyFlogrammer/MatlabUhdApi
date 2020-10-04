#ifndef _GET_TX_GPIO_OUT_HPP_
#define _GET_TX_GPIO_OUT_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uint32_t get_gpio_out(unit_t unit)
class GetTxGpioOut : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getGpioOut(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif