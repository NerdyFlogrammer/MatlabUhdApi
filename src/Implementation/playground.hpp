#ifndef _PLAYGROUND_HPP_
#define _PLAYGROUND_HPP_

#include <vector>
#include "../API/mex_non_object_runner.hpp"

using matlab::data::Array;

class Playground : public MexNonObjectRunner<> {
protected:
	virtual void funcImpl(ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		std::vector<std::vector<double>> buffs;
		std::vector<double> vect1{ 1, 2, 3 };
		std::vector<double> vect2{ 10, 20, 30 };
		buffs.push_back(vect1);
		buffs.push_back(vect2);
		std::vector<double> buff;
		
	}
};

#endif


