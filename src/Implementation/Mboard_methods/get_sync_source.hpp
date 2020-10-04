#ifndef _GET_SYNC_SOURCE_HPP_
#define _GET_SYNC_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual device_addr_t 	get_sync_source (const size_t mboard)
class GetSyncSource : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
        const std::string syncSource = uhd->getUhd()->get_sync_source(mboard).to_string();
        outputs[0] = factory.createCharArray(syncSource);
    }
};

#endif