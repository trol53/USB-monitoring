#include "main_parser.hpp"

MainParser::MainParser(){};

Settings MainParser::IsExist(const std::string& id_product){
    YAML::Node config = YAML::LoadFile(file_name);
    Settings set;
    set.is_exist = false;

    for(auto it = config.begin(); it != config.end(); it++) {
        if (it->first.as<std::string>() == "SnmpServer"){
            for (auto snmm_it = it->second.begin(); 
                    snmm_it != it->second.end();
                    snmm_it++){
                if (snmm_it->first.as<std::string>() == "ip"){
                    set.ip = snmm_it->second.as<std::string>();
                }
                if (snmm_it->first.as<std::string>() == "port"){
                    set.port = snmm_it->second.as<std::string>();
                }
            }
        }
        if (it->first.as<std::string>() == "Products"){
            for (auto prod_it = it->second.begin(); prod_it != it->second.end(); prod_it++){
                // std::cout << id_product << " " << prod_it->second.as<std::string>() << '\n';
                if (id_product == prod_it->second.as<std::string>()){
                    // std::cout << "true\n";
                    set.is_exist = true;
                }
            }
        }
    }
    return set;
}