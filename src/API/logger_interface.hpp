#ifndef _LOGGER_INTERFACE_HPP_
#define _LOGGER_INTERFACE_HPP_
 
#include <string>

class LoggerInterface {
public:
	virtual ~LoggerInterface() = default;
	virtual void info(std::string info) = 0;
	virtual void warn(std::string warn) = 0;
	virtual void error(std::string error) = 0;
};

using Logger = std::shared_ptr<LoggerInterface>;

#endif // !_LOGGER_HPP_
