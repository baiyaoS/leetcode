#include <iostream>
#include <string.h>
#include <map>

int main()
{
    // std::string s = "ejheuhgf";
    std::cout << '0'-0 << std::endl;
    std::cout << "Hello World" << std::endl;

    std::map<int, char> code;
    for (int i=0; i<26; ++i){
        code[i]=i+65;
        std::cout << code[i] << std::endl;
    }
}