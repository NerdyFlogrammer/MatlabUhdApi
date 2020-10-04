#ifndef _GET_TX_SPECIAL_PROPS_HPP_
#define _GET_TX_SPECIAL_PROPS_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual special_props_t get_special_props(void) = 0;
class GetTxSpecialProps : public MexObjectRunner<> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getSpecialProps(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif
