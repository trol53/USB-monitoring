#include <unistd.h>
#include <ctime>
#include <string>
#include "main_parser.hpp"
#include "sub_parser.hpp"

class Monitor{

public:

    Monitor(){};

    void ScriptRun(std::string script_name);
    void ScriptArgsRun(std::string script_name);
    bool IsDevExist();
    void Run();

private:
    std::string dev_info_gen_script = "/home/Trol53/diploma/script.sh";
    std::string netstat_script = "/home/Trol53/diploma/script1.sh";
    Dev device;
    Settings set;

};