#include <memory>
#include <iostream>


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

    std::shared_ptr<Bar> pBar = std::make_shared<Bar>(1,2,3);
    pBar->dump();

    auto pFoo = pBar;

    // Change pBar to NULL
    std::cout << "Setting pBar = NULL\n";
    pBar = NULL;

    // Change pFoo to NULL, triggering deletion of instance
    std::cout << "Setting pFoo = NULL\n";
    pFoo = NULL;
    
}
