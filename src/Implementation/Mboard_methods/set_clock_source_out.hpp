#ifndef _SET_CLOCK_SOURCE_OUT_HPP_
#define _SET_CLOCK_SOURCE_OUT_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual void 	set_clock_source_out (const bool enb, const size_t mboard=ALL_MBOARDS)
class SetClockSourceOut : public MexObjectRunner<LOGICAL_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool enable{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_clock_source_out(enable);
        }
        else {
			const size_t mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_clock_source_out(enable, mboard);
        }        
    }
};

#endif