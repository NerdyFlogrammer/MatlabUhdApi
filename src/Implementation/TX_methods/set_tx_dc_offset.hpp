#ifndef _SET_TX_DC_OFFSET_HPP_
#define _SET_TX_DC_OFFSET_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_dc_offset (const std::complex< double > &offset, size_t chan=ALL_CHANS)
class SetTxDcOffset : public MexObjectRunner<COMPLEX_DOUBLE_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::complex<double> offset{ inputs[0][0][0] };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_tx_dc_offset(offset);
		}
		else
		{
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->set_tx_dc_offset(offset, chan);
		}
	}
};

#endif