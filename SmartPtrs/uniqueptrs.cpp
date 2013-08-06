#include <memory>
#include <iostream>
#include "memory.hpp"

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args && ...args)
{
    return std::unique_ptr<T>( new T(std::forward<Args>(args)...));
}

class Bar {
public:
    Bar(int a, int b, int c);

    ~Bar();

    void dump();

private:
    int m_a;
    int m_b;
    int m_c;
};

Bar::Bar(int a, int b, int c): m_a(a),m_b(b),m_c(c)
{
}

Bar::~Bar()
{
    std::cout << "Destructing Bar instance" << '\n';
}

void
Bar::dump()
{
    std::cout << m_a << " " << m_b << m_c << '\n';
}

int main(int argc, char **argv)
{
    if (argc > 0) {
        std::cout << argv[0] << '\n';
    }

    {
        std::unique_ptr<Bar> pBar = std::make_unique<Bar>(1,2,3);
        pBar->dump();

        // pBar goes out of scope
        std::cout << "pBar goes out of scope\n";
    }
}
    
