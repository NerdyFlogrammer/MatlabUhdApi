#ifndef _CLOSE_ALL_HPP_
#define _CLOSE_ALL_HPP_

#include "../../API/mex_non_object_runner.hpp"
#include "../../API/storage.hpp"

class CloseAll : public MexNonObjectRunner<> {
    
protected:
    virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        Storage::clear();
    }
};
#endif