#ifndef _GET_TX_DC_RANGE_HPP_
#define _GET_TX_DC_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual meta_range_t 	get_tx_dc_offset_range (size_t chan=0)
class GetTxDcOffsetRange : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const uhd::meta_range_t offsetRange = uhd->getUhd()->get_tx_dc_offset_range();
			outputs[0] = getOutputStruct(offsetRange);
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			const uhd::meta_range_t offsetRange = uhd->getUhd()->get_tx_dc_offset_range(chan);
			outputs[0] = getOutputStruct(offsetRange);
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