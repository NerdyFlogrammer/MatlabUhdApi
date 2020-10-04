#ifndef _GET_TX_LO_NAMES_HPP_
#define _GET_TX_LO_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

// virtual std::vector< std::string > 	get_tx_lo_names (size_t chan=0)
class GetTxLoNames : public MexObjectRunner<INT64> {

protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> rxLoNames {};
        if(inputs.size() == 0) {
            rxLoNames = uhd->getUhd()->get_tx_lo_names();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            rxLoNames = uhd->getUhd()->get_tx_lo_names(chan);
        }
        outputs[0] = factory.createArray({1, rxLoNames.size()}, rxLoNames.begin(), rxLoNames.end());
    }
};

#endif