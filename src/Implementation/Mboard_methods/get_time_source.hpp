#ifndef _GET_TIME_SOURCE_HPP_
#define _GET_TIME_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::string 	get_time_source (const size_t mboard)
class GetTimeSource : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
		const std::string timeSource = uhd->getUhd()->get_time_source(mboard);
        outputs[0] = factory.createCharArray(timeSource);
    }
};

#endif