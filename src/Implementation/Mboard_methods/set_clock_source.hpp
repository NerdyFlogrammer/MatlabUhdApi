#ifndef _SET_CLOCK_SOURCE_HPP_
#define _SET_CLOCK_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_clock_source (const std::string &source, const size_t mboard=ALL_MBOARDS)
class SetClockSource : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string source = inputs[0][0][0];
        if(inputs.size() == 1) {
            uhd->getUhd()->set_clock_source(source);
        }
        else {
			const int mboard{ inputs[1][0][0] };
            uhd->getUhd()->set_clock_source(source, mboard);
        }
    }
};

#endif