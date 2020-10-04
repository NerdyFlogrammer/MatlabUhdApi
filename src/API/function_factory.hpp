#ifndef _FUNCTION_FACTORY_HPP_
#define _FUNCTION_FACTORY_HPP_

#include <memory>
#include <unordered_map>
#include "mex_runner_interface.hpp"
#include "logger_interface.hpp"

using Func = std::unique_ptr<MexRunnerInterface>(*)();

class FunctionFactory {
public:
	FunctionFactory() 
	{ }
	std::shared_ptr<MexRunnerInterface> create(const std::string& name) {
		return functions.at(name)();
	}
	bool exists(const std::string& name) {
		if (functions.find(name) != functions.end()) {
			return true;
		}
		return false;
	}
private:
	static const std::unordered_map<std::string, Func> functions;
};

#endif