#ifndef _POKE32_HPP_
#define _POKE32_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	poke32 (const wb_addr_type addr, const uint32_t data)
class Poke32 : public MexObjectRunner<UINT32_REQUIRED, UINT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		const uint32_t data = inputs[1][0][0];
		uhd->getWbIface()->poke32(addr, data);
	}
};

#endif // !_POKE32_HPP_