#ifndef _GET_TX_ATR_REG_HPP_
#define _GET_TX_ATR_REG_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uint32_t get_atr_reg(unit_t unit, atr_reg_t reg)
class GetTxAtrReg : public MexObjectRunner<INT32_REQUIRED, INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getAtrReg(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif