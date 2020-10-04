#ifndef _GET_MASTER_CLOCK_RATE_HPP_
#define _GET_MASTER_CLOCK_RATE_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual double 	get_master_clock_rate (size_t mboard=0)
class GetMasterClockRate : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			outputs[0] = factory.createScalar(uhd->getUhd()->get_master_clock_rate());
		}
		else {
			size_t mboard{ inputs[0][0][0] };
			outputs[0] = factory.createScalar(uhd->getUhd()->get_master_clock_rate(mboard));
		}
    }
};

#endif