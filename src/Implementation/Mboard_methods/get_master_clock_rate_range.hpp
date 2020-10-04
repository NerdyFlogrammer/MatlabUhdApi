#ifndef _GET_MASTER_CLOCK_RATE_RANGE_HPP_
#define _GET_MASTER_CLOCK_RATE_RANGE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual meta_range_t 	get_master_clock_rate_range (const size_t mboard=0)
class GetMasterClockRateRange : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const auto mr = uhd->getUhd()->get_master_clock_rate_range();
			const auto mrMatlab = createMatlab(mr);
			outputs[0] = mrMatlab;
		}
		else {
			const size_t mboard{ inputs[0][0][0] };
			const auto mr = uhd->getUhd()->get_master_clock_rate_range(mboard);
			const auto mrMatlab = createMatlab(mr);
			outputs[0] = mrMatlab;
		}
	}

	inline auto createMatlab(const uhd::meta_range_t& mr) -> matlab::data::StructArray {
		constexpr auto START = "start";
		constexpr auto STOP = "stop";
		constexpr auto STEP = "step";
		const matlab::data::ArrayDimensions scalar{ 1, 1 };
		auto retStruct =
			factory.createStructArray(
				scalar,
				{ START, STOP,  STEP }
		);
		retStruct[0][START] = factory.createScalar(mr.start());
		retStruct[0][STOP] = factory.createScalar(mr.stop());
		retStruct[0][STEP] = factory.createScalar(mr.step());
		return retStruct;
	}
};

#endif