#include <iostream>
#include <vector>
#include <algorithm>

double foo(int a, int c)
{
    return static_cast<double>(a/c);
}

class Foo {
public:

    static Foo &instance();

    int doSomething() const;

private:
    Foo(int a);

    ~Foo();

    int m_a;
    
    static Foo *inst;
};

Foo * Foo::inst = NULL;

Foo &
Foo::instance()
{
    if (nullptr == inst) {
        inst = new Foo(10);
    }
    return *inst;
}

Foo::Foo(int a): m_a(a)
{}

Foo::~Foo()
{}

int
Foo::doSomething() const
{
    return m_a;
}

int main(int argc, char **argv)
{
    if (argc > 0) {
        std::cout << argv[0] << '\n';
    }
    
    // Scalar type
    auto d = foo(10,4);
    d += 2.4;

    std::cout << d << '\n';
        

    // container type
    std::vector<int> g;
    g.push_back(4);
    g.push_back(3);
    g.push_back(2);
    g.push_back(1);

    //    auto i = g.begin();
    auto i = begin(g);
    //    auto e = g.end();
    auto e = end(g);
    for (; i != e; ++i) {
        std::cout << *i << " ";
    }
    std::cout << '\n';

    // Reference
    auto &f = Foo::instance();

    std::cout << f.doSomething() << '\n';

    // for
    int total = 0;
    for (auto d: g) {
        total += d;
    }

    std::cout << total << '\n';

    // begin(), end()
    sort(begin(g),end(g));

    // 
    for (auto dd: g) {
        std::cout << dd << " ";
    }
    std::cout << '\n';
        
    
}
