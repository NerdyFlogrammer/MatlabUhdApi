#ifndef _GET_TIME_SOURCES_HPP_
#define _GET_TIME_SOURCES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_time_sources (const size_t mboard)
class GetTimeSources : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
		const std::vector<std::string> timeSources{ uhd->getUhd()->get_time_sources(mboard) };
        outputs[0] = factory.createArray({1, timeSources.size()}, timeSources.begin(), timeSources.end());
    }
};

#endif