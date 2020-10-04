#ifndef _STRUCT_UTILS_HPP_
#define _STRUCT_UTILS_HPP_

#include <uhd/types/time_spec.hpp>
#include <uhd/types/tune_request.hpp>
#include <uhd/types/metadata.hpp>
#include <unordered_map>
#include <unordered_set>

namespace structUtils {
	template<typename T>
	struct TypeConverter {
		inline static constexpr T value(matlab::data::StructArray const & matlabStructArray, std::string const & fieldName) {
			const Array arr = matlabStructArray[0][fieldName];
			const T val{ static_cast<T>(arr[0]) };
			return val;
		}

		inline static constexpr T value(matlab::data::StructArray const & matlabStructArray, std::string const & fieldName, std::unordered_set<std::string> const & fields, T const defaultVal) {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const Array arr = matlabStructArray[0][fieldName];
			const T val{ static_cast<T>(arr[0]) };
			return val;
		}
	};

	template<>
	struct TypeConverter<uhd::rx_metadata_t::error_code_t> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray, 
			std::string const & fieldName, std::unordered_set<std::string> const & fields, uhd::rx_metadata_t::error_code_t const defaultVal) -> uhd::rx_metadata_t::error_code_t {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const int intVal{ arr[0] };
			const uhd::rx_metadata_t::error_code_t val{ static_cast<uhd::rx_metadata_t::error_code_t>(intVal) };
			return val;
		}
	};


	static std::unordered_map<std::string, uhd::tune_request_t::policy_t> policy{
		{	"POLICY_NONE",		uhd::tune_request_t::POLICY_NONE	},
		{	"POLICY_MANUAL",	uhd::tune_request_t::POLICY_MANUAL	},
		{	"POLICY_AUTO",		uhd::tune_request_t::POLICY_AUTO	}
	};

	template<>
	struct TypeConverter<uhd::tune_request_t::policy_t> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray, 
			std::string const & fieldName, std::unordered_set<std::string> const & fields, uhd::tune_request_t::policy_t defaultVal) -> uhd::tune_request_t::policy_t {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const std::string val = arr[0];
			return policy.at(val);
		}
	};

	template<>
	struct TypeConverter<uhd::async_metadata_t::event_code_t> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray,
			std::string const & fieldName, std::unordered_set<std::string> const & fields, uhd::async_metadata_t::event_code_t defaultVal) -> uhd::async_metadata_t::event_code_t {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const int val = arr[0];
			return static_cast<uhd::async_metadata_t::event_code_t>(val);
		}
	};

	template<>
	struct TypeConverter<uhd::filter_info_base::filter_type> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray, 
			std::string const & fieldName, std::unordered_set<std::string> const & fields) -> uhd::filter_info_base::filter_type {
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const int intVal{ arr[0] };
			const auto val{ static_cast<uhd::filter_info_base::filter_type>(intVal) };
			return val;
		}
	};

	template<>
	struct TypeConverter<uhd::usrp::fe_connection_t::sampling_t> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray,
			std::string const & fieldName, std::unordered_set<std::string> const & fields, uhd::usrp::fe_connection_t::sampling_t defaultVal) -> uhd::usrp::fe_connection_t::sampling_t {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const int intVal{ arr[0] };
			const auto val = static_cast<uhd::usrp::fe_connection_t::sampling_t>(intVal);
			return val;
		}
	};

	template<>
	struct TypeConverter<uhd::spi_config_t::edge_t> {
		inline static auto value(matlab::data::StructArray const & matlabStructArray, 
			std::string const & fieldName, std::unordered_set<std::string> const & fields, uhd::spi_config_t::edge_t defaultVal) -> uhd::spi_config_t::edge_t {
			if (fields.find(fieldName) == fields.end()) {
				return defaultVal;
			}
			const matlab::data::Array arr = matlabStructArray[0][fieldName];
			const int intVal{ arr[0] };
			const auto val{ static_cast<uhd::spi_config_t::edge_t>(intVal) };
			return val;
		}
	};

}

#endif // !_STRUCT_UTILS_HPP_