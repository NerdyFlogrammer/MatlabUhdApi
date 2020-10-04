#ifndef _SET_RX_ATR_REG_HPP_
#define _SET_RX_ATR_REG_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_atr_reg(unit_t unit, atr_reg_t reg, uint32_t value, uint32_t mask = 0xffff)
class SetRxAtrReg : public MexObjectRunner<INT32_REQUIRED, INT32_REQUIRED, UINT32_REQUIRED, UINT32> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setAtrReg(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif