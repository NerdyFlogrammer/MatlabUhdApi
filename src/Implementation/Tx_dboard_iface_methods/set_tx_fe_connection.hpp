#ifndef _SET_TX_FE_CONNECTION_HPP_
#define _SET_TX_FE_CONNECTION_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_fe_connection(unit_t unit, const std::string& fe_name, const uhd::usrp::fe_connection_t& fe_conn)
class SetTxFeConnection : public MexObjectRunner<INT32_REQUIRED, STRING_REQUIRED, STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setFeConnection(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif