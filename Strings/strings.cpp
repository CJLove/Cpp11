//
// String operations
//
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string s = "abcdefghijklmnopqrstuvwxyz";

    cout << s << "\n";

    cout << "substr(10,15) = " << s.substr(10,15) << "\n";

    cout << "replace(0,1,\"ABCDEFGHIJK\") = " << s.replace(0,1,"ABCDEFGHIJK") << "\n";
    
    string f = "abc";

    if (f == s.substr(0,3)) {
        cout << "Match\n";
    } else {
        cout << "No match\n";
    }

}
