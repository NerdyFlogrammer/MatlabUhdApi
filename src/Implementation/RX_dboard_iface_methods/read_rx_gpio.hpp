#ifndef _READ_RX_GPIO_HPP_
#define _READ_RX_GPIO_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uint32_t read_gpio(unit_t unit)
class ReadRxGpio : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::readGpio(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif