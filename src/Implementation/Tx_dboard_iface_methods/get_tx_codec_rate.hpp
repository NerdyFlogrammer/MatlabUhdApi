#ifndef _GET_TX_CODEC_RATE_HPP_
#define _GET_TX_CODEC_RATE_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual double get_codec_rate(unit_t unit)
class GetTxCodecRate : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getCodecRate(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif