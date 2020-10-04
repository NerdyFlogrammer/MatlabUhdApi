#ifndef _PEEK64_HPP_
#define _PEEK64_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uint64_t 	peek64 (const wb_addr_type addr)
class Peek64 : public MexObjectRunner<UINT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		uint64_t peek = uhd->getWbIface()->peek64(addr);
		outputs[0] = factory.createScalar(peek);
	}
};

#endif // !_PEEK64_HPP_