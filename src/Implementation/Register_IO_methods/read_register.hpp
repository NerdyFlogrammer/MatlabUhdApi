#ifndef _READ_REGISTER_HPP_
#define _READ_REGISTER_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uint64_t read_register(const std::string& path, const uint32_t field, const size_t mboard = 0)
class ReadRegister : public MexObjectRunner<STRING_REQUIRED, UINT32_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string path = inputs[0][0][0];
		const uint32_t field{ inputs[1][0][0] };
		uint64_t val{};
		if (inputs.size() == 2) {
			val = uhd->getUhd()->read_register(path, field);
		}
		else {
			const size_t mboard{ inputs[2][0][0] };
			val = uhd->getUhd()->read_register(path, field, mboard);
		}
		outputs[0] = factory.createScalar(val);
	}
};

#endif

