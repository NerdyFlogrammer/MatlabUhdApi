#ifndef _INIT_UHD_HPP_
#define _INIT_UHD_HPP_

#include "../../API/storage.hpp"
#include "../../API/mex_non_object_runner.hpp"
#include <uhd/utils/log_add.hpp>
#include <fstream>
#include <mutex>
#include <vector>

namespace {
	const std::unordered_map<uhd::log::severity_level,std::string> VERBOSITY = {
		{ uhd::log::severity_level::trace, "trace"},
		{ uhd::log::severity_level::debug, "debug"},
		{ uhd::log::severity_level::info, "info"},
		{ uhd::log::severity_level::warning, "warning"},
		{ uhd::log::severity_level::error, "error"},
		{ uhd::log::severity_level::fatal, "fatal"},
		{ uhd::log::severity_level::off, "off"}
	};
}


class InitUhd : public MexNonObjectRunner<STRING_REQUIRED, STRING> {
    
protected:
    virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string device = inputs[0][0][0];
		const uint32_t deviceNo{ static_cast<uint32_t>(Storage::addUHD(device)) };
		if (inputs.size() == 2) {
			std::string filename = inputs[1][0][0];
			enableLogger(filename);
		}
        outputs[0] = factory.createScalar(deviceNo);
    }

private:
	std::string enableLogger(std::string logfile) {
		uhd::log::set_log_level(uhd::log::severity_level::info);
		uhd::log::add_logger(logfile, [&, filename = std::move(logfile)](const uhd::log::logging_info& info) {
			std::mutex m;
			std::lock_guard<std::mutex> lg(m);
			std::string level = VERBOSITY.at(info.verbosity);
			std::ofstream log_file(
				filename, std::ios_base::app);
			log_file << "[" << level << "]" << " " << info.component << " " << info.message << std::endl;
		});
		return logfile;
	}
};
#endif