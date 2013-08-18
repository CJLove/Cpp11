#include <array>
#include <iostream>
#include <type_traits>
#include <cstring>		//memcpy


// Do the right thing regardless of whether T is a POD or not
template<typename T>
void mycopy(T* to, const T* from, int count)
{
    if (std::is_pod<T>::value)
        memcpy(to,from,count*sizeof(T));
    else
        for (int i = 0; i < count; ++i) {
            to[i] = from[i];
        }
}

int main()
{
    struct Point { int x; int y; };

    // array definition of 3 elts
    // Note that extra braces were required by gcc 4.8.1
    std::array<Point,3> points { { {1,1}, {2,2}, {3,3}}};

    for (auto &pt: points) {
        std::cout << "X: " << pt.x
                  << " Y: " << pt.y << "\n";
    }


    // Following structure is a POD, w/user-defined constructor and
    // default constructor
    // Data can be copied around w/o concerns about class layout
    // or user-defined semantics for construction
    struct S1 {
        int a;
        S1(int aa): a(aa)
        {}

        S1() = default;
    };

    S1 pod[10] { 1,2,3,4,5,6,7,8,9,10};

    S1 toPod[10] { 0,0,0,0,0,0,0,0,0,0};

    mycopy<S1>(toPod,pod,10);

    for (int i = 0; i < 10; ++i) {
        std::cout << toPod[i].a << " ";
    }
    std::cout << "\n";

    // Not a POD since there is no default constructor
    struct S2 {
        int a;
        S2(int aa): a(aa)
        {}

        S2() = delete;
    };

    S2 nonPod[10] { 1,2,3,4,5,6,7,8,9,10};
    S2 toNonPod[10] { 0,0,0,0,0,0,0,0,0,0};


    mycopy<S2>(toNonPod,nonPod,10);
    for (int i = 0; i < 10; ++i) {
        std::cout << toNonPod[i].a << " ";
    }
    std::cout << "\n";
        

}
