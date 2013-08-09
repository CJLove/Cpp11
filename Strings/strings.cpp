//
// String operations
//
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename C, typename V>
vector<typename C::iterator> find_all(C &c, V v)
{
    vector<typename C::iterator> res;
    for (auto p = c.begin(); p!= c.end(); ++p) {
        if (*p == v) res.push_back(p);
    }
    return res;
}

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

    string g { "abc123abc666abc" };

    for (auto p: find_all(g,'a') ) {
        if (*p != 'a')
            cout << "Bug!\n";
    }
    cout << "Done\n";

    list<double> ld { 1.1, 2.2, 3.3, 4.4, 5.5 };
    for (auto p: find_all(ld, 1.1)) {
        if (*p != 1.1) {
            cout << "Double bug\n";
        }
    }
    cout << "Double done\n";

    vector<string> vs { "red", "green", "green", "orange", "red" };
    for (auto p: find_all(vs, "green")) {
        if (*p != "green" ) {
            cout << "String bug\n";
        }
    }
    cout << "String done\n";

}
