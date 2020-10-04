#ifndef _SET_MASTER_CLOCK_RATE_HPP_
#define _SET_MASTER_CLOCK_RATE_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual void 	set_master_clock_rate (double rate, size_t mboard=ALL_MBOARDS)
class SetMasterClockRate : public MexObjectRunner<DOUBLE_REQUIRED, INT64> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const double clockRate{ inputs[0][0][0] };
		if (inputs.size() == 1)
		{
			uhd->getUhd()->set_master_clock_rate(clockRate);
		}
		else {
			const size_t mboard{ inputs[1][0][0] };
			uhd->getUhd()->set_master_clock_rate(clockRate, mboard);
		}
        
    }
};

#endif