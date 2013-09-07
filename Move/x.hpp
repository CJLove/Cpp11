#pragma once

#include <iosfwd>

class x {
public:
    friend std::ostream &operator<<(std::ostream &os, const x &theX);
    
    // Constructor
    x(int a, int b, int cSize, int* c);

    // Copy constructor
    x(const x &rhs);

    // Move constructor
    x(x && rhs);

    // Destructor
    ~x();

    // Copy assignment
    x &operator= (const x &rhs);

    // Move assignment
    x &operator= (x &&rhs);

private:
    int m_a;
    int m_b;
    int m_cSize;
    int *m_c;
};

std::ostream &operator<<(std::ostream &os, const x &theX);

    
