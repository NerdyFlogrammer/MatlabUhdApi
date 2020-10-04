#ifndef _CLOSE_HPP_
#define _CLOSE_HPP_

#include "../../API/mex_non_object_runner.hpp"
#include "../../API/storage.hpp"

class Close : public MexNonObjectRunner<UINT32_REQUIRED> {

protected:
	virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const int index{ inputs[0][0][0] };
		Storage::remove(index);
	}
};
#endif