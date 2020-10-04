#ifndef MEX_OBJECT_RUNNER_HPP
#define MEX_OBJECT_RUNNER_HPP

#include "mex_runner_interface.hpp"
#include "mex_object_interface.hpp"
#include "argument_list_verifier.hpp"
#include "argument_type_def.hpp"

template<typename... Ts>
class MexObjectRunner : 
	public MexRunnerInterface, 
	protected MexObjectInterface 
{   
public:
    virtual void run(ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
};


template<typename... Ts>
void MexObjectRunner<Ts ...>::run(ArgumentList outputs, ArgumentList inputs, matlabEngine engine){
    ArgumentListVerifier<STRING_REQUIRED, UINT32_REQUIRED, Ts ...>::check(inputs, engine);
	Uhd_ptr uhd = Storage::getUHD(inputs[1][0][0]);
    if(uhd) {
        ArgumentList args(inputs.begin() + 2, inputs.end(), inputs.size() - 2); 
        funcImpl(uhd, outputs, args, engine);
    }
    else {
        //TODO: ERROR
    }
}

#endif