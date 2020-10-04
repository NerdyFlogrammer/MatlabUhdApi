#ifndef _GET_M_BOARD_NAME_HPP_
#define _GET_M_BOARD_NAME_HPP_

#include "../../API/mex_object_runner.hpp"

class GetMBoardName
        : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size())
		{
			outputs[0] = factory.createCharArray(uhd->getUhd()->get_mboard_name());
		}
		else {
			const size_t mboard{ inputs[0][0][0] };
			outputs[0] = factory.createCharArray(uhd->getUhd()->get_mboard_name(mboard));
		}
        
    }
};

#endif