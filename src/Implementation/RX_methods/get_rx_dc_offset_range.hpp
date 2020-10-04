#ifndef _GET_RX_DC_RANGE_HPP_
#define _GET_RX_DC_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual meta_range_t 	get_rx_dc_offset_range (size_t chan=0)
class GetRxDcOffsetRange : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const auto offsetRange{ uhd->getUhd()->get_rx_dc_offset_range() };
			const auto mr = getOutputStruct(offsetRange);
			outputs[0] = mr;
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			const auto offsetRange = uhd->getUhd()->get_rx_dc_offset_range(chan);
			const auto mr = getOutputStruct(offsetRange);
			outputs[0] = mr;
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