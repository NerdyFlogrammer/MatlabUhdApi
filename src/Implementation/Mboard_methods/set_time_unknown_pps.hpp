#ifndef _SET_TIME_UNKNOWN_PPS_HPP_
#define _SET_TIME_UNKNOWN_PPS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_time_unknown_pps (const time_spec_t &time_spec)
class SetTimeUnknownPPS : public MexObjectRunner<DOUBLE_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double secs{ inputs[0][0][0] };
        uhd->getUhd()->set_time_unknown_pps(secs);
    }
};

#endif