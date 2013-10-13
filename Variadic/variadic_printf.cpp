//
// main.cpp
// printf
// A crude but safe printf in C++11.
// Created by Sourav Datta on 17/05/13.
// Copyright (c) 2013 Sourav Datta. All rights reserved.
//
 
#include <iostream>
#include <string>
 
// The inner print1 definition
// a print1 with only format argument, print whatever it gets
const std::string print1(const std::string& just_fmt)
{
    std::cout << just_fmt;
    return "";
}
 
// this version takes a format string and a param to print it
template <class T>
const std::string print1(const std::string& fmt, const T& elem)
{
    for (int i = 0; i < fmt.length(); i++) {
        if (fmt[i] == '%') {
            if ((i == 0) ||
                ((i > 0) && (fmt[i] != '\\'))) {
                i += 2;
                std::cout << elem;
                return fmt.substr(i);
            }
        }
        std::cout << fmt[i];
    }
    return "";
}
 
// now comes C++11
template <class T, class... Rest>
const std::string print1(const std::string& fmt, const T& elem, const Rest&... rest)
{
    std::string rem = print1(fmt, elem);
    if (rem != "")
        return print1(rem, rest...);
    else
        return "";
}
 
 
// The wrapper
void print(const std::string& fmt)
{
    print1(fmt);
}
 
template <class... Rest>
void print(const std::string& fmt, const Rest&... rest)
{
    std::string rem = print1(fmt, rest...);
    if (rem != "")
        print1(rem);
}
 
int main(int argc, const char * argv[])
{
    print("hello, world\n");
    print("this is the new brave world%s", '\n');
    print("hello %f %f|%g|%y,%g worlds", 67, "big", "crazy", "yellow", "green");
    return 0;
}
