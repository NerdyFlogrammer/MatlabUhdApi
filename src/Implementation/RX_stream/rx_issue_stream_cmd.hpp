#ifndef _RX_ISSUE_STREAM_CMD_HPP_
#define _RX_ISSUE_STREAM_CMD_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/stream_cmd_factory.hpp"

//virtual void 	issue_stream_cmd(const stream_cmd_t &stream_cmd) 
class RxIssueStreamCmd : public MexObjectRunner<STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const auto streamCmd{ StructFactory<uhd::stream_cmd_t>::createCpp(inputs[0]) };
		//TODO: CHECK STREAMER
		uhd->getRxStreamer()->issue_stream_cmd(streamCmd);
	}
};

#endif
