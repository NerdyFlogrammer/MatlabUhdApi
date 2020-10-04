#ifndef _POKE64_HPP_
#define _POKE64_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual void 	poke64 (const wb_addr_type addr, const uint64_t data)
class Poke64 : public MexObjectRunner<UINT32_REQUIRED, UINT64_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		const uint64_t data = inputs[1][0][0];
		uhd->getWbIface()->poke64(addr, data);
	}
};

#endif // !_POKE64_HPP_