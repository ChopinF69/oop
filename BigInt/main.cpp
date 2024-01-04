//
// Created by lazar on 26.12.2023.
//

#include "main.h"
#include <iostream>
int main()
{
    int array[] = {1 , 2 , 3 , 4 , 5};
    std::vector<int>V;
    for(int i = 1 ; i <= 1000 ; ++i)
        V.push_back(i);
    size_t sizeV = V.size();
    std::cout << sizeV << "\n";
    size_t size = sizeof(array);
    std::cout << size << "\n";

    std::string s1("1234") , s2("235");
    size_t found = s1.find(s2);
    std::cout << found;
}