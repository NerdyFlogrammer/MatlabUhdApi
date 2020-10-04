#ifndef _GET_CLOCK_SOURCES_HPP_
#define _GET_CLOCK_SOURCES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_clock_sources (const size_t mboard)=0
class GetClockSources : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
        const std::vector<std::string> clockSources = uhd->getUhd()->get_clock_sources(mboard);
        outputs[0] = factory.createArray({1, clockSources.size()}, clockSources.begin(), clockSources.end());
    }
};

#endif