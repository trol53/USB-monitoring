#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <algorithm>

class ConfigGen{

public:

    void Gen();
    void DevGen();
    void ZeroDel(std::string &s);
    void FileConfigGen(std::string ip, std::string port);
    

    std::string conf_path = "/etc/usb_monitor";
    std::string config_name = "config.yaml";
    std::vector<std::string> devices;
    std::string dev_path = "/sys/bus/usb/devices/";

};