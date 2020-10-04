#ifndef _GET_FE_TX_FREQ_RANGE_HPP_
#define _GET_FE_TX_FREQ_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual freq_range_t 	get_fe_tx_freq_range (size_t chan=0)=0
class GetFeTxFreqRange : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const uhd::meta_range_t freqRange = uhd->getUhd()->get_fe_tx_freq_range();
			outputs[0] = getOutputStruct(freqRange);
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			const uhd::meta_range_t freqRange = uhd->getUhd()->get_fe_tx_freq_range(chan);
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