#ifndef _CREATE_TX_STREAM_HPP_
#define _CREATE_TX_STREAM_HPP_

#include "../Structs/stream_args_struct.hpp"
#include "../../API/mex_object_runner.hpp"

//virtual tx_streamer::sptr 	get_tx_stream (const stream_args_t &args)
// stream_args_t (const std::string &cpu="", const std::string &otw="")
class CreateTxStream : public MexObjectRunner<STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const auto inputStruct = static_cast<matlab::data::StructArray>(inputs[0]);
		const auto args = getStreamArgs(inputStruct);
		uhd->setTxStreamer(uhd->getUhd()->get_tx_stream(args));
		uhd->setTxCpuFormat(args.cpu_format);
		uhd->setTxOtwFormat(args.otw_format);
	}
};
#endif