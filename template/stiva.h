//
// Created by lazar on 04.01.2024.
//

#ifndef TEMPLATE_STIVA_H
#define TEMPLATE_STIVA_H
#define SMAX 1000 // buffer pt stiva
#include <iostream>
//vom face o stiva de obiecte xd
template<typename T>
class Stiva
{
protected:
    int varf;
    T array[SMAX];
public:
    //constructori
    Stiva(){varf = -1;}
    T& Top()
    {
        std::logic_error e("Stiva vida");
        if(varf < 0)throw e;
        return array[varf];
    }
    T Pop()
    {
        std::logic_error e("Stiva vida");
        if(varf < 0 )throw e;
        return array[varf--];
    }
    void Push(const T& new_obj)
    {
        std::logic_error e("Stiva plina");
        if(varf > 1000)throw e;
        array[++varf] = new_obj;
    }
    bool empty(){return (varf == -1);}
    int size(){return varf + 1;}
};

#endif //TEMPLATE_STIVA_H
