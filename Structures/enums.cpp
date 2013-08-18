#include <iostream>

// Enum class definition
enum class Colors : int { red, green, blue, yellow, brown, black };

// Overload output operator for enum class
std::ostream & operator<<(std::ostream & os, const Colors &color)
{
    switch (color) {
    case Colors::red:
        os << "red"; break;
    case Colors::green:
        os << "green"; break;
    case Colors::blue:
        os << "blue"; break;
    case Colors::yellow:
        os << "yellow"; break;
    case Colors::brown:
        os << "brown"; break;
    case Colors::black:
        os << "black"; break;
    }
    os << "[" << static_cast<int>(color)<<"]";
    return os;
}

class Foo {
public:
    // Unnamed enum to define set of integer constants
    enum { val1=1, val2=2, val3=3 };

};


int main()
{
    Colors c = { Colors::red };

    std::cout << c << "\n";

    c = Colors::black;

    std::cout << c << "\n";
}
