#ifndef MEX_NON_OBJECT_RUNNER_HPP
#define MEX_NON_OBJECT_RUNNER_HPP

#include "mex_runner_interface.hpp"
#include "mex_non_object_interface.hpp"
#include "argument_list_verifier.hpp"
#include "argument_type_def.hpp"

template<typename... Ts>
class MexNonObjectRunner : public MexRunnerInterface, protected MexNonObjectInterface{
    
public:
    virtual void run(ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
};


template<typename... Ts>
inline void MexNonObjectRunner<Ts ...>::run(ArgumentList outputs, ArgumentList inputs, matlabEngine engine){
    ArgumentListVerifier<STRING_REQUIRED, Ts ...>::check(inputs, engine);
    ArgumentList args(inputs.begin() + 1, inputs.end(), inputs.size() - 1); 
    funcImpl(outputs, args, engine);
}

#endif