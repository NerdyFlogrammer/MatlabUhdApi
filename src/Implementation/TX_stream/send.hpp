#ifndef _SEND_HPP_
#define _SEND_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/tx_meta_factory.hpp"
#include <vector>
#include <complex>

template<typename T>
using BufferStorage = std::vector<std::vector<T>>;
template<typename T>
using SendBuffers = std::vector<T*>;

//virtual size_t 	send (const buffs_type &buffs, const size_t nsamps_per_buff, const tx_metadata_t &metadata, const double timeout=0.1)
class Send : public MexObjectRunner<MATRIX_NUMBER_COMPLEX_REQUIRED, INT64_REQUIRED, STRUCT_REQUIRED, DOUBLE> {
protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {	
		const auto txStreamerPtr = uhd->getTxStreamer();
		if (txStreamerPtr == nullptr) {
			engine->feval(u"error",
				0, std::vector<matlab::data::Array>({ factory.createScalar("tx_streamer not initialized!") }));
		}
		const auto cpu = uhd->getTxCpuFormat();
		sendX(cpu, txStreamerPtr, outputs, inputs, engine);
	}

private:
	/* CPU format switch, calls the required send method */
	template<typename ...Ts>
	inline void sendX(std::string cpuFormat, Ts... ts) {
		if		(cpuFormat == "fc64")	send<std::complex<double>>(ts...);
		else if (cpuFormat == "fc32")	send<std::complex<float>>(ts...);
		else if (cpuFormat == "sc16")	send<std::complex<int16_t>>(ts...);
		else if (cpuFormat == "sc8")	send<std::complex<int8_t>>(ts...);
		else if (cpuFormat == "f64")	send<double>(ts...);
		else if (cpuFormat == "f32")	send<float>(ts...);
		else if (cpuFormat == "s16")	send<int16_t>(ts...);
		else if (cpuFormat == "s8")		send<int8_t>(ts...);
		else							send<std::complex<double>>(ts...);
	}

	template<typename T>
	inline void send(uhd::tx_streamer::sptr txStreamer, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
		BufferStorage<T> buffs{ };
		SendBuffers<T> sendBuffs{ };
		size_t numOfSampsSent{ };
		const Array inputBuffs{ inputs[0] };
		const size_t nsamps_per_buff{ inputs[1][0][0] };
		createBuff<T>(inputBuffs, buffs, sendBuffs);
		uhd::tx_metadata_t metaData = StructFactory<uhd::tx_metadata_t>::createCpp(inputs[2]);
		if (inputs.size() == 3)
		{
			numOfSampsSent = txStreamer->send(sendBuffs, nsamps_per_buff, metaData);
		}
		else {
			const double timeout{ inputs[3][0][0] };
			numOfSampsSent = txStreamer->send(sendBuffs, nsamps_per_buff, metaData, timeout);
		}
		outputs[0] = factory.createScalar(numOfSampsSent);
		outputs[1] = StructFactory<uhd::tx_metadata_t>::createMatlab(metaData);
	}

	template<typename T>
	inline void createBuff(const Array inputBuffs, BufferStorage<T>& buffs, SendBuffers<T>& sendBuffs) {
		// dimensions of input buffer
		const auto dims = inputBuffs.getDimensions();
		const auto nBuffs = dims.at(0);
		const auto lenBuff = dims.at(1);
		// resize buffers, prevents frequent copying 
		buffs.resize(nBuffs);
		sendBuffs.resize(nBuffs);
		// default value for move constructor, reduces the use of copy constructer 
		const T defaultComplex{};
		// move values to vector
		for (int i = 0; i < nBuffs; i++)
		{
			std::vector<T> buff(lenBuff, std::move(defaultComplex));
			for (int k = 0; k < lenBuff; k++)
			{
				buff[k] = inputBuffs[i][k];
			}
			buffs[i] = std::move(buff);
			sendBuffs[i] = &buffs[i].front();
		}
	}
};

#endif