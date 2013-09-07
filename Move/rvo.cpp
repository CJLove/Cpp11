#include <iostream>
struct Verbose {
  Verbose() { std::cout << "default ctor\n"; }
  Verbose( Verbose const& ){ std::cout << "copy ctor\n"; }
  Verbose( Verbose && ){ std::cout << "move ctor\n"; }
  Verbose& operator=( Verbose const& ){ std::cout << "copy asgn\n"; }
  Verbose& operator=( Verbose && ){ std::cout << "move asgn\n"; }
};

// Direct construction of return value
//Verbose simple() { return {}; }

// Simple RVO
Verbose simple_RVO() { return Verbose(); }

// Simple NRVO
Verbose simple_NRVO() {
   Verbose retval;
   return retval;
}

Verbose simple_no_NRVO(bool b) {
   Verbose retval1;
   Verbose retval2;
   if (b)
     return retval1;
   else
     return retval2;
 }

int main()
{
    std::cout << "Calling simple_RVO\n";
    Verbose v = simple_RVO(); // or simple_RVO, or simple_NRVO, or...

    std::cout << "Calling simple_NRVO\n";
    Verbose vv = simple_NRVO();

    std::cout << "Calling simple_no_NRVO(true)\n";
    Verbose vvv = simple_no_NRVO(true);

    std::cout << "Calling simple_no_NRVO(false)\n";    
    Verbose vvvv = simple_no_NRVO(false);

}
