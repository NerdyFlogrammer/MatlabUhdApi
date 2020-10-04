#ifndef _GET_TX_RATES_HPP_
#define _GET_TX_RATES_HPP_

#include "../../API/mex_object_runner.hpp"

using matlab::data::StructArray;

//virtual meta_range_t 	get_tx_rates (size_t chan=0)=0
class GetTxRates : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			const uhd::meta_range_t txRates = uhd->getUhd()->get_tx_rates();
			outputs[0] = getOutputStruct(txRates);
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			const uhd::freq_range_t txRates = uhd->getUhd()->get_tx_rates(chan);
			outputs[0] = getOutputStruct(txRates);
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