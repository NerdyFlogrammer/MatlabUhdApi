#ifndef _GET_TIME_LAST_PPS_HPP_
#define _GET_TIME_LAST_PPS_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual time_spec_t 	get_time_last_pps (size_t mboard=0)
class GetTimeLastPPS : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const uhd::time_spec_t& time = uhd->getUhd()->get_time_last_pps();
			outputs[0] = getOutputStruct(time);
		}
		else {
			const size_t mboard{ inputs[0][0][0] };
			const uhd::time_spec_t& time = uhd->getUhd()->get_time_last_pps(mboard);
			outputs[0] = getOutputStruct(time);;
		}
	}

	StructArray getOutputStruct(const uhd::time_spec_t& time) {
		StructArray retStruct = factory.createStructArray({ 1 }, { "real_secs", "full_secs", "frac_secs" });
		retStruct[0]["real_secs"] = factory.createScalar(time.get_real_secs());
		retStruct[0]["full_secs"] = factory.createScalar(time.get_full_secs());
		retStruct[0]["frac_secs"] = factory.createScalar(time.get_frac_secs());
		return retStruct;
	}
};

#endif