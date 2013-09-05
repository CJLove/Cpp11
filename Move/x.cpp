#include <iostream>
#include <algorithm>
#include "x.hpp"

x::x(int a, int b, int cSize, int *c): m_a{a}, m_b{b}, m_cSize{cSize},m_c{ new int[cSize]}
{
    std::copy(c,c+cSize,m_c);
    std::cout << "Ctor\n";
}

x::~x()
{
    std::cout << "Dtor\n";
    delete [] m_c;
    m_c = nullptr;
}

std::ostream &operator<<(std::ostream &os, const x &theX)
{
    os << "X: m_a=" << theX.m_a << " m_b=" << theX.m_b << " m_cSize=" << theX.m_cSize << "{ ";

    for (int i = 0; i < theX.m_cSize; ++i) {
        os << " " << theX.m_c[i];
    }
    os << "}\n";
    return os;
}

x::x(const x &rhs): m_a{rhs.m_a}, m_b{rhs.m_b}, m_cSize{rhs.m_cSize},m_c{new int [rhs.m_cSize]}
{
    std::cout << "Copy Ctor\n";
    std::copy(rhs.m_c,rhs.m_c+rhs.m_cSize,m_c);
}

x & x::operator=(const x &rhs)
{
    std::cout << "Copy assignment\n";
    //    x tmp{rhs};
    //    std::swap(tmp,*this);
    m_a = rhs.m_a;
    m_b = rhs.m_b;
    m_cSize = rhs.m_cSize;
    delete [] m_c;
    m_c = new int[rhs.m_cSize];
    std::copy(rhs.m_c,rhs.m_c+rhs.m_cSize,m_c);    

    return *this;
}

x::x(x &&rhs): m_a{rhs.m_a},m_b{rhs.m_b},m_cSize{rhs.m_cSize},m_c{std::move(rhs.m_c)}
{
    rhs.m_c = nullptr;
}

x bar(x xArg)
{
    int v [] = { 2,4,6,8,10,12,14,16,18,20 };
    x y(5,5,10,v);
    
    std::cout << "In bar(): " << xArg;

    std::cout << "Returning move of local y\n";
    return y;
}

int main(int argc, char **argv)
{
    int values [] = { 1,2,3,4,5,6,7,8,9,10};

    int moreValues[] = { 10, 9, 8, 7,6,5,4,3,2,1 };

    x theX(1,2,10,values);

    std::cout << "theX " << theX;

    std::cout << "copy constructing theCopy\n";
    x theCopy(theX);

    std::cout << "theCopy " << theCopy;

    std::cout << "constructing foo\n";
    x foo(2,3,10,moreValues);

    std::cout << "foo " << foo;

    std::cout << "copy assigning to foo\n";
    foo = theX;

    std::cout << "foo (after assignment) " << foo;

    std::cout << "Passing theX by value to bar()\n";

    theX = bar(theX);

    std::cout << "Ending program\n";

}
