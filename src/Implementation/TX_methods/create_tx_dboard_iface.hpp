#ifndef _CREATE_TX_DBOARD_IFACE_HPP_
#define _CREATE_TX_DBOARD_IFACE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual dboard_iface::sptr get_tx_dboard_iface(size_t chan = 0)
class CreateTxDboardIface : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			auto dbIface{ uhd->getUhd()->get_tx_dboard_iface() };
			uhd->setTxDboardIface(dbIface);
		}
		else {
			const size_t chan = inputs[0][0][0];
			auto dbIface{ uhd->getUhd()->get_tx_dboard_iface(chan) };
			uhd->setTxDboardIface(dbIface);
		}
	}
};

#endif