#ifndef _SET_TIME_NOW_HPP_
#define _SET_TIME_NOW_HPP_

#include "../../API/mex_object_runner.hpp"

//set_time_now (const time_spec_t &time_spec, size_t mboard=ALL_MBOARDS)
class SetTimeNow : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double secs{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_time_now(secs);
        }
        else {
			const size_t mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_time_now(secs, mboard);
        }   
    }
};

#endif