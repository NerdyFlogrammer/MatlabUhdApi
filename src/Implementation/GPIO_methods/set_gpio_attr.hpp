#ifndef _SET_GPIO_ATTR_HPP_
#define _SET_GPIO_ATTR_HPP_

#include "../../API/mex_object_runner.hpp"
//virtual void 	set_gpio_attr (const std::string &bank, const std::string &attr, const uint32_t value, const uint32_t mask=0xffffffff, const size_t mboard=0)
class SetGpioAttr : public MexObjectRunner<STRING_REQUIRED, STRING_REQUIRED, UINT32_REQUIRED, UINT32, INT64> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string bank = inputs[0][0][0]; 
		const std::string attr =  inputs[1][0][0];
		const uint32_t value{ inputs[2][0][0] };
		const uint32_t mask{ };
		if (inputs.size() == 3) {
			uhd->getUhd()->set_gpio_attr(bank, attr, value);
		}
		else if(inputs.size() == 4)
		{
			const uint32_t mask = inputs[3][0][0] ;
			uhd->getUhd()->set_gpio_attr(bank, attr, value, mask);
		}
		else {
			const uint32_t mask = inputs[3][0][0] ;
			const size_t mboard{ inputs[4][0][0] };
			uhd->getUhd()->set_gpio_attr(bank, attr, value, mask, mboard);
		}
    }
};

#endif