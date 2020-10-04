#ifndef _SET_TIME_SOURCE_HPP_
#define _SET_TIME_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_time_source (const std::string &source, const size_t mboard=ALL_MBOARDS)
class SetTimeSource : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string source = inputs[0][0][0];
        if(inputs.size() == 1) {
            uhd->getUhd()->set_time_source(source);
        }
        else {
			const size_t mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_time_source(source, mboard);
        }        
    }
};

#endif