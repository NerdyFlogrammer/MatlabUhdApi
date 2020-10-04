#ifndef _GET_NUM_MBOARDS_HPP_
#define _GET_NUM_MBOARDS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual size_t 	get_num_mboards (void)
class GetNumMboards : public MexObjectRunner<> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t numBoards{ uhd->getUhd()->get_num_mboards() };
        outputs[0] = factory.createScalar(numBoards);
    }
};

#endif