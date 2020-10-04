#ifndef _GET_RX_NUM_CHANNELS_HPP_
#define _GET_RX_NUM_CHANNELS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual size_t 	get_rx_num_channels (void)
class GetRxNumChannels : public MexObjectRunner<> {  
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        const size_t numChannels = uhd->getUhd()->get_rx_num_channels();
        outputs[0] = factory.createScalar(numChannels);
    }
};

#endif