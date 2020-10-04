#ifndef _ISSUE_STREAM_CMD_HPP_
#define _ISSUE_STREAM_CMD_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/stream_cmd_factory.hpp"

//virtual void issue_stream_cmd(const stream_cmd_t& stream_cmd, size_t chan = ALL_CHANS)
class IssueStreamCmd : public MexObjectRunner<STRUCT_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const auto streamCmd{ StructFactory<uhd::stream_cmd_t>::createCpp(inputs[0]) };
		//TODO: CHECK STREAMER
		if (inputs.size() == 1) {
			uhd->getUhd()->issue_stream_cmd(streamCmd);
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			uhd->getUhd()->issue_stream_cmd(streamCmd, chan);
		}
	}
};

#endif
