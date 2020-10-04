#ifndef _SET_USER_REGISTER_HPP_
#define _SET_USER_REGISTER_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	set_user_register (const uint8_t addr, const uint32_t data, size_t mboard=ALL_MBOARDS)
class SetUserRegister : public MexObjectRunner<UINT8_REQUIRED, UINT32_REQUIRED, INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint8_t addr{ inputs[0][0][0] };
		const uint32_t data{ inputs[1][0][0] };
        if(inputs.size() == 2) {
            uhd->getUhd()->set_user_register(addr, data);
        }
        else {
			const size_t mboard{ inputs[2][0][0] };
            uhd->getUhd()->set_user_register(addr, data, mboard);
        }        
    }
};

#endif