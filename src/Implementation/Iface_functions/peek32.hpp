#ifndef _PEEK32_HPP_
#define _PEEK32_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uint32_t 	peek32 (const wb_addr_type addr)
class Peek32 : public MexObjectRunner<UINT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		uint32_t peek = uhd->getWbIface()->peek32(addr);
		outputs[0] = factory.createScalar(peek);
	}
};

#endif // !_PEEK32_HPP_