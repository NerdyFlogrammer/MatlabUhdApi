#ifndef _FUNCTION_FACTORY_TABLE_HPP_
#define _FUNCTION_FACTORY_TABLE_HPP_

#include "../API/function_factory.hpp"
#include "../API/function_factory_entry.hpp"
#include "General_methods/include/general_methods.hpp"
#include "Mboard_methods/include/mboard_methods.hpp"
#include "RX_methods/include/rx_methods.hpp"
#include "RX_methods/include/gain_controls.hpp"
#include "LO_controls/include/lo_controls.hpp"
#include "RX_methods/include/gain_controls.hpp"
#include "TX_methods/include/tx_methods.hpp"
#include "GPIO_methods/include/gpio_methods.hpp"
#include "Register_IO_methods/include/register_io_methods.hpp"
#include "Filter_API_methods/include/filter_api_methods.hpp"
#include "RX_stream/include/rx_streamer_methods.hpp"
#include "TX_stream/include/tx_streamer_methods.hpp"
#include "iface_functions/include/iface_function.hpp"
#include "RX_dboard_iface_methods/include/rx_dboard_iface_methods.hpp"
#include "TX_dboard_iface_methods/include/tx_dboard_iface_methods.hpp"

const std::unordered_map<std::string, Func> FunctionFactory::functions = {
	//General methods
	FactoryEntry<	FindDevices	>::registerFunction(	"find_devices"		),
	FactoryEntry<	InitUhd		>::registerFunction(	"init_uhd"			),
	FactoryEntry<	Close		>::registerFunction(	"close"				),
	FactoryEntry<	CloseAll	>::registerFunction(	"close_all"			),

	FactoryEntry<	CreateRxStream	>::registerFunction(	"create_rx_stream"		),
	FactoryEntry<	CreateTxStream	>::registerFunction(	"create_tx_stream"		),
	FactoryEntry<	GetUsrpRxInfo	>::registerFunction(	"get_usrp_rx_info"		),
	FactoryEntry<	GetUsrpTxInfo	>::registerFunction(	"get_usrp_tx_info"		),

	//Mboard methods
	FactoryEntry<	SetMasterClockRate		>::registerFunction(	"set_master_clock_rate"			),
	FactoryEntry<	GetMasterClockRate		>::registerFunction(	"get_master_clock_rate"			),
	FactoryEntry<	GetMasterClockRateRange	>::registerFunction(	"get_master_clock_rate_range"	),
	FactoryEntry<	GetPPString				>::registerFunction(	"get_pp_string"					),
	FactoryEntry<	GetMBoardName			>::registerFunction(	"get_mboard_name"				),
	FactoryEntry<	GetTimeNow				>::registerFunction(	"get_time_now"					),
	FactoryEntry<	GetTimeLastPPS			>::registerFunction(	"get_time_last_pps"				),
	FactoryEntry<	SetTimeNow				>::registerFunction(	"set_time_now"					),
	FactoryEntry<	SetTimeNextPPS			>::registerFunction(	"set_time_next_pps"				),
	FactoryEntry<	SetTimeUnknownPPS		>::registerFunction(	"set_time_unknown_pps"			),
	FactoryEntry<	GetTimeSynchronized		>::registerFunction(	"get_time_synchronized"			),
	FactoryEntry<	SetCommandTime			>::registerFunction(	"set_command_time"				),
	FactoryEntry<	ClearCommandTime		>::registerFunction(	"clear_command_time"			),
	FactoryEntry<	IssueStreamCmd			>::registerFunction(	"issue_stream_cmd"				),
	FactoryEntry<	SetTimeSource			>::registerFunction(	"set_time_source"				),
	FactoryEntry<	GetTimeSource			>::registerFunction(	"get_time_source"				),
	FactoryEntry<	GetTimeSources			>::registerFunction(	"get_time_sources"				),
	FactoryEntry<	SetClockSource			>::registerFunction(	"set_clock_source"				),
	FactoryEntry<	GetClockSource			>::registerFunction(	"get_clock_source"				),
	FactoryEntry<	GetClockSources			>::registerFunction(	"get_clock_sources"				),
	FactoryEntry<	SetSyncSource			>::registerFunction(	"set_sync_source"				),
	FactoryEntry<	GetSyncSource			>::registerFunction(	"get_sync_source"				),
	FactoryEntry<	GetSyncSources			>::registerFunction(	"get_sync_sources"				),
	FactoryEntry<	SetClockSourceOut		>::registerFunction(	"set_clock_source_out"			),
	FactoryEntry<	SetTimeSourceOut		>::registerFunction(	"set_time_source_out"			),
	FactoryEntry<	GetNumMboards			>::registerFunction(	"get_num_mboards"				),
	FactoryEntry<	GetMboardSensor			>::registerFunction(	"get_mboard_sensor"				),
	FactoryEntry<	GetMboardSensorNames	>::registerFunction(	"get_mboard_sensor_names"		),
	FactoryEntry<	SetUserRegister			>::registerFunction(	"set_user_register"				),
	FactoryEntry<	CreateUserSettingsIface	>::registerFunction(	"create_user_settings_iface"	),

	//RX methods
	FactoryEntry<	SetRxSubdevSpec		>::registerFunction(	"set_rx_subdev_spec"	),
	FactoryEntry<	GetRxSubdevSpec		>::registerFunction(	"get_rx_subdev_spec"	),
	FactoryEntry<	GetRxNumChannels	>::registerFunction(	"get_rx_num_channels"	),
	FactoryEntry<	GetRxSubdevName		>::registerFunction(	"get_rx_subdev_name"	),
	FactoryEntry<	SetRxRate			>::registerFunction(	"set_rx_rate"			),
	FactoryEntry<	GetRxRate			>::registerFunction(	"get_rx_rate"			),
	FactoryEntry<	GetRxRates			>::registerFunction(	"get_rx_rates"			),
	FactoryEntry<	SetRxFreq			>::registerFunction(	"set_rx_freq"			),
	FactoryEntry<	GetRxFreq			>::registerFunction(	"get_rx_freq"			),
	FactoryEntry<	GetRxFreqRange		>::registerFunction(	"get_rx_freq_range"		),
	FactoryEntry<	GetFeRxFreqRange	>::registerFunction(	"get_fe_rx_freq_range"	),
	
	//LO controls
	FactoryEntry<	GetRxLoNames		>::registerFunction(	"get_rx_lo_names"			),
	FactoryEntry<	SetRxLoSource		>::registerFunction(	"set_rx_lo_source"			),
	FactoryEntry<	GetRxLoSource		>::registerFunction(	"get_rx_lo_source"			),
	FactoryEntry<	GetRxLoSources		>::registerFunction(	"get_rx_lo_sources"			),
	FactoryEntry<	SetRxLoExportEnabled>::registerFunction(	"set_rx_lo_export_enabled"	),
	FactoryEntry<	GetRxLoExportEnabled>::registerFunction(	"get_rx_lo_export_enabled"	),
	FactoryEntry<	SetRxLoFreq			>::registerFunction(	"set_rx_lo_freq"			),
	FactoryEntry<	GetRxLoFreq			>::registerFunction(	"get_rx_lo_freq"			),
	FactoryEntry<	GetRxLoFreqRange	>::registerFunction(	"get_rx_lo_freq_range"		),
	FactoryEntry<	GetTxLoNames		>::registerFunction(	"get_tx_lo_names"			),
	FactoryEntry<	SetTxLoSource		>::registerFunction(	"set_tx_lo_source"			),
	FactoryEntry<	GetTxLoSource		>::registerFunction(	"get_tx_lo_source"			),
	FactoryEntry<	GetLoTxSources		>::registerFunction(	"get_tx_lo_sources"			),
	FactoryEntry<	SetTxLoExportEnabled>::registerFunction(	"set_tx_lo_export_enabled"	),
	FactoryEntry<	GetTxLoExportEnabled>::registerFunction(	"get_tx_lo_export_enabled"	),
	FactoryEntry<	SetTxLoFreq			>::registerFunction(	"set_tx_lo_freq"			),
	FactoryEntry<	GetTxLoFreq			>::registerFunction(	"get_tx_lo_freq"			),
	FactoryEntry<	GetTxLoFreqRange	>::registerFunction(	"get_tx_lo_freq_range"		),

	//Gain controls
	FactoryEntry<	SetRxGain			>::registerFunction(	"set_rx_gain"				),
	FactoryEntry<	GetRxGainProfileNames>::registerFunction(	"get_rx_gain_profile_names"	),
	FactoryEntry<	SetRxGainProfile	>::registerFunction(	"set_rx_gain_profile"		),
	FactoryEntry<	GetRxGainProfile	>::registerFunction(	"get_rx_gain_profile"		),
	FactoryEntry<	SetNormalizedRxGain	>::registerFunction(	"set_normalized_rx_gain"	),
	FactoryEntry<	SetRxAgc			>::registerFunction(	"set_rx_agc"				),
	FactoryEntry<	GetRxGain			>::registerFunction(	"get_rx_gain"				),
	FactoryEntry<	GetNormalizedRxGain	>::registerFunction(	"get_normalized_rx_gain"	),
	FactoryEntry<	GetRxGainRange		>::registerFunction(	"get_rx_gain_range"			),
	FactoryEntry<	GetRxGainNames		>::registerFunction(	"get_rx_gain_names"			),
	FactoryEntry<	SetRxAntenna		>::registerFunction(	"set_rx_antenna"			),
	FactoryEntry<	GetRxAntenna		>::registerFunction(	"get_rx_antenna"			),
	FactoryEntry<	GetRxAntennas		>::registerFunction(	"get_rx_antennas"			),
	FactoryEntry<	SetRxBandwidth		>::registerFunction(	"set_rx_bandwidth"			),
	FactoryEntry<	GetRxBandwidth		>::registerFunction(	"get_rx_bandwidth"			),
	FactoryEntry<	GetRxBandwidthRange	>::registerFunction(	"get_rx_bandwidth_range"	),
	FactoryEntry<	CreateRxDboardIface	>::registerFunction(	"create_rx_dboard_iface"	),
	FactoryEntry<	GetRxSensor			>::registerFunction(	"get_rx_sensor"				),
	FactoryEntry<	GetRxSensorNames	>::registerFunction(	"get_rx_sensor_names"		),
	FactoryEntry<	SetRxDcOffset		>::registerFunction(	"set_rx_dc_offset"			),
	FactoryEntry<	SetRxDcOffsetComplex>::registerFunction(	"set_rx_dc_offset_complex"	),
	FactoryEntry<	GetRxDcOffsetRange	>::registerFunction(	"get_rx_dc_offset_range"	),
	FactoryEntry<	SetRxIqBalance		>::registerFunction(	"set_rx_iq_balance"			),
	FactoryEntry<	SetRxIqBalanceComplex>::registerFunction(	"set_rx_iq_balance_complex"	),
	
	//TX methods
	FactoryEntry<	SetTxSubdevSpec		>::registerFunction(	"set_tx_subdev_spec"		),
	FactoryEntry<	GetTxSubdevSpec		>::registerFunction(	"get_tx_subdev_spec"		),
	FactoryEntry<	GetTxNumChannels	>::registerFunction(	"get_tx_num_channels"		),
	FactoryEntry<	GetTxSubdevName		>::registerFunction(	"get_tx_subdev_name"		),
	FactoryEntry<	SetTxRate			>::registerFunction(	"set_tx_rate"				),
	FactoryEntry<	GetTxRate			>::registerFunction(	"get_tx_rate"				),
	FactoryEntry<	GetTxRates			>::registerFunction(	"get_tx_rates"				),
	FactoryEntry<	SetTxFreq			>::registerFunction(	"set_tx_freq"				),
	FactoryEntry<	GetTxFreq			>::registerFunction(	"get_tx_freq"				),
	FactoryEntry<	GetTxFreqRange		>::registerFunction(	"get_tx_freq_range"			),
	FactoryEntry<	GetFeTxFreqRange	>::registerFunction(	"get_fe_tx_freq_range"		),
	FactoryEntry<	SetTxGain			>::registerFunction(	"set_tx_gain"				),
	FactoryEntry<	GetTxGainProfileNames>::registerFunction(	"get_tx_gain_profile_names"	),
	FactoryEntry<	SetTxGainProfile	>::registerFunction(	"set_tx_gain_profile"		),
	FactoryEntry<	GetTxGainProfile	>::registerFunction(	"get_tx_gain_profile"		),
	FactoryEntry<	SetNormalizedTxGain	>::registerFunction(	"set_normalized_tx_gain"	),
	FactoryEntry<	GetTxGain			>::registerFunction(	"get_tx_gain"				),
	FactoryEntry<	GetNormalizedTxGain	>::registerFunction(	"get_normalized_tx_gain"	),
	FactoryEntry<	GetTxGainRange		>::registerFunction(	"get_tx_gain_range"			),
	FactoryEntry<	GetTxGainNames		>::registerFunction(	"get_tx_gain_names"			),
	FactoryEntry<	SetTxAntenna		>::registerFunction(	"set_tx_antenna"			),
	FactoryEntry<	GetTxAntenna		>::registerFunction(	"get_tx_antenna"			),
	FactoryEntry<	GetTxAntennas		>::registerFunction(	"get_tx_antennas"			),
	FactoryEntry<	SetTxBandwidth		>::registerFunction(	"set_tx_bandwidth"			),
	FactoryEntry<	GetTxBandwidth		>::registerFunction(	"get_tx_bandwidth"			),
	FactoryEntry<	GetTxBandwidthRange	>::registerFunction(	"get_tx_bandwidth_range"	),
	FactoryEntry<	CreateTxDboardIface	>::registerFunction(	"create_tx_dboard_iface"	),
	FactoryEntry<	GetTxSensor			>::registerFunction(	"get_tx_sensor"				),
	FactoryEntry<	GetTxSensorNames	>::registerFunction(	"get_tx_sensor_names"		),
	FactoryEntry<	SetTxDcOffset		>::registerFunction(	"set_tx_dc_offset"			),
	FactoryEntry<	GetTxDcOffsetRange	>::registerFunction(	"get_tx_dc_offset_range"	),
	FactoryEntry<	SetTxIqBalance		>::registerFunction(	"set_tx_iq_balance"			),
		
	// GPIO methods
	FactoryEntry<	GetGpioBanks		>::registerFunction(	"get_gpio_banks"			),
	FactoryEntry<	SetGpioAttr			>::registerFunction(	"set_gpio_attr"				),
	FactoryEntry<	GetGpioAttr			>::registerFunction(	"get_gpio_attr"				),
	FactoryEntry<	GetGpioStringAttr	>::registerFunction(	"get_gpio_string_attr"		),

	// Register IO methods
	FactoryEntry<	EnumerateRegisters	>::registerFunction(	"enumerate_registers"		),
	FactoryEntry<	GetRegisterInfo		>::registerFunction(	"get_register_info"			),
	FactoryEntry<	WriteRegister		>::registerFunction(	"write_register"			),
	FactoryEntry<	ReadRegister		>::registerFunction(	"read_register"				),

	// Filter API methods
	FactoryEntry<	GetFilterNames	>::registerFunction(	"get_filter_names"		),
	FactoryEntry<	GetFilter		>::registerFunction(	"get_filter"			),
	//FactoryEntry<	SetFilter		>::registerFunction(	"set_filter"			),
		
	// Rx stream methods
	FactoryEntry<	GetRxStreamNumChannels	>::registerFunction(	"get_rx_stream_num_channels"),
	FactoryEntry<	GetRxMaxNumSamps		>::registerFunction(	"get_rx_max_num_samps"		),
	FactoryEntry<	Recv					>::registerFunction(	"recv"						),
	FactoryEntry<	RxIssueStreamCmd		>::registerFunction(	"rx_issue_stream_cmd"		),

	// Tx stream methods
	FactoryEntry<	GetTxStreamNumChannels	>::registerFunction(	"get_tx_stream_num_channels"),
	FactoryEntry<	GetTxMaxNumSamps		>::registerFunction(	"get_tx_max_num_samps"		),
	FactoryEntry<	Send					>::registerFunction(	"send"						),
	FactoryEntry<	RecvAsyncMsg			>::registerFunction(	"recv_async_msg"			),

	// WB Iface methods		
	FactoryEntry<	Poke64	>::registerFunction(	"poke64"		),
	FactoryEntry<	Peek64	>::registerFunction(	"peek64"		),
	FactoryEntry<	Poke32	>::registerFunction(	"poke32"		),
	FactoryEntry<	Peek32	>::registerFunction(	"peek32"		),
	FactoryEntry<	Poke16	>::registerFunction(	"poke16"		),
	FactoryEntry<	Peek16	>::registerFunction(	"peek16"		),

	//RX dboard iface methods
	FactoryEntry<	GetRxSpecialProps		>::registerFunction(	"get_rx_special_props"		),
	FactoryEntry<	WriteRxAuxDac			>::registerFunction(	"write_rx_aux_dac"			),
	FactoryEntry<	ReadRxAuxAdc			>::registerFunction(	"read_rx_aux_adc"			),
	FactoryEntry<	SetRxPinCtrl			>::registerFunction(	"set_rx_pin_ctrl"			),
	FactoryEntry<	GetRxPinCtrl			>::registerFunction(	"get_rx_pin_ctrl"			),
	FactoryEntry<	SetRxAtrReg				>::registerFunction(	"set_rx_atr_reg"			),
	FactoryEntry<	GetRxAtrReg				>::registerFunction(	"get_rx_atr_reg"			),
	FactoryEntry<	SetRxGpioDdr			>::registerFunction(	"set_rx_gpio_ddr"			),
	FactoryEntry<	GetRxGpioDdr			>::registerFunction(	"get_rx_gpio_ddr"			),
	FactoryEntry<	SetRxGpioDdr			>::registerFunction(	"set_rx_gpio_out"			),
	FactoryEntry<	GetRxGpioDdr			>::registerFunction(	"get_rx_gpio_out"			),
	FactoryEntry<	ReadRxGpio				>::registerFunction(	"read_rx_gpio"				),
	FactoryEntry<	WriteRxSpi				>::registerFunction(	"write_rx_spi"				),
	FactoryEntry<	ReadWriteRxSpi			>::registerFunction(	"read_write_rx_spi"			),
	FactoryEntry<	SetRxClockRate			>::registerFunction(	"set_rx_clock_rate"			),
	FactoryEntry<	GetRxClockRate			>::registerFunction(	"get_rx_clock_rate"			),
	FactoryEntry<	GetRxClockRates			>::registerFunction(	"get_rx_clock_rates"		),
	FactoryEntry<	SetRxClockEnabled		>::registerFunction(	"set_rx_clock_enabled"		),
	FactoryEntry<	GetRxCodecRate			>::registerFunction(	"get_rx_codec_rate"			),
	FactoryEntry<	SetRxFeConnection		>::registerFunction(	"set_rx_fe_connection"		),
	FactoryEntry<	HasSetRxFeConnection	>::registerFunction(	"has_set_rx_fe_connection"	),
	FactoryEntry<	GetRxCommandTime		>::registerFunction(	"get_rx_command_time"		),
	FactoryEntry<	SetRxCommandTime		>::registerFunction(	"set_rx_command_time"		),
	FactoryEntry<	RxSleep					>::registerFunction(	"rx_sleep"					),

	//TX dboard iface methods
	FactoryEntry<	GetTxSpecialProps		>::registerFunction(	"get_tx_special_props"		),
	FactoryEntry<	WriteTxAuxDac			>::registerFunction(	"write_tx_aux_dac"			),
	FactoryEntry<	ReadTxAuxAdc			>::registerFunction(	"read_tx_aux_adc"			),
	FactoryEntry<	SetTxPinCtrl			>::registerFunction(	"set_tx_pin_ctrl"			),
	FactoryEntry<	GetTxPinCtrl			>::registerFunction(	"get_tx_pin_ctrl"			),
	FactoryEntry<	SetTxAtrReg				>::registerFunction(	"set_tx_atr_reg"			),
	FactoryEntry<	GetTxAtrReg				>::registerFunction(	"get_tx_atr_reg"			),
	FactoryEntry<	SetTxGpioDdr			>::registerFunction(	"set_tx_gpio_ddr"			),
	FactoryEntry<	GetTxGpioDdr			>::registerFunction(	"get_tx_gpio_ddr"			),
	FactoryEntry<	SetTxGpioDdr			>::registerFunction(	"set_tx_gpio_out"			),
	FactoryEntry<	GetTxGpioDdr			>::registerFunction(	"get_tx_gpio_out"			),
	FactoryEntry<	ReadTxGpio				>::registerFunction(	"read_tx_gpio"				),
	FactoryEntry<	WriteTxSpi				>::registerFunction(	"write_tx_spi"				),
	FactoryEntry<	ReadWriteTxSpi			>::registerFunction(	"read_write_tx_spi"			),
	FactoryEntry<	SetTxClockRate			>::registerFunction(	"set_tx_clock_rate"			),
	FactoryEntry<	GetTxClockRate			>::registerFunction(	"get_tx_clock_rate"			),
	FactoryEntry<	GetTxClockRates			>::registerFunction(	"get_tx_clock_rates"		),
	FactoryEntry<	SetTxClockEnabled		>::registerFunction(	"set_tx_clock_enabled"		),
	FactoryEntry<	GetTxCodecRate			>::registerFunction(	"get_tx_codec_rate"			),
	FactoryEntry<	SetTxFeConnection		>::registerFunction(	"set_tx_fe_connection"		),
	FactoryEntry<	HasSetTxFeConnection	>::registerFunction(	"has_set_tx_fe_connection"	),
	FactoryEntry<	GetTxCommandTime		>::registerFunction(	"get_tx_command_time"		),
	FactoryEntry<	SetTxCommandTime		>::registerFunction(	"set_tx_command_time"		),
	FactoryEntry<	TxSleep					>::registerFunction(	"tx_sleep"					)

};

#endif