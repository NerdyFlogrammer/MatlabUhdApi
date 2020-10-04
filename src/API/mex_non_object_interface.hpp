#ifndef MEX_NON_OBJECT_INTERFACE_HPP
#define MEX_NON_OBJECT_INTERFACE_HPP

class MexNonObjectInterface {
protected:
    virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) = 0;
};

#endif