#ifndef _SET_RX_PIN_CTRL_HPP_
#define _SET_RX_PIN_CTRL_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_pin_ctrl(unit_t unit, uint32_t value, uint32_t mask = 0xffff)
class SetRxPinCtrl : public MexObjectRunner<INT32_REQUIRED, UINT32_REQUIRED, UINT32> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setPinCtrl(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif