#ifndef _RECV_ASYNC_MSG_HPP_
#define _RECV_ASYNC_MSG_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/async_metadata_struct_factory.hpp"

//virtual bool recv_async_msg(async_metadata_t& async_metadata, double timeout = 0.1)
class RecvAsyncMsg : public MexObjectRunner<STRUCT_REQUIRED, DOUBLE> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		auto metadata = StructFactory<uhd::async_metadata_t>::createCpp(inputs[0]);
		bool recv{};
		if (inputs.size() == 1) {
			recv = uhd->getTxStreamer()->recv_async_msg(metadata);
		}
		else {
			const double timeout{ inputs[1][0][0] };
			recv = uhd->getTxStreamer()->recv_async_msg(metadata, timeout);
		}		
		outputs[0] = factory.createScalar(recv);
		outputs[1] = StructFactory<uhd::async_metadata_t>::createMatlab(metadata);
	}
};

#endif