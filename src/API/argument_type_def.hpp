#ifndef _ARGUMENT_TYPE_DEF_HPP_
#define _ARGUMENT_TYPE_DEF_HPP_

#include "Argument.hpp"
#include <map>

using matlab::data::ArrayType;

template<int ARRAY_SIZE>
using ARRAY_DOUBLE = Argument<1, ARRAY_SIZE, false, ArrayType::DOUBLE>;

template<int ARRAY_SIZE>
using ARRAY_DOUBLE_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::DOUBLE>;

using DOUBLE = ARRAY_DOUBLE<1>;
using DOUBLE_REQUIRED = ARRAY_DOUBLE_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_UINT8 = Argument<1, ARRAY_SIZE, false, ArrayType::UINT8>;

template<int ARRAY_SIZE>
using ARRAY_UINT8_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::UINT8>;

using UINT8 = ARRAY_UINT8<1>;
using UINT8_REQUIRED = ARRAY_UINT8_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_UINT16 = Argument<1, ARRAY_SIZE, false, ArrayType::UINT16>;

template<int ARRAY_SIZE>
using ARRAY_UINT16_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::UINT16>;

using UINT16 = ARRAY_UINT16<1>;
using UINT16_REQUIRED = ARRAY_UINT16_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_UINT32 = Argument<1, ARRAY_SIZE, false, ArrayType::UINT32>;

template<int ARRAY_SIZE>
using ARRAY_UINT32_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::UINT32>;

using UINT32 = ARRAY_UINT32<1>;
using UINT32_REQUIRED = ARRAY_UINT32_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_UINT64 = Argument<1, ARRAY_SIZE, false, ArrayType::UINT64>;

template<int ARRAY_SIZE>
using  ARRAY_UINT64_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::UINT64>;

using UINT64 = ARRAY_UINT64<1>;
using UINT64_REQUIRED = ARRAY_UINT64_REQUIRED<1>;



template<int ARRAY_SIZE>
using ARRAY_INT32 = Argument<1, ARRAY_SIZE, false, ArrayType::INT32>;

template<int ARRAY_SIZE>
using ARRAY_INT32_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::INT32>;

using INT32 = ARRAY_INT32<1>;
using INT32_REQUIRED = ARRAY_INT32_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_INT64 = Argument<1, ARRAY_SIZE, false, ArrayType::INT64>;

template<int ARRAY_SIZE>
using ARRAY_INT64_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::INT64>;

using INT64 = ARRAY_INT64<1>;
using INT64_REQUIRED = ARRAY_INT64_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_COMPLEX_DOUBLE = Argument<1, ARRAY_SIZE, false, ArrayType::COMPLEX_DOUBLE>;

template<int ARRAY_SIZE>
using ARRAY_COMPLEX_DOUBLE_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::COMPLEX_DOUBLE>;

using COMPLEX_DOUBLE = ARRAY_COMPLEX_DOUBLE<1>;
using COMPLEX_DOUBLE_REQUIRED = ARRAY_COMPLEX_DOUBLE_REQUIRED<1>;



template<int ARRAY_SIZE>
using ARRAY_LOGICAL = Argument<1, ARRAY_SIZE, false, ArrayType::LOGICAL>;

template<int ARRAY_SIZE>
using ARRAY_LOGICAL_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::LOGICAL>;

using LOGICAL = ARRAY_LOGICAL<1>;
using LOGICAL_REQUIRED = ARRAY_LOGICAL_REQUIRED<1>;


template<int ARRAY_SIZE>
using ARRAY_STRING = Argument<1, ARRAY_SIZE, false, ArrayType::MATLAB_STRING>;

template<int ARRAY_SIZE>
using ARRAY_STRING_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::MATLAB_STRING>;

using STRING = ARRAY_STRING<1>;
using STRING_REQUIRED = ARRAY_STRING_REQUIRED<1>;



template<int ARRAY_SIZE>
using ARRAY_COMPLEX_DOUBLE = Argument<1, ARRAY_SIZE, false, ArrayType::COMPLEX_DOUBLE>;

template<int ARRAY_SIZE>
using ARRAY_COMPLEX_DOUBLE_REQUIRED = Argument<1, ARRAY_SIZE, true, ArrayType::COMPLEX_DOUBLE>;

using COMPLEX_DOUBLE = ARRAY_COMPLEX_DOUBLE<1>;
using COMPLEX_DOUBLE_REQUIRED = ARRAY_COMPLEX_DOUBLE_REQUIRED<1>;


using STRUCT = Argument<1, 1, false, ArrayType::STRUCT>;
using STRUCT_REQUIRED = Argument<1, 1, true, ArrayType::STRUCT>;

using ENUM = Argument<1, 1, false, ArrayType::ENUM>;
using ENUM_REQUIRED = Argument<1, 1, true, ArrayType::ENUM>;

using MATRIX_NUMBER_COMPLEX_REQUIRED = Argument<-1, -1, true,
	ArrayType::COMPLEX_DOUBLE, ArrayType::COMPLEX_SINGLE, ArrayType::COMPLEX_INT16,
	ArrayType::COMPLEX_INT8, ArrayType::DOUBLE, ArrayType::SINGLE, ArrayType::INT16,
	ArrayType::INT8>;


static std::vector<std::string> TYPES = {
			"LOGICAL",
			"CHAR",
			"MATLAB_STRING",
			"DOUBLE",
			"SINGLE",
			"INT8",
			"UINT8",
			"INT16",
			"UINT16",
			"INT32",
			"UINT32",
			"INT64",
			"UINT64",
			"COMPLEX_DOUBLE",
			"COMPLEX_SINGLE",
			"COMPLEX_INT8",
			"COMPLEX_UINT8",
			"COMPLEX_INT16",
			"COMPLEX_UINT16",
			"COMPLEX_INT32",
			"COMPLEX_UINT32",
			"COMPLEX_INT64",
			"COMPLEX_UINT64",
			"CELL",
			"STRUCT",
			"OBJECT",
			"VALUE_OBJECT",
			"HANDLE_OBJECT_REF",
			"ENUM",
			"SPARSE_LOGICAL",
			"SPARSE_DOUBLE",
			"SPARSE_COMPLEX_DOUBLE",
			"UNKNOWN"
};

#endif