#ifndef _GET_PP_STRING_HPP_
#define _GET_PP_STRING_HPP_

#include "../../API/mex_object_runner.hpp"

class GetPPString : public MexObjectRunner<> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        outputs[0] = factory.createCharArray(uhd->getUhd()->get_pp_string());
    }
};

#endif