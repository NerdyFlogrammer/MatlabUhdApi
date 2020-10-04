#ifndef MEX_OBJECT_INTERFACE_HPP
#define MEX_OBJECT_INTERFACE_HPP

#include "storage.hpp"

class MexObjectInterface {

protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) = 0;

};

#endif