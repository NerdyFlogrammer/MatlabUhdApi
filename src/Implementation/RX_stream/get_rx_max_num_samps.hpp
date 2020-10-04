#ifndef _GET_RX_MAX_NUM_SAMPS_HPP_
#define _GET_RX_MAX_NUM_SAMPS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual size_t 	get_max_num_samps (void) const 
class GetRxMaxNumSamps : public MexObjectRunner<> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t maxNumSamps{ uhd->getRxStreamer()->get_max_num_samps() };
		outputs[0] = factory.createScalar(maxNumSamps);
	}
};

#endif