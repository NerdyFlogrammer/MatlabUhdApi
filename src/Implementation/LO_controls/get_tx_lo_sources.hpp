#ifndef _GET_TX_LO_SOURCES_HPP_
#define _GET_TX_LO_SOURCES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_tx_lo_sources (const std::string &name=ALL_LOS, const size_t chan=0)
class GetLoTxSources : public MexObjectRunner<STRING, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> txLoSources {};
        if(inputs.size() == 0) {
            txLoSources = uhd->getUhd()->get_tx_lo_sources();
        }
        else if(inputs.size() == 1) {
			const std::string name = inputs[0][0][0];
            txLoSources = uhd->getUhd()->get_tx_lo_sources(name);
        }
        else  {
			const std::string name = inputs[0][0][0];
			const size_t chan{ inputs[1][0][0] };
            txLoSources = uhd->getUhd()->get_tx_lo_sources(name, chan);
        }
        outputs[0] = factory.createArray({1, txLoSources.size()}, txLoSources.begin(), txLoSources.end());        
    }
};

#endif