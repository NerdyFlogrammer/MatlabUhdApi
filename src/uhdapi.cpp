#include "mex.hpp"
#include "mexAdapter.hpp"
#include "API/function_factory.hpp"
#include "Implementation/function_factory_table.hpp"
#include "API/mex_logger.hpp"


using matlab::mex::Function;
using matlab::mex::ArgumentList;

class MexFunction : 
	public Function
{
public:
	MexFunction() : 
		mFuncFactory{ },
		mLogger{ std::make_shared<MexLogger>(getEngine()) }
	{ }

	void operator()(ArgumentList outputs, ArgumentList inputs) {
		const std::string command = inputs[0][0][0];
		if (mFuncFactory.exists(command) == false) {
			mLogger->error("Function does not exists!");
		}
		auto func = mFuncFactory.create(command);
		func->run(outputs, inputs, getEngine());
	}
private:
	FunctionFactory mFuncFactory;
	Logger mLogger;

};


