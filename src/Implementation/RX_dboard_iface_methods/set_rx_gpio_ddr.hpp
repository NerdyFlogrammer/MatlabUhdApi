#ifndef _SET_RX_GPIO_DDR_HPP_
#define _SET_RX_GPIO_DDR_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_gpio_ddr(unit_t unit, uint32_t value, uint32_t mask = 0xffff)
class SetRxGpioDdr : public MexObjectRunner<INT32_REQUIRED, UINT32_REQUIRED, UINT32> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setGpioDdr(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif