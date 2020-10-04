#ifndef _GET_FILTER_HPP_
#define _GET_FILTER_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/filter_factory.hpp"

//virtual filter_info_base::sptr get_filter(const std::string& path)
class GetFilter : public MexObjectRunner<STRING_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string path = inputs[0][0][0];
		const auto filter_ptr = uhd->getUhd()->get_filter(path);
		outputs[0] = StructFactory<uhd::filter_info_base>::createMatlab(filter_ptr);
	}
};

#endif