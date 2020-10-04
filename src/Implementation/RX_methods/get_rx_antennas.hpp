#ifndef _GET_RX_ANTENNAS_HPP_
#define _GET_RX_ANTENNAS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_rx_antennas (size_t chan=0)=0
class GetRxAntennas : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> rxAntennas { };
        if(inputs.size() == 0) {
			rxAntennas = uhd->getUhd()->get_rx_antennas();
        }
        else {
			const size_t chan{ inputs[0][0][0] };
			rxAntennas = uhd->getUhd()->get_rx_antennas(chan);
        }
		outputs[0] = factory.createArray({1, rxAntennas.size() }, rxAntennas.begin(), rxAntennas.end());
    }
};

#endif