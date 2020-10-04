#ifndef _TX_SLEEP_HPP_
#define _TX_SLEEP_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void sleep(const boost::chrono::nanoseconds& time)
class TxSleep : public MexObjectRunner<INT64_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::sleep(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif