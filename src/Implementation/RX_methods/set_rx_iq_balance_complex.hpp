#ifndef _SET_RX_IQ_BALANCE_COMPLEX_HPP_
#define _SET_RX_IQ_BALANCE_COMPLEX_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_iq_balance (const std::complex< double > &correction, size_t chan=ALL_CHANS)
class SetRxIqBalanceComplex : public MexObjectRunner<COMPLEX_DOUBLE_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::complex<double> correction{ inputs[0][0][0] };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_rx_iq_balance(correction);
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->set_rx_iq_balance(correction, chan);
		}
	}
};

#endif