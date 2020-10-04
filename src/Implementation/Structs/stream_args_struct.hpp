#ifndef _STREAM_ARGS_STRUCT_HPP_
#define _STREAM_ARGS_STRUCT_HPP_

#include "mex.hpp"
#include "mexAdapter.hpp"
#include <uhd/stream.hpp>

auto getStreamArgs(matlab::data::StructArray inputStruct) -> uhd::stream_args_t {
	matlab::data::Array const cpuArr = inputStruct[0]["cpu_format"];
	matlab::data::Array const otwArr = inputStruct[0]["otw_format"];
	const std::string cpu = cpuArr[0];
	const std::string otw = otwArr[0];
	uhd::stream_args_t streamArgs{ cpu, otw };
	matlab::data::StructArray const argsStruct = inputStruct[0]["args"];
	auto fields = argsStruct.getFieldNames();
	for each (auto field in fields)
	{
		matlab::data::Array const argsArr = argsStruct[0][field];
		const std::string arg = argsArr[0];
		streamArgs.args[field] = arg;
	}
	matlab::data::Array const chanArr = inputStruct[0]["channels"];
	for (auto i = 0; i < chanArr.getNumberOfElements(); i++)
	{
		streamArgs.channels.push_back(chanArr[i]);
	}
	return streamArgs;
}

#endif // !_STREAM_ARGS_STRUCT_HPP_