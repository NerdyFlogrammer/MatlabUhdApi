#ifndef MEX_RUNNER_INTERFACE_HPP
#define MEX_RUNNER_INTERFACE_HPP

#include <iostream>

using matlab::mex::ArgumentList;
using matlabEngine = std::shared_ptr<matlab::engine::MATLABEngine>;
using matlab::data::ArrayFactory;

class MexRunnerInterface{
public:
    MexRunnerInterface& operator=(const MexRunnerInterface&)&  = delete;
    virtual void run(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) = 0;
protected:
    ArrayFactory factory;
};

#endif