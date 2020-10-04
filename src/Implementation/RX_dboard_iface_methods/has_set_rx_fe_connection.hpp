#ifndef _HAS_SET_RX_FE_CONNECTION_HPP_
#define _HAS_SET_RX_FE_CONNECTION_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual bool has_set_fe_connection(const unit_t)
class HasSetRxFeConnection : public MexObjectRunner<INT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::hasSetFeConnection(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif