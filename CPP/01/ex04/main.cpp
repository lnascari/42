#include <iostream>
#include <fstream>
#include <sstream> 

int main(int argc, char const *argv[])
{
    if (argc != 4 || std::string(argv[2]).empty()) {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::fstream ifile;
    ifile.open(argv[1], std::ios::in);
    if (!ifile) {
        std::cout << "Invalid file" << std::endl;
        return 1;
    }
    std::stringstream buf;
    buf << ifile.rdbuf();
    ifile.close();
    std::string istr = buf.str();
    std::string ostr = "";
    for (size_t i = 0; i < istr.length(); i++) {
        if (i == istr.find(s1, i)) {
            ostr += s2;
            i += s1.length() - 1;
        } else {
            ostr += istr[i];
        }
    }
    std::fstream ofile;
    ofile.open((std::string(argv[1]) + ".replace").c_str(), std::ios::out | std::ios::trunc);
    ofile << ostr;
    ofile.close();
    return 0;
}
