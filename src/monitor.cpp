#include "monitor.hpp"
#include <vector>
#include <iostream>


void Monitor::ScriptRun(std::string script_name){
    timespec ts;
    ts.tv_sec = 0.05;
    ts.tv_nsec = 0;
    pid_t pid = fork();
    nanosleep(&ts, &ts);
    if (pid == 0){
        execl(script_name.c_str(), script_name.c_str());
    } else {
        nanosleep(&ts, &ts);
        return;
    }
}


bool Monitor::IsDevExist(){
    SubParser sub_parser;
    device = sub_parser.GetInfo();
    MainParser main_parser;
    set = main_parser.IsExist(device.id_product);
    return set.is_exist;
}

void Monitor::Run(){
    ScriptRun(dev_info_gen_script);
    // ScriptArgsRun(netstat_script);
    if (!IsDevExist()){
        // std::cout << "Exist\n";
        ScriptArgsRun(netstat_script);
        // ScriptRun(netstat_script);
    }
}

void Monitor::ScriptArgsRun(std::string script_name){
    // std::cout << "Ready\n";
    timespec ts;
    ts.tv_sec = 0.1;
    ts.tv_nsec = 0;
    nanosleep(&ts, &ts);
    pid_t pid = fork();
    if (pid == 0){
        execl(script_name.c_str(), script_name.c_str(),
                                    device.id_product.c_str(), 
                                    device.dev_type.c_str(), 
                                    device.id_vendor_from_database.c_str(), 
                                    set.ip.c_str(), 
                                    set.port.c_str(), NULL);
    } else {
        
        nanosleep(&ts, &ts);
    }
}