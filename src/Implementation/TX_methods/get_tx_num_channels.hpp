#ifndef _GET_TX_NUM_CHANNELS_HPP_
#define _GET_TX_NUM_CHANNELS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual size_t 	get_tx_num_channels (void)
class GetTxNumChannels : public MexObjectRunner<> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const size_t numTxChannels{ uhd->getUhd()->get_tx_num_channels() };
		outputs[0] = factory.createScalar(numTxChannels);
    }
};

#endif