#ifndef _GET_GPIO_BANKS_HPP_
#define _GET_GPIO_BANKS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector<std::string> get_gpio_banks(const size_t mboard) 
class GetGpioBanks : public MexObjectRunner<INT64_REQUIRED> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t mboard{ inputs[0][0][0] };
		const auto banks = uhd->getUhd()->get_gpio_banks(mboard);
		outputs[0] = factory.createArray({ 1, banks.size() }, banks.begin(), banks.end());
    }
};

#endif