#ifndef _SET_TX_LO_SOURCE_HPP_
#define _SET_TX_LO_SOURCE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_tx_lo_source (const std::string &src, const std::string &name=ALL_LOS, const size_t chan=0)
class SetTxLoSource : public MexObjectRunner<STRING_REQUIRED, STRING, INT64> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string src = inputs[0][0][0];
        if(inputs.size() == 1) {
            uhd->getUhd()->set_tx_lo_source(src);
        }
        else if(inputs.size() == 2) {
			const std::string name = inputs[1][0][0];
            uhd->getUhd()->set_tx_lo_source(src, name);    
        }
		else {
			const std::string name = inputs[1][0][0];
			const int chan{ inputs[2][0][0] };
            uhd->getUhd()->set_tx_lo_source(src, name, chan);
        }
    }
};

#endif