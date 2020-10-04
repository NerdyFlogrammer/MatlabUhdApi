#ifndef _GET_TX_STREAM_NUM_CHANNELS_HPP_
#define _GET_TX_STREAM_NUM_CHANNELS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual size_t 	get_num_channels (void) const
class GetTxStreamNumChannels : public MexObjectRunner<> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t maxNumSamps{ uhd->getTxStreamer()->get_num_channels() };
		outputs[0] = factory.createScalar(maxNumSamps);
	}
};

#endif