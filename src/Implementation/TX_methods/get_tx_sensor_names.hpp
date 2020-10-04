#ifndef _GET_TX_SENSOR_NAMES_HPP_
#define _GET_TX_SENSOR_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_tx_sensor_names (size_t chan=0)
class GetTxSensorNames : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::string> sensorNames{ };
		if (inputs.size() == 0) {
			sensorNames = uhd->getUhd()->get_tx_sensor_names();

		}
		else {
			const size_t chan{ inputs[0][0][0] };
			sensorNames = uhd->getUhd()->get_tx_sensor_names(chan);
		}
		outputs[0] = factory.createArray({ 1, sensorNames.size() }, sensorNames.begin(), sensorNames.end());
	}
};

#endif