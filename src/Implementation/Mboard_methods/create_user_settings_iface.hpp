#ifndef _CREATE_USER_SETINGS_IFACE_HPP_
#define _CREATE_USER_SETINGS_IFACE_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uhd::wb_iface::sptr 	get_user_settings_iface (const size_t chan=0)
class CreateUserSettingsIface : public MexObjectRunner<INT64> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		if (inputs.size() == 0) {
			auto wbIface{ uhd->getUhd()->get_user_settings_iface() };
			uhd->setWbIface(wbIface);
		}
		else {
			const size_t chan{ inputs[0][0][0] };
			auto wbIface{ uhd->getUhd()->get_user_settings_iface(chan) };
			uhd->setWbIface(wbIface);
		}
	}
};

#endif