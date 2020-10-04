#ifndef _ENUMERATE_REGISTERS_HPP_
#define _ENUMERATE_REGISTERS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector<std::string> enumerate_registers(const size_t mboard = 0)
class EnumerateRegisters : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::string> registers{ };
		if (inputs.size() == 0) {
			registers = uhd->getUhd()->enumerate_registers();
		}
		else {
			const size_t mboard{ inputs[0][0][0] };
			registers = uhd->getUhd()->enumerate_registers(mboard);
		}
		outputs[0] = factory.createArray({1, registers.size()}, registers.begin(), registers.end());
	}
};

#endif