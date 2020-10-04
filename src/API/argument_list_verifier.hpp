#ifndef _ARGUMENT_LIST_VERIFIER_HPP_
#define _ARGUMENT_LIST_VERIFIER_HPP_

#include <initializer_list>
#include <ostream>
#include <numeric>
#include <functional>
#include "mex.hpp"
#include "mexAdapter.hpp"

using matlab::mex::ArgumentList;
using matlabEngine = std::shared_ptr<matlab::engine::MATLABEngine>;
		
template<typename... Ts>
class ArgumentListVerifier
{
public:
	inline void static check(ArgumentList& inputs, matlabEngine& matlabPtr) {
        matlab::data::ArrayFactory factory;
        std::initializer_list<int> il{ (Ts::isRequired())... };
		const size_t args = il.size();
		const size_t req = std::accumulate(il.begin(), il.end(), 0);
		int index {};
        if(inputs.size() < req  || inputs.size() > args){
            std::ostringstream error;
            error << "Arguments: " << inputs.size() << std::endl << "Expected arguments: " << req << " - "
            << args << std::endl;
            matlabPtr->feval(u"error", 
                0, std::vector<matlab::data::Array>({ factory.createScalar(error.str()) }));
        }    
		std::initializer_list<bool> ilInput { (Ts::checkArgument(inputs, index++))... };
        bool inputError = std::all_of(ilInput.begin(), ilInput.end(), [](bool x) { return x; } );
        if(!inputError)
            matlabPtr->feval(u"error", 
                0, std::vector<matlab::data::Array>({ factory.createScalar("Input error") })); 
	}
};



#endif