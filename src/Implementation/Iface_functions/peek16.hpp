#ifndef _PEEK16_HPP_
#define _PEEK16_HPP_

#include "../../API/mex_object_runner.hpp"

//virtual uint16_t 	peek16 (const wb_addr_type addr)
class Peek16 : public MexObjectRunner<UINT32_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const uint32_t addr = inputs[0][0][0];
		uint16_t peek = uhd->getWbIface()->peek16(addr);
		outputs[0] = factory.createScalar(peek);
	}
};

#endif // !_PEEK16_HPP_

