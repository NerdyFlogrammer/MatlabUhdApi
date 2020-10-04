#ifndef _READ_RX_AUX_ADC_HPP_
#define _READ_RX_AUX_ADC_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual double read_aux_adc(unit_t unit, aux_adc_t which_adc)
class ReadRxAuxAdc : public MexObjectRunner<INT32_REQUIRED, INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::readAuxAdc(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif