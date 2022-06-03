#include <yaml-cpp/yaml.h>
#include <string>
#include <fstream>
#include <iostream>

struct  Settings
{
    std::string ip;
    std::string port;
    bool is_exist;
};


class MainParser {

public:

    MainParser();
    Settings IsExist(const std::string& id_product);

private:

    // std::string file_name = "/home/Trol53/diploma/src/config.yaml";
    std::string file_name = "/etc/usb_monitor/config.yaml";

};