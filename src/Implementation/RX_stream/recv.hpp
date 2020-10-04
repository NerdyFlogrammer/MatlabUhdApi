#ifndef _RECV_HPP_
#define _RECV_HPP_

#include "../../API/mex_object_runner.hpp"
#include "../Structs/rx_meta_struct_factory.hpp"
#include <complex>
#include <unordered_map>
#include <functional>

//virtual size_t 	recv (const buffs_type &buffs, const size_t nsamps_per_buff, rx_metadata_t &metadata, const double timeout=0.1, const bool one_packet=false)
class Recv : public MexObjectRunner<INT64_REQUIRED, STRUCT_REQUIRED, DOUBLE, LOGICAL> {

protected:
	virtual void funcImpl(Uhd_ptr uhd, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) override {
		const auto rxStreamerPtr = uhd->getRxStreamer();
		if (rxStreamerPtr == nullptr) {
			engine->feval(u"error",
				0, std::vector<matlab::data::Array>({ factory.createScalar("rx_streamer not initialized!") }));
		}
		const auto cpu = uhd->getRxCpuFormat();
		recvX(cpu, rxStreamerPtr, outputs, inputs, engine);
	}

private:
	template<typename ...Ts>
	void recvX(std::string cpuFormat, Ts... ts) {
		if (cpuFormat == "fc64")	receive<std::complex<double>>(ts...);
		else if (cpuFormat == "fc32")	receive<std::complex<float>>(ts...);
		else if (cpuFormat == "sc16")	receive<std::complex<int16_t>>(ts...);
		else if (cpuFormat == "sc8")	receive<std::complex<int8_t>>(ts...);
		else if (cpuFormat == "f64")	receive<double>(ts...);
		else if (cpuFormat == "f32")	receive<float>(ts...);
		else if (cpuFormat == "s16")	receive<int16_t>(ts...);
		else if (cpuFormat == "s8")		receive<int8_t>(ts...);
		else receive<std::complex<double>>(ts...);
	}

	template<typename T>
	void receive(uhd::rx_streamer::sptr rxStreamerPtr, ArgumentList outputs, ArgumentList inputs, matlabEngine engine) {
		const size_t nSampsPerBuffer{ inputs[0][0][0] };
		std::vector<std::vector<T>> buffs(
			rxStreamerPtr->get_num_channels(), std::vector<T>(nSampsPerBuffer));
		// create a vector of pointers to point to each of the channel buffers
		std::vector<T*> recvBuffs;
		for (size_t i = 0; i < buffs.size(); i++) {
			recvBuffs.push_back(&buffs[i].front());
		}
		const std::vector<T> vecBuff(nSampsPerBuffer, 0); //ändern
		//uhd::rx_streamer::buffs_type receiveBuffer{ vecBuff };
		auto metaData = StructFactory<uhd::rx_metadata_t>::createCpp(inputs[1]);
		int numberOfSamplesReceived{ };
		if (inputs.size() == 2) {
			//receive(rxStreamerPtr, receiveBuffer, nSampsPerBuffer, metaData);
			numberOfSamplesReceived = rxStreamerPtr->recv(recvBuffs, nSampsPerBuffer, metaData);
		}
		else if (inputs.size() == 3) {
			const double timeout{ inputs[2][0][0] };
			//receive(rxStreamerPtr, receiveBuffer, nSampsPerBuffer, metaData, timeout);
			numberOfSamplesReceived = rxStreamerPtr->recv(recvBuffs, nSampsPerBuffer, metaData, timeout);
		}
		else {
			const double timeout{ inputs[2][0][0] };
			const bool onePacket{ inputs[3][0][0] };
			//receive(rxStreamerPtr, receiveBuffer, nSampsPerBuffer, metaData, timeout, onePacket);
			numberOfSamplesReceived = rxStreamerPtr->recv(recvBuffs, nSampsPerBuffer, metaData, timeout, onePacket);
		}
		std::vector<T> outBuff;
		for each (auto vec in buffs)
		{
			std::move(vec.begin(), vec.end(), std::back_inserter(outBuff));
		}
		outputs[0] = StructFactory<uhd::rx_metadata_t>::createMatlab(metaData);
		outputs[1] = factory.createScalar(numberOfSamplesReceived);
		outputs[2] = factory.createArray({ buffs[0].size(), buffs.size() }, outBuff.begin(), outBuff.end());

	}


/*
private:
	template<typename ...Ts>
	size_t receive(uhd::rx_streamer::sptr rx_streamer_ptr, uhd::rx_streamer::buffs_type& vec, size_t nSampsPerBuffer, uhd::rx_metadata_t& md, Ts... ts) {
		return rx_streamer_ptr->recv(vec, nSampsPerBuffer, md, ts...);
	}
	*/
};

#endif