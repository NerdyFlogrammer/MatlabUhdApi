#ifndef _DICT_STRUCT_FACTORY_HPP_
#define _DICT_STRUCT_FACTORY_HPP_

#include "struct_factory.hpp"



matlab::data::StructArray getDictStruct(const uhd::dict<std::string, std::string>& dict) {
	ArrayFactory factory{ };
	const auto keys = dict.keys();
	matlab::data::StructArray retStruct = factory.createStructArray({ 1 }, keys);
	for each (auto key in keys)
	{
		retStruct[0][key] = factory.createScalar(dict.get(key));
	}
	return retStruct;
}

#endif // !_DICT_STRUCT_FACTORY_HPP_

