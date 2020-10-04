#ifndef _SET_TIME_SOURCE_OUT_HPP_
#define _SET_TIME_SOURCE_OUT_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_time_source_out (const bool enb, const size_t mboard=ALL_MBOARDS)=0
class SetTimeSourceOut : public MexObjectRunner<LOGICAL_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool enable{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_time_source_out(enable);
        }
        else {
			const size_t mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_time_source_out(enable, mboard);
        }        
    }
};

#endif