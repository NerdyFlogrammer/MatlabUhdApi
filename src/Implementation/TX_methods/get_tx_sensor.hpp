#ifndef _GET_TX_SENSOR_HPP_
#define _GET_TX_SENSOR_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual sensor_value_t 	get_tx_sensor (const std::string &name, size_t chan=0)
class GetTxSensor : public MexObjectRunner<STRING_REQUIRED, INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const std::string name = inputs[0][0][0] ;
		double sensorValue{ };
		if (inputs.size() == 1) {
			sensorValue = uhd->getUhd()->get_tx_sensor(name).to_real();
		}
		else {
			const size_t chan{ inputs[1][0][0] };
			sensorValue = uhd->getUhd()->get_tx_sensor(name, chan).to_real();
		}
		outputs[0] = factory.createScalar(sensorValue);
	}

};

#endif