#ifndef _WRITE_RX_AUX_DAC_HPP_
#define _WRITE_RX_AUX_DAC_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void write_aux_dac(unit_t unit, aux_dac_t which_dac, double value)
class WriteRxAuxDac : public MexObjectRunner<INT32_REQUIRED, INT32_REQUIRED, DOUBLE_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::writeAuxDac(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif