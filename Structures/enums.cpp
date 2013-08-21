#include <iostream>
#include <string>

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

// Alternate approach to bundling debug code with enum class
// Define to_string() for the enum class in a namespace and use
// Argument Dependent Lookup to find the to_string() in the Bar namespace
// supporting the Baz type

namespace Bar {
    enum class Baz : int { red,green,blue };

    std::string to_string(Baz baz) {
        switch(baz) {
        case Baz::red: return "Red";
        case Baz::green: return "Green";
        case Baz::blue: return "Blue";
        default: return "Invalid";
        }
    }
}


int main()
{
    Colors c = { Colors::red };

    std::cout << c << "\n";

    c = Colors::black;

    std::cout << c << "\n";

    Bar::Baz b = Bar::Baz::green;

    std::cout << to_string(b) << "\n";
}
