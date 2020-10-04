#ifndef _UHD_HPP_
#define _UHD_HPP_

#include <uhd/usrp/multi_usrp.hpp>

class Uhd 
{
public:
	Uhd(uhd::usrp::multi_usrp::sptr uhd) : uhd_ptr{ uhd },
		rx_streamer_ptr{ }, 
		tx_streamer_ptr{ },
		rx_dboard_ptr{ },
		rxCpuFormat{ },
		rxOtwFormat{ },
		txCpuFormat{ },
		txOtwFormat{ }
	{ }

	inline auto getUhd() -> uhd::usrp::multi_usrp::sptr {
		return uhd_ptr;
	}

	void setRxStreamer(uhd::rx_streamer::sptr rx_streamer) {
		rx_streamer_ptr = rx_streamer;
	}
	inline uhd::rx_streamer::sptr getRxStreamer() {
		return rx_streamer_ptr;
	}

	inline void setTxStreamer(uhd::tx_streamer::sptr tx_streamer) {
		tx_streamer_ptr = tx_streamer;
	}
	inline auto getTxStreamer() -> uhd::tx_streamer::sptr {
		return tx_streamer_ptr;
	}

	inline void setRxDboardIface(uhd::usrp::dboard_iface::sptr rx_dboard) {
		rx_dboard_ptr = rx_dboard;
	}

	inline void setTxDboardIface(uhd::usrp::dboard_iface::sptr tx_dboard) {
		tx_dboard_ptr = tx_dboard;
	}

	inline auto getRxDboardIface() -> uhd::usrp::dboard_iface::sptr {
		return rx_dboard_ptr;
	}

	inline auto getTxDboardIface() -> uhd::usrp::dboard_iface::sptr {
		return tx_dboard_ptr;
	}

	inline void setWbIface(uhd::wb_iface::sptr wb_iface) {
		wb_iface_ptr = wb_iface;
	}
	inline auto getWbIface() -> uhd::wb_iface::sptr {
		return wb_iface_ptr;
	}

	//cpu & otw format

	inline void setRxCpuFormat(std::string rxCpu) {
		rxCpuFormat = std::move(rxCpu);
	}

	inline auto getRxCpuFormat() -> std::string {
		return rxCpuFormat;
	}

	inline void setTxCpuFormat(std::string txCpu) {
		txCpuFormat = std::move(txCpu);
	}

	inline auto getTxCpuFormat() -> std::string {
		return txCpuFormat;
	}

	inline void setRxOtwFormat(std::string rxOtw) {
		rxOtwFormat = std::move(rxOtw);
	}

	inline auto getRxOtwFormat() -> std::string {
		return rxOtwFormat;
	}

	inline void setTxOtwFormat(std::string txOtw) {
		txOtwFormat = std::move(txOtw);
	}

	inline auto getTxOtwFormat() -> std::string {
		return txOtwFormat;
	}

private:
	uhd::usrp::multi_usrp::sptr uhd_ptr;
	uhd::rx_streamer::sptr rx_streamer_ptr;
	uhd::tx_streamer::sptr tx_streamer_ptr;
	uhd::usrp::dboard_iface::sptr rx_dboard_ptr;
	uhd::usrp::dboard_iface::sptr tx_dboard_ptr;
	uhd::wb_iface::sptr wb_iface_ptr;
	std::string rxCpuFormat;
	std::string rxOtwFormat;
	std::string txCpuFormat;
	std::string txOtwFormat;
};

#endif

