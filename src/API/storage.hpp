#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include <string>
#include <map>
#include <iostream>
#include <cstddef>
#include "uhd.hpp"

using Uhd_ptr = std::shared_ptr<Uhd> ;

namespace {
    std::map<int, Uhd_ptr> uhds_{};
    int index_{};
}

class Storage
	{
public:
		static int addUHD(std::string uhd_str) {
			auto uhd{ std::make_shared<Uhd>(uhd::usrp::multi_usrp::make(uhd_str)) };
			uhds_[index_] = uhd;
			return index_++;
		}

		static Uhd_ptr getUHD(int index) {
            auto itr = uhds_.find(index);
            if(itr == uhds_.end())
            {
				return Uhd_ptr{ nullptr };
            }
			return itr->second;
		}
        
        static void clear() {
            uhds_.clear();
            index_ = 0;        
		}

		static void remove(int index) {
			uhds_.erase(index);
		}
};

#endif /* STORAGE_HPP_ */
