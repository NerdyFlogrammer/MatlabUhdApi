#ifndef _POKE16_HPP_
#define _POKE16_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	poke16 (const wb_addr_type addr, const uint16_t data)
class Poke16 : public MexObjectRunner<UINT32_REQUIRED, UINT16_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		const uint16_t data = inputs[1][0][0];
		uhd->getWbIface()->poke16(addr, data);
	}
};

#endif // !_POKE16_HPP_