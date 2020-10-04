#ifndef _SET_SYNC_SOURCE_HPP_
#define _SET_SYNC_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_sync_source (const std::string &clock_source, const std::string &time_source, const size_t mboard=ALL_MBOARDS)
class SetSyncSource : public MexObjectRunner<STRING_REQUIRED, STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string clockSource{ inputs[0][0][0] };
		const std::string timeSource{ inputs[1][0][0] };
        if(inputs.size() == 2) {
            uhd->getUhd()->set_sync_source(clockSource, timeSource);
        }
        else {
			const size_t mboard{ inputs[2][0][0] };
            uhd->getUhd()->set_sync_source(clockSource, timeSource, mboard);
        }
    }
};

#endif