#ifndef _CLEAR_COMMAND_TIME_HPP_
#define _CLEAR_COMMAND_TIME_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	clear_command_time (size_t mboard=ALL_MBOARDS)
class ClearCommandTime : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        if(inputs.size() == 0) {
            uhd->getUhd()->clear_command_time();
        }
        else {
			const size_t mboard{ inputs[0][0][0] };
            uhd->getUhd()->clear_command_time(mboard);
        }   
    }
};

#endif