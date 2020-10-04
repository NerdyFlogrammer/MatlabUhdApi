#ifndef _SET_RX_IQ_BALANCE_HPP_
#define _SET_RX_IQ_BALANCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_iq_balance (const bool enb, size_t chan)
class SetRxIqBalance : public MexObjectRunner<LOGICAL_REQUIRED, INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool enb{ inputs[0][0][0] };
		const size_t chan{ inputs[1][0][0] };
		uhd->getUhd()->set_rx_iq_balance(enb, chan);
    }
};

#endif