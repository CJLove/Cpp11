#ifndef pimpl_hpp
#define pimpl_hpp

#include <memory>

class MyClass {
public:
    MyClass(const int a, const int b, const int c);

    virtual ~MyClass();

    int operation(int a, int b, int c, int d);

private:
    struct impl;
    std::unique_ptr<impl> pimpl;
};

#endif
