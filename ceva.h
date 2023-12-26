//
// Created by lazar on 25.12.2023.
//

#ifndef LIONUL_CEVA_H
#define LIONUL_CEVA_H
#include <iostream>
#include <numeric>
#include <algorithm>
class Fractie
{
private:
    int a , b;
public:
    const int get_numitor(){return a;}
    const int get_numarator(){return b;}
    void set_numitor(int value){a = value;}
    void set_numarator(int value){b = value;}
    void afiseaza()
    {
        std::cout << a << " " << b << "\n";
    }
    void simplifica()
    {
        int c = std::__gcd(a , b);
        a /= c;
        b /= c;
    }
    Fractie(int x = 0 , int y = 1) : a(x) , b(y) {}
    //~Fractie() {std::cout << "Distrus Mental \n" ;}

    //dam overloade la astea + - * /
    Fractie operator + (const Fractie& other_fractie) const;
    Fractie operator - (const Fractie& other_fractie) const;
    Fractie operator *(const Fractie& other_fractie) const;
    Fractie operator /(const Fractie& other_fractie) const;

    //dam overloade la += , -= , */ , /*
    Fractie operator +=(const Fractie& other_fractie);
    Fractie operator -=(const Fractie& other_fractie);
    Fractie operator *=(const Fractie& other_fractie);
    Fractie operator /=(const Fractie& other_fractie);
    //dam overloade la == , != , adica de tip bool
    bool operator==(const Fractie& other_fractie) const;
    bool operator!=(const Fractie& other_fractie) const;
    bool operator >(const Fractie& other_fractie) const;
    bool operator <(const Fractie& other_fractie) const;
    bool operator >=(const Fractie& other_fractie) const;
    bool operator <=(const Fractie& other_fractie) const;

    //dam overload la >> , <<
    friend std::istream& operator>>(std::istream& is, Fractie& fraction);
    friend std::ostream& operator<<(std::ostream& os, const Fractie& fraction);

    //facem valoare double
    operator double() const;

};
#endif //LIONUL_CEVA_H
