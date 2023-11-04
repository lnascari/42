#include <cstdlib>
#include <time.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
    srand((unsigned)time(0));
    switch (rand() % 3) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }   
}

void identify(Base *p)
{

}

void identify(Base &p)
{

}

int main()
{
    for (size_t i = 0; i < 6; i++) {
        Base *p = generate();
        identify(p);
        identify(*p);
        delete p;
    }
}