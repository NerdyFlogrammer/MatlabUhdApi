#ifndef _GET_RX_LO_EXPORT_ENABLED_HPP_
#define _GET_RX_LO_EXPORT_ENABLED_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual bool 	get_rx_lo_export_enabled (const std::string &name=ALL_LOS, size_t chan=0)=0
class GetRxLoExportEnabled : public MexObjectRunner<STRING, INT64> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        bool enabled {};
        if(inputs.size() == 0) {
            enabled = uhd->getUhd()->get_rx_lo_export_enabled();
        }
		else if (inputs.size() == 1) {
			const std::string name = inputs[0][0][0];
            enabled = uhd->getUhd()->get_rx_lo_export_enabled(name);
        }
        else {
			const std::string name = inputs[0][0][0];
			const size_t chan{ inputs[1][0][0] };
            enabled = uhd->getUhd()->get_rx_lo_export_enabled(name, chan);
        } 
        outputs[0] = factory.createScalar(enabled);
    }
};

#endif