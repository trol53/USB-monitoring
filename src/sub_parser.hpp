#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

struct Dev{
    std::string id_product;
    std::string dev_type;
    std::string id_vendor_from_database;
};

class SubParser {

public:

    SubParser();
    Dev GetInfo();

private:

    std::string file_name = "/home/Trol53/diploma/file.txt";
    std::ifstream file;
    Dev device;

};