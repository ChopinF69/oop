#include <iostream>
#include "stiva.h"
#include <cstring>
#include <string>
using namespace std;
template<typename T>
T minim(T , T);

template<class T>
void sort(T , int);

int main() {
    std::string s1("Ana are mere") , s2("Anadrol");
    int i1 = 2 , i2 = 9;
    double x1 = 2.234 , x2 = 2.192;
    std::cout << minim(s1 , s2) << "\n";
    std::cout << minim(i1 , i2) << "\n";
    std::cout << minim(x1 , x2) << "\n";

    int array[] = {5 , 3 , 6};
    sort(array , 3);
    size_t sizeArray = sizeof(array)/ sizeof(array[0]);
    for(int i = 0 ; i < sizeArray ; ++i)
        std::cout << array[i] << " ";
    std::cout << "\n";
    Stiva<int> S;
    std::string comanda , stop = "0";
    std::cout << "Introdu comanda : ";
    std::cin >> comanda;
    while(comanda != stop)
    {

        //size_t commandSize = sizeof(comanda);
        //std::cout << commandSize << "\n";

        if(comanda.find("PUSH") != std::string::npos)
        {
            std::cin >> comanda;
            std::string number_to_be_formed = "";
            for(int i = 0 ; comanda[i] ; ++i)
                number_to_be_formed += comanda[i];

            //std::cout << number_to_be_formed << "\n";
            int number = std::stoi(number_to_be_formed);
            std::cout << number << "\n";
            S.Push(number);
            //int number = std::stoi(comanda , 5 , commandSize - 1);
        }
        else if(comanda.find("STORE") != std::string::npos)
        {
            int number_to_display = S.Pop();
            std::cout << "Numarul din vf stivei : " << number_to_display << "\n";
        }
        else if(comanda.find("GOALA") != std::string::npos)
        {
            bool is_empty = S.empty();
            if(is_empty)std::cout << "E goala";
            else std::cout << "Nu e goala";
            std::cout << "\n";
        }

        std::cin >> comanda;
    }
    return 0;
}
template<typename T>
T minim(T x, T y)
{
    if(x < y)return x;
    return y;
}
template<class T>
void sort(T array , int length)
{
    for(int i = 0 ; i < length - 1; ++i)
    {
        for(int j = i + 1 ; j < length; ++j)
            if(array[i] > array[j])swap(array[i] , array[j]);
    }
}
