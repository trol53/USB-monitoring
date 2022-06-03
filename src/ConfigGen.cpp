#include "ConfigGen.hpp"

void ConfigGen::DevGen(){

    std::filesystem::path p(dev_path);
    if (!std::filesystem::is_directory(p)){
        std::cout << "wrong directory name\n";
        return;
    }
    for (const auto & entry : std::filesystem::directory_iterator(p)){
        std::string tmp_dir = entry.path().string(), id_prod, id_vend;
        std::ifstream product_file(tmp_dir + "/" + "idProduct");
        std::ifstream vendor_file(tmp_dir + "/" + "idVendor");
        if (!product_file.is_open()){
            continue;
        }
        if (!vendor_file.is_open()){
            continue;
        }
        std::getline(product_file, id_prod);
        std::getline(vendor_file, id_vend);
        ZeroDel(id_prod);
        ZeroDel(id_vend);
        devices.push_back(id_vend + "/" + id_prod);
        // std:: cout << tmp_dir << " " << id_prod << " " << id_vend << std::endl;
        

    }
}

void ConfigGen::FileConfigGen(std::string ip, std::string port){
    DevGen();
    std::filesystem::path p(conf_path);
    if (!std::filesystem::is_directory(p)){
        std::filesystem::create_directory(p);
    }
    std::ofstream config(conf_path + "/" + config_name);
    config << "SnmpServer:\n";
    config << "  ip: " << ip << '\n';
    config << "  port: " << port << '\n' << '\n';
    config << "Products:\n";
    for (auto prod : devices){
        config << "  Product: " << prod << '\n';
    }
    config.close();
    
}

void ConfigGen::ZeroDel(std::string &s){
    std::reverse(s.begin(), s.end());
    for (size_t i = s.size() - 1; i >= 0; i--){
        if (s[i] == '0'){
            s.pop_back();
        } else {
            break;
        }
    }
    std::reverse(s.begin(), s.end());
    
}

int main(){
    ConfigGen gen;
    gen.FileConfigGen("172.20.240.3", "1162");
}