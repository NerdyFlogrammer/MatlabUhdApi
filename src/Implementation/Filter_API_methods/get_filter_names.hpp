#ifndef _GET_FILTER_NAMES_HPP_
#define _GET_FILTER_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector<std::string> get_filter_names(const std::string& search_mask = "")
class GetFilterNames : public MexObjectRunner<STRING> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::string> filterNames{ };
		if (inputs.size() == 0) {
			filterNames = uhd->getUhd()->get_filter_names();
		}
		else {
			const std::string searchMask = inputs[0][0][0];
			filterNames = uhd->getUhd()->get_filter_names(searchMask);
		}
		
		outputs[0] = factory.createArray({ 1, filterNames.size() }, filterNames.begin(), filterNames.end());
	}
};

#endif