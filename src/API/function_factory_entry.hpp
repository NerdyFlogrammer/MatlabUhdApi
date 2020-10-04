#ifndef _FUNCTION_FACTORY_HPP
#define _FUNCTION_FACTORY_HPP

template<typename T>
struct FactoryEntry {
	static constexpr std::pair<std::string, Func> registerFunction(std::string funcName) {
		return {
			funcName,
			[]() -> std::unique_ptr<MexRunnerInterface> { 
				return std::make_unique<T>();
			}
		};
	}
};

#endif // !_FUNCTION_FACTORY_HPP
