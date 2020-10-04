#ifndef _CREATE_RX_STREAM_HPP_
#define _CREATE_RX_STREAM_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/stream_args_struct.hpp"

//virtual rx_streamer::sptr 	get_rx_stream (const stream_args_t &args) 
//stream_args_t (const std::string &cpu="", const std::string &otw="")
class CreateRxStream : public MexObjectRunner<STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const auto inputStruct = static_cast<matlab::data::StructArray>(inputs[0]);
		const auto args = getStreamArgs(inputStruct);
		uhd->setRxStreamer(uhd->getUhd()->get_rx_stream(args));
		uhd->setRxCpuFormat(args.cpu_format);
		uhd->setRxOtwFormat(args.otw_format);
	}
};
#endif