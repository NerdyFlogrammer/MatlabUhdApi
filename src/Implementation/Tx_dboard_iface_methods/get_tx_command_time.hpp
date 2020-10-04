#ifndef _GET_TX_COMMAND_TIME_HPP_
#define _GET_TX_COMMAND_TIME_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uhd::time_spec_t get_command_time(void)
class GetTxCommandTime : public MexObjectRunner<> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::getCommandTime(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif