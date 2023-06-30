#include "Harl.hpp"

int main()
{
    Harl harl;
    harl.complain("info");
    harl.complain("debug");
    harl.complain("error");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("warning");
    harl.complain("debug");
    harl.complain("error");
    harl.complain("info");
}