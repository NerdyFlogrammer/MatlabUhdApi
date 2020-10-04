#ifndef _SET_TX_COMMAND_TIME_HPP_
#define _SET_TX_COMMAND_TIME_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void set_command_time(const uhd::time_spec_t& t)
class SetTxCommandTime : public MexObjectRunner<DOUBLE_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::setCommandTime(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif