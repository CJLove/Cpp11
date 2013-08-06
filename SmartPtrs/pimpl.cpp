#include "pimpl.hpp"
#include "memory.hpp"
#include <iostream>

struct MyClass::impl {
    impl(const int a, const int b, const int c): m_a(a),m_b(b),m_c(c)
    {};

    ~impl()
    {
        std::cout << "Destructing MyClass::impl" << '\n';
    }

    int m_a;
    int m_b;
    int m_c;
};

MyClass::MyClass(const int a, const int b, const int c):
    pimpl{ std::make_unique<impl>(a,b,c) }
{}

MyClass::~MyClass()
{
    std::cout << "Destructing MyClass" << '\n';    
}


int
MyClass::operation(int a, int b, int c, int d)
{
    pimpl->m_a = a;
    pimpl->m_b = b;
    pimpl->m_c = c;

    std::cout << "operation(" << a << b << c << d << ")\n";
    return 0;
}

int main(int argc, char **argv)
{
    {
        std::cout << "Declaring MyClass instance on stack\n";

        MyClass m(1,2,3);

        std::cout << "MyClass instance going out of scope\n";
    }


    std::cout << "Exiting main()\n";
}
    

