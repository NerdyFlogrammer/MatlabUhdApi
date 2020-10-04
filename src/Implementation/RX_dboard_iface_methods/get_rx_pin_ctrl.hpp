#ifndef _GET_RX_PIN_CTRL_HPP_
#define _GET_RX_PIN_CTRL_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uint32_t get_pin_ctrl(unit_t unit)
class GetRxPinCtrl : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getPinCtrl(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif