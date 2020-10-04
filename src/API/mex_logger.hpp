#ifndef _MEX_LOGGER_HPP_
#define _MEX_LOGGER_HPP_

#include <iostream>
#include "logger_interface.hpp"

class MexLogger : public LoggerInterface {
public:
	MexLogger(matlabEngine engine) : mEngine{ engine }
	{ }
	virtual void info(std::string info) override;
	virtual void warn(std::string warn) override;
	virtual void error(std::string error) override;
private:
	matlabEngine mEngine;
	ArrayFactory mFactory;
};

void MexLogger::info(std::string info) {
	std::cout << info << std::endl;
}

void MexLogger::warn(std::string warn) {
	std::cout << warn << std::endl;
}

void MexLogger::error(std::string error) {
	mEngine->feval(u"error",
		0, std::vector<matlab::data::Array>({ mFactory.createScalar(error) }));
}

#endif // !_MEX_LOGGER_HPP_
