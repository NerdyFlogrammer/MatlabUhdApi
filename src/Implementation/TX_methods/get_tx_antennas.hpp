#ifndef _GET_TX_ANTENNAS_HPP_
#define _GET_TX_ANTENNAS_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_tx_antennas (size_t chan=0)
class GetTxAntennas : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::string> txAntennas{ };
		if (inputs.size() == 0) {
			txAntennas = uhd->getUhd()->get_tx_antennas();
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			txAntennas = uhd->getUhd()->get_tx_antennas();
		}
		outputs[0] = factory.createArray({ 1, txAntennas.size() }, txAntennas.begin(), txAntennas.end());
	}
};

#endif