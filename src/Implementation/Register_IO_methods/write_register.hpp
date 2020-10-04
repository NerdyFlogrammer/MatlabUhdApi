#ifndef _WRITE_REGISTER_HPP_
#define _WRITE_REGISTER_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void write_register(const std::string& path, const uint32_t field, const uint64_t value, const size_t mboard = 0)
class WriteRegister : public MexObjectRunner<STRING_REQUIRED, UINT32_REQUIRED, UINT64_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string path = inputs[0][0][0];
		const uint32_t field{ inputs[1][0][0] };
		const uint64_t value{ inputs[2][0][0] };
		if (inputs.size() == 3) {
			uhd->getUhd()->write_register(path, field, value);
		}
		else {
			const size_t mboard{ inputs[3][0][0] };
			uhd->getUhd()->write_register(path, field, value, mboard);
		}
	}
};

#endif