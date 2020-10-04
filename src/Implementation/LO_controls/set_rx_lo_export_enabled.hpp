#ifndef _SET_RX_LO_EXPORT_ENABLED_HPP_
#define _SET_RX_LO_EXPORT_ENABLED_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_rx_lo_export_enabled (bool enabled, const std::string &name=ALL_LOS, size_t chan=0)
class SetRxLoExportEnabled : public MexObjectRunner<LOGICAL_REQUIRED, STRING, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const bool enabled{ inputs[0][0][0] };
        if(inputs.size() == 1) {
            uhd->getUhd()->set_rx_lo_export_enabled(enabled);
        }
        else if(inputs.size() == 2) {
			const std::string name = inputs[1][0][0];
            uhd->getUhd()->set_rx_lo_export_enabled(enabled, name);
        }
        else {
			const std::string name = inputs[1][0][0];
			const size_t chan{ inputs[2][0][0] };
            uhd->getUhd()->set_rx_lo_export_enabled(enabled, name, chan);
        }   
    }
};

#endif