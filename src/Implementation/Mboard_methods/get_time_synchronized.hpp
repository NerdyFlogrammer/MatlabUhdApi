#ifndef _GET_TIME_SYNCHRONIZED_HPP_
#define _GET_TIME_SYNCHRONIZED_HPP_

#include "../../API/mex_object_runner.hpp"

using namespace matlab::data;
//virtual bool 	get_time_synchronized (void)
class GetTimeSynchronized : public MexObjectRunner<> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool isSynchronized{ uhd->getUhd()->get_time_synchronized() };
        outputs[0] = factory.createScalar(uhd->getUhd()->get_time_synchronized());
    }
};

#endif