#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
    switch (rand() % 3) {
    case 0:
        std::cout << "Obj type A" << std::endl;
        return new A();
    case 1:
        std::cout << "Obj type B" << std::endl;
        return new B();
    case 2:
        std::cout << "Obj type C" << std::endl;
        return new C();
    }
    return 0;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Ptr is type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Ptr is type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Ptr is type C" << std::endl;
    else
        std::cout << "Ptr is unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        Base &ref = dynamic_cast<A&>(p);
        (void) ref;
        std::cout << "Ref is type A" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        Base &ref = dynamic_cast<B&>(p);
        (void) ref;
        std::cout << "Ref is type B" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        Base &ref = dynamic_cast<C&>(p);
        (void) ref;
        std::cout << "Ref is type C" << std::endl;
    }
    catch(const std::exception& e) {}
}

int main()
{
    for (size_t i = 0; i < 6; i++) {
        Base *p = generate();
        identify(p);
        identify(*p);
        std::cout << std::endl;
        delete p;
    }
}