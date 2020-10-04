#ifndef _GET_MBOARD_SENSOR_NAMES_HPP_
#define _GET_MBOARD_SENSOR_NAMES_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual std::vector< std::string > 	get_mboard_sensor_names (size_t mboard=0)
class GetMboardSensorNames : public MexObjectRunner<INT64> {
protected:
    virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        std::vector<std::string> sensorNames {};
        if(inputs.size() == 0) {
            sensorNames = uhd->getUhd()->get_mboard_sensor_names();
        }
        else {
			const size_t mboard{ inputs[0][0][0] };
            sensorNames = uhd->getUhd()->get_mboard_sensor_names(mboard);
        }
		outputs[0] = factory.createArray({0, sensorNames.size()}, sensorNames.begin(), sensorNames.end());
    }
};

#endif