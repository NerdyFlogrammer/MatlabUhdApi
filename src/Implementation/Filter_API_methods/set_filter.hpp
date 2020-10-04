#ifndef _SET_FILTER_HPP_
#define _SET_FILTER_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void set_filter(const std::string& path, filter_info_base::sptr filter)
class SetFilter : public MexObjectRunner<STRING_REQUIRED, STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string path = inputs[0][0][0];
		//auto filter = StructFactory<uhd::filter_info_base>::createMatlab
	
	}
};

#endif // !_SET_FILTER_HPP_

