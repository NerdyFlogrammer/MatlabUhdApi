#ifndef _GET_GPIO_STRING_ATTR_HPP_
#define _GET_GPIO_STRING_ATTR_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector<std::string> get_gpio_string_attr(const std::string& bank, const std::string& attr, const size_t mboard = 0)
class GetGpioStringAttr : public MexObjectRunner<STRING_REQUIRED, STRING_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string bank = inputs[0][0][0];
		const std::string attr = inputs[1][0][0];
		std::vector<std::string> gpioAttr{ };
		if (inputs.size() == 2) {
			gpioAttr = uhd->getUhd()->get_gpio_string_attr(bank, attr);
		}
		else
		{
			const size_t mboard{ inputs[2][0][0] };
			gpioAttr = uhd->getUhd()->get_gpio_string_attr(bank, attr, mboard);
		}
		outputs[0] = factory.createArray({ 1, gpioAttr.size() }, gpioAttr.begin(), gpioAttr.end());
	}
};

#endif