#ifndef _ARGUMENT_HPP_
#define _ARGUMENT_HPP_

#include <iostream>


using matlab::mex::ArgumentList;

template<int M, int N, bool REQUIRED, matlab::data::ArrayType ...Ts>
class Argument
{
public:
    static constexpr bool isRequired() {
        return REQUIRED;
    }
	static inline bool checkArgument(ArgumentList& inputs, int i) {
        if(REQUIRED || i < inputs.size())
        {
			const auto type = inputs[i].getType();
			const ArrayType types[]{ Ts... };
			if (std::find(std::begin(types), std::end(types), type) == std::end(types)) {
				std::cerr << "Argument: " << i << std::endl <<
					"Typ: " << typeid(inputs[i].getType()).name() << " " << TYPES[static_cast<int>(inputs[i].getType())] << std::endl;
				for (auto t : { Ts... })
				{
					std::cerr << "Expected typ: " << typeid(t).name() << " " << TYPES[static_cast<int>(t)] << std::endl;
				}
                return false;
            }
        }
        return true;
	}

};

#endif
