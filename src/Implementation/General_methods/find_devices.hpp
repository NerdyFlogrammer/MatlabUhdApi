#ifndef _FIND_DEVICES_HPP_
#define _FIND_DEVICES_HPP_

#include "../../API/mex_non_object_runner.hpp"
#include <uhd/usrp/multi_usrp.hpp>
#include <string>
#include <algorithm> 


class FindDevices : public MexNonObjectRunner<> {
    
protected:
    virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
        auto devices = findUhdDevices();
        outputs[0] = factory.createArray({ 1, devices.size() }, devices.begin(),devices.end());
    }

    std::vector<std::string> findUhdDevices() {
        uhd::device_addr_t hint; //an empty hint discovers all devices
		uhd::device_addrs_t dev_addrs = uhd::device::find(hint);
        std::vector<std::string> devices;
        for (auto ptr = dev_addrs.begin(); ptr != dev_addrs.end(); ptr++) {
            auto device = *ptr;
            devices.push_back(device.to_string());
        }
        return devices;
    }
};

#endif // !_FIND_DEVICES_HPP_
