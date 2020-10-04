#ifndef _GET_TX_LO_SOURCE_HPP_
#define _GET_TX_LO_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual const std::string 	get_tx_lo_source (const std::string &name=ALL_LOS, const size_t chan=0)
class GetTxLoSource : public MexObjectRunner<STRING, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::string txLoSource {};
        if(inputs.size() == 0) {
            txLoSource = uhd->getUhd()->get_tx_lo_source();
        }
        else if(inputs.size() == 1) {
			const std::string name = inputs[0][0][0];
            txLoSource = uhd->getUhd()->get_tx_lo_source(name);
        }
        else {
			const std::string name = inputs[0][0][0];
			const size_t chan{ inputs[1][0][0] };
            txLoSource = uhd->getUhd()->get_tx_lo_source(name, chan);
        }
        outputs[0] = factory.createCharArray(txLoSource);
    }
};

#endif