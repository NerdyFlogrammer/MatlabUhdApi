#ifndef _DBOARD_IFACE_HPP_
#define _DBOARD_IFACE_HPP_
#include "../Structs/special_props_t_factory.hpp"
#include "../Structs/spi_config_factory.hpp"
#include "../Structs/fe_connection_factory.hpp"

using DboardIface = uhd::usrp::dboard_iface::sptr;

class DboardIfaceMethods {
public:
	static inline void getSpecialProps(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void writeAuxDac(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void readAuxAdc(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setPinCtrl(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getPinCtrl(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setAtrReg(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getAtrReg(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setGpioDdr(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getGpioDdr(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setGpioOut(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getGpioOut(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void readGpio(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void writeSpi(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void readWriteSpi(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setClockRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getClockRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getClockRates(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setClockEnabled(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getCodecRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setFeConnection(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void hasSetFeConnection(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void getCommandTime(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void setCommandTime(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	static inline void sleep(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine);
	
};


inline void DboardIfaceMethods::getSpecialProps(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	auto specialProps = dboardIface->get_special_props();
	outputs[0] = StructFactory<uhd::usrp::dboard_iface_special_props_t>::createMatlab(specialProps);
}

inline void DboardIfaceMethods::writeAuxDac(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int input1 = inputs[0][0][0];
	const int input2 = inputs[1][0][0];
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(input1) };
	const auto whichDac{ static_cast<uhd::usrp::dboard_iface::aux_dac_t>(input2) };
	const double value{ inputs[2][0][0] };
	dboardIface->write_aux_dac(unit, whichDac, value);
}

inline void DboardIfaceMethods::readAuxAdc(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const int inputWhichDac{ inputs[1][0][0] };
	const auto whichDac{ static_cast<uhd::usrp::dboard_iface::aux_adc_t>(inputWhichDac) };
	const double value{ dboardIface->read_aux_adc(unit, whichDac) };
	outputs[0] = factory.createScalar(value);
}

inline void DboardIfaceMethods::setPinCtrl(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t value{ inputs[1][0][0] };
	if (inputs.size() == 2) {
		dboardIface->set_pin_ctrl(unit, value);
	}
	else {
		const uint32_t mask{ inputs[2][0][0] };
		dboardIface->set_pin_ctrl(unit, value, mask);
	}
}

inline void DboardIfaceMethods::getPinCtrl(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ dboardIface->get_pin_ctrl(unit) };
	outputs[0] = factory.createScalar(val);
}

inline void DboardIfaceMethods::setAtrReg(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const int inputAtrReg{ inputs[1][0][0] };
	const auto atrReg{ static_cast<uhd::usrp::gpio_atr::gpio_atr_reg_t>(inputAtrReg) };
	const uint32_t value{ inputs[2][0][0] };
	if (inputs.size() == 3) {
		dboardIface->set_atr_reg(unit, atrReg, value);
	}
	else {
		const uint32_t mask{ inputs[3][0][0] };
		dboardIface->set_atr_reg(unit, atrReg, value, mask);
	}
}

inline void DboardIfaceMethods::getAtrReg(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const int inputAtrReg{ inputs[1][0][0] };
	const auto atrReg{ static_cast<uhd::usrp::gpio_atr::gpio_atr_reg_t>(inputAtrReg) };
	const auto atrRegVal{ dboardIface->get_atr_reg(unit, atrReg) };
	outputs[0] = factory.createScalar(atrRegVal);
}

inline void DboardIfaceMethods::setGpioDdr(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ inputs[1][0][0] };
	if (inputs.size() == 2) {
		dboardIface->set_gpio_ddr(unit, val);
	}
	else {
		const uint32_t mask{ inputs[2][0][0] };
		dboardIface->set_gpio_ddr(unit, val, mask);
	}
}

inline void DboardIfaceMethods::getGpioDdr(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ dboardIface->get_gpio_ddr(unit) };
	outputs[0] = factory.createScalar(val);
}

inline void DboardIfaceMethods::setGpioOut(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ inputs[1][0][0] };
	if (inputs.size() == 2) {
		dboardIface->set_gpio_out(unit, val);
	}
	else {
		const uint32_t mask{ inputs[2][0][0] };
		dboardIface->set_gpio_out(unit, val, mask);
	}
}

inline void DboardIfaceMethods::getGpioOut(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ dboardIface->get_gpio_out(unit) };
	outputs[0] = factory.createScalar(val);
}

inline void DboardIfaceMethods::readGpio(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const uint32_t val{ dboardIface->read_gpio(unit) };
	outputs[0] = factory.createScalar(val);
}

inline void DboardIfaceMethods::writeSpi(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int input1{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(input1) };
	const auto spiConfig{ StructFactory<uhd::spi_config_t>::createCpp(inputs[1]) };
	const uint32_t data{ inputs[2][0][0] };
	const int64_t numBits{ inputs[3][0][0] };
	dboardIface->write_spi(unit, spiConfig, data, numBits);
}

inline void DboardIfaceMethods::readWriteSpi(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const auto spiConfig{ StructFactory<uhd::spi_config_t>::createCpp(inputs[1]) };
	const uint32_t data{ inputs[2][0][0] };
	const int64_t numBits{ inputs[3][0][0] };
	const auto readVal = dboardIface->read_write_spi(unit, spiConfig, data, numBits);
	outputs[0] = factory.createScalar(readVal);
}

inline void DboardIfaceMethods::setClockRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const double rate{ inputs[1][0][0] };
	dboardIface->set_clock_rate(unit, rate);
}

inline void DboardIfaceMethods::getClockRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const auto clock{ dboardIface->get_clock_rate(unit) };
	outputs[0] = factory.createScalar(clock);
}

inline void DboardIfaceMethods::getClockRates(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const auto clockRates = dboardIface->get_clock_rates(unit);
	outputs[0] = factory.createArray({ 1, clockRates.size() }, clockRates.begin(), clockRates.end());
}

inline void DboardIfaceMethods::setClockEnabled(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const bool enb{ inputs[1][0][0] };
	dboardIface->set_clock_enabled(unit, enb);
}

inline void DboardIfaceMethods::getCodecRate(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const auto rate{ dboardIface->get_codec_rate(unit) };
	outputs[0] = factory.createScalar(rate);
}

//virtual void set_fe_connection(unit_t unit, const std::string& fe_name, const uhd::usrp::fe_connection_t& fe_conn)
inline void DboardIfaceMethods::setFeConnection(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const std::string feName = inputs[1][0][0];
	const auto feConn = StructFactory<uhd::usrp::fe_connection_t>::createCpp(inputs[2]);
	dboardIface->set_fe_connection(unit, feName, feConn);
}

inline void DboardIfaceMethods::hasSetFeConnection(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int inputUnit{ inputs[0][0][0] };
	const auto unit{ static_cast<uhd::usrp::dboard_iface::unit_t>(inputUnit) };
	const bool val{ dboardIface->has_set_fe_connection(unit) };
	outputs[0] = factory.createScalar(val);
}

inline void DboardIfaceMethods::getCommandTime(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const auto commandTime{ dboardIface->get_command_time() };
	outputs[0] = factory.createScalar(commandTime.get_real_secs());
}

inline void DboardIfaceMethods::setCommandTime(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	const double time{ inputs[0][0][0] };
	dboardIface->set_command_time(time);
}

inline void DboardIfaceMethods::sleep(DboardIface dboardIface, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
	ArrayFactory factory;
	const int64_t input1{ inputs[0][0][0] };
	const boost::chrono::nanoseconds ns{ input1 };
	dboardIface->sleep(ns);
}

#endif
