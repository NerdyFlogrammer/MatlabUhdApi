#ifndef _SET_COMMAND_TIME_HPP_
#define _SET_COMMAND_TIME_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual void 	set_command_time (const uhd::time_spec_t &time_spec, size_t mboard=ALL_MBOARDS)
class SetCommandTime : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		double secs{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_command_time(secs);
        }
        else {
			const size_t mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_command_time(secs, mboard);
        }        
    }
};

#endif