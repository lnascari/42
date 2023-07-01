#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    Harl harl;
    std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int c = -1;
    for (size_t i = 0; i < 4; i++) {
        if (argv[1] == s[i])
            c = i;
    }
    switch (c) {
    case 0:
        std::cout << "[DEBUG]" << std::endl;
        harl.complain("DEBUG");
    case 1:
        std::cout << "[INFO]" << std::endl;
        harl.complain("INFO");
    case 2:
        std::cout << "[WARNING]" << std::endl;
        harl.complain("WARNING");
    case 3:
        std::cout << "[ERROR]" << std::endl;
        harl.complain("ERROR");
        break;
    default:
        std::cout << "[DEFAULT]" << std::endl;
        break;
    }
    return 0;
}
