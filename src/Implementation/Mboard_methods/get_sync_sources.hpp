#ifndef _GET_SYNC_SOURCES_HPP_
#define _GET_SYNC_SOURCES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< device_addr_t > 	get_sync_sources (const size_t mboard)
class GetSyncSources : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
		const auto syncSources{ uhd->getUhd()->get_sync_sources(mboard) };
        std::vector<std::string> syncSourcesString;
        syncSourcesString.resize(syncSources.size());
        std::transform(syncSources.begin(), syncSources.end(), syncSourcesString.begin(),
                   [&](auto& addr) -> std::string { return addr.to_string(); });
        outputs[0] = factory.createArray({1, syncSourcesString.size()}, syncSourcesString.begin(), syncSourcesString.end());
    }
};

#endif