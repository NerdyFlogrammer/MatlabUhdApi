#ifndef _GET_TX_LO_FREQ_RANGE_HPP_
#define _GET_TX_LO_FREQ_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual freq_range_t 	get_tx_lo_freq_range (const std::string &name, const size_t chan=0)
class GetTxLoFreqRange : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string name = inputs[0][0][0];
        if(inputs.size() == 1) {
            const uhd::freq_range_t freqRange = uhd->getUhd()->get_tx_lo_freq_range(name);
            outputs[0] = getOutputStruct(freqRange);
        }
        else {
			const size_t chan{ inputs[1][0][0] };
            const uhd::freq_range_t freqRange = uhd->getUhd()->get_tx_lo_freq_range(name, chan);
            outputs[0] = getOutputStruct(freqRange);
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