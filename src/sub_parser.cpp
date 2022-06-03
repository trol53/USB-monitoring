#include "sub_parser.hpp"

SubParser::SubParser(){
    file.open(file_name);
}

Dev SubParser::GetInfo(){
    std::string tmp;
    while (std::getline(file, tmp)){
        if (tmp.find("PRODUCT") != std::string::npos){
            size_t ind_start = tmp.find("=") + 1;
            std::string tmp_rev = tmp;
            std::reverse(tmp_rev.begin(), tmp_rev.end());
            size_t ind_end = tmp_rev.find("/");
            ind_end = tmp.size() - ind_end - 1;
            device.id_product = tmp.substr(ind_start, ind_end - ind_start);
        }
        if (tmp.find("DEVTYPE") != std::string::npos){
            size_t ind_start = tmp.find("=") + 1;
            device.dev_type = tmp.substr(ind_start, tmp.size());
        }
        if (tmp.find("ID_VENDOR_FROM_DATABASE") != std::string::npos){
            size_t ind_start = tmp.find("=") + 1;
            device.id_vendor_from_database = tmp.substr(ind_start, tmp.size());
        }
    }
    return device;
}