#ifndef _SET_RX_DC_OFFSET_HPP_
#define _SET_RX_DC_OFFSET_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_dc_offset (const bool enb, size_t chan=ALL_CHANS)
class SetRxDcOffset : public MexObjectRunner<LOGICAL_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool enb{ inputs[0][0][0] };
		if (inputs.size() == 1) {
			uhd->getUhd()->set_rx_dc_offset(enb);
		}
		else
		{
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->set_rx_dc_offset(enb, chan);
		}
    }
};

#endif