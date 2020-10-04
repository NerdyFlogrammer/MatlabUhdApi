#ifndef _READ_WRITE_TX_SPI_HPP_
#define _READ_WRITE_TX_SPI_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Dboard_iface_base/dboard_iface_methods.hpp"

//virtual uint32_t read_write_spi(unit_t unit, const spi_config_t& config, uint32_t data, size_t num_bits)
class ReadWriteTxSpi : public MexObjectRunner<INT32_REQUIRED, STRUCT_REQUIRED, UINT32_REQUIRED, INT64_REQUIRED> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		DboardIfaceMethods::readWriteSpi(uhd->getTxDboardIface(), outputs, inputs, engine);
	}
};

#endif