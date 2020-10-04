#ifndef _SET_RX_FREQ_HPP_
#define _SET_RX_FREQ_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/tune_request_factory.hpp"
#include "../Structs//tune_result_factory.hpp"

using matlab::data::StructArray;

//virtual tune_result_t 	set_rx_freq (const tune_request_t &tune_request, size_t chan=0)
class SetRxFreq : public MexObjectRunner<STRUCT_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uhd::tune_request_t tune_req{ StructFactory<uhd::tune_request_t>::createCpp(inputs[0]) };
		uhd::tune_result_t tune_res{ };
		if (inputs.size() == 1) {
			tune_res = uhd->getUhd()->set_rx_freq(tune_req);
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			tune_res = uhd->getUhd()->set_rx_freq(tune_req, chan);
		}
        outputs[0] = StructFactory<uhd::tune_result_t>::createMatlab(tune_res);
    }
};

#endif