#ifndef _GET_RX_LO_SOURCES_HPP_
#define _GET_RX_LO_SOURCES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_rx_lo_sources (const std::string &name=ALL_LOS, size_t chan=0)
class GetRxLoSources : public MexObjectRunner<STRING, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> rxLoSources {};
        if(inputs.size() == 0) {
            rxLoSources = uhd->getUhd()->get_rx_lo_sources();
        }
        else if(inputs.size() == 1) {
            const std::string name = inputs[0][0][0];
            rxLoSources = uhd->getUhd()->get_rx_lo_sources(name);
        }
        else  {
            const std::string name = inputs[0][0][0];
			const size_t chan{ inputs[1][0][0] };
            rxLoSources = uhd->getUhd()->get_rx_lo_sources(name, chan);
        }
        outputs[0] = factory.createArray({1, rxLoSources.size()}, rxLoSources.begin(), rxLoSources.end());
    }
};

#endif