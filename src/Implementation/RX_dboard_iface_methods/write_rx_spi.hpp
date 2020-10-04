#ifndef _WRITE_RX_SPI_HPP_
#define _WRITE_RX_SPI_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual void write_spi(unit_t unit, const spi_config_t& config, uint32_t data, size_t num_bits)
class WriteRxSpi : public MexObjectRunner<INT32_REQUIRED, STRUCT_REQUIRED, UINT32_REQUIRED, INT64_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::writeSpi(uhd->getRxDboardIface(), outputs, inputs, engine);
	}
};

#endif