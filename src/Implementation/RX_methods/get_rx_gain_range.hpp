#ifndef _GET_RX_GAIN_RANGE_HPP_
#define _GET_RX_GAIN_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual gain_range_t 	get_rx_gain_range (const std::string &name, size_t chan=0)
class GetRxGainRange : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const std::string name = inputs[0][0][0];
        if(inputs.size() == 1) {
            const uhd::gain_range_t gainRange = uhd->getUhd()->get_rx_gain_range(name);
            outputs[0] = getOutputStruct(gainRange);
        }
        else {
			const size_t chan{ inputs[0][0][0] };
            const uhd::gain_range_t gainRange = uhd->getUhd()->get_rx_gain_range(name, chan);
            outputs[0] = getOutputStruct(gainRange);
        } 
    }
    
    StructArray getOutputStruct(const uhd::meta_range_t& metaRange) {
        StructArray retStruct = factory.createStructArray({ 1 }, { "start", "stop", "step" });
        retStruct[0]["start"] = factory.createScalar(metaRange.start());
        retStruct[0]["stop"] = factory.createScalar(metaRange.stop());
        retStruct[0]["step"] = factory.createScalar(metaRange.step());
        return retStruct;
    }
};

#endif