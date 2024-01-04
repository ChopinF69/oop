//
// Created by lazar on 26.12.2023.
//

#ifndef BIGINT_MAIN_H
#define BIGINT_MAIN_H

#define LGMAX 1000 //maxim 1000 de cifre poate sa aiba numarul
/*
 * Constructor
 * Destructor
 * Operatori aritmetici
 * Operatori de tip bool
 * Operatori de tip istream
 *
 */
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
class BigInt
{
private:
    std::string digits;
public:
    const std::string& get_digits() const
    {
        return digits;
    }
    //Constructors
    BigInt(unsigned long long);
    BigInt(std::string &);
    BigInt(const char *);
    BigInt(BigInt &);
    BigInt(const BigInt &);
    BigInt();
    //direct
    BigInt &operator=(const BigInt &);
    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int )const;
    //Post/pre incrementation
    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);

    //Aditie substractie
    friend BigInt &operator+=(BigInt& , const BigInt&);
    friend BigInt operator+(const BigInt & , const BigInt &);
    friend BigInt &operator-=(BigInt& , const BigInt&);
    friend BigInt operator -(const BigInt & , const BigInt &);

    //comparatori - bool
    friend bool operator==(const BigInt & , const BigInt &);
    friend bool operator!=(const BigInt & , const BigInt &);

    friend bool operator>(const BigInt & , const BigInt &);
    friend bool operator>=(const BigInt & , const BigInt &);
    friend bool operator<(const BigInt & , const BigInt &);
    friend bool operator<=(const BigInt & , const BigInt &);

    //multiplicari impartiri
    friend BigInt &operator*=(BigInt& , const BigInt &);
    friend BigInt operator*(const BigInt & , const BigInt &);
    friend BigInt &operator/=(const BigInt & , const BigInt &);
    friend BigInt operator/(const BigInt & , const BigInt &);

    //modulo
    friend BigInt operator%(const BigInt & , const BigInt &);
    friend BigInt &operator%=(BigInt & , const BigInt &);

    //power function
    friend BigInt operator^(const BigInt & , const BigInt &);
    friend BigInt &operator^=(BigInt & , const BigInt &);

    //read and write
    friend std::istream &operator>>(std::istream & , BigInt &);
    friend std::ostream &operator<<(std::ostream & , const BigInt &);

    //Others
    friend BigInt nThCatalan(int n);
    friend BigInt nThFibonacci(int n);
    friend BigInt Factorial(int n);
};
BigInt::BigInt()
{
    digits = "";
}
BigInt::BigInt(std::string &s) {
    digits = "";
    int length = s.size();
    if (length == 0)throw ("Nu poate fi NIMIC");

    for (int i = length - 1; i >= 0; --i) {
        if (!isdigit(s[i]))
            throw ("Ai bagat ceva ce nu e cifra");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(unsigned long long nr)
    {
        do
        {
            digits.push_back(nr % 10);
            nr /= 10;
        }while(nr);
    }
BigInt::BigInt(const char *s)
{
    digits = "";
    for(int i = strlen(s) - 1 ; i >= 0 ; --i)
    {
        if(!isdigit(s[i]))
        {
            throw("NU E CIFRA");
        }
        else digits.push_back(s[i]);
    }
}
BigInt::BigInt(BigInt &a)
{
    digits = a.digits;
}
BigInt::BigInt(const BigInt &a)
{
    digits = a.digits;
}
bool Null(const BigInt& a)
{
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

int Length(const BigInt& a)
{
    return a.digits.size();
}
int BigInt::operator[](const int index) const
{
    if(digits.size() <= index || index < 0 )
        throw("NU E BUN INDEXUL , PREA MIC SAU MARE");
    return digits[index];
}
bool operator==(const BigInt& a , const BigInt& b)
{
    return a.digits == b.digits;
}
bool operator!=(const BigInt& a , const BigInt &b)
{
    return !(a == b);//deja definit xd
}
bool operator<(const BigInt& a , const BigInt &b)
{
    int l1 = Length(a) , l2 = Length(b);
    if(l1 != l2)return l1 < l2;

    for(int i = l1 - 1 ; i >= 0 ; --i)
    {
        if(a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i];
    }
    return false;
}
bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}
bool operator>=(const BigInt &a , const BigInt &b)
{
    return !(a < b);// !< == >=
}
bool operator<=(const BigInt &a , const BigInt &b)
{
    return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a)
{
    digits = a.digits;
    return *this;
}
BigInt &BigInt::operator++()
{
    int l = digits.size() , i;
    for(i = 0 ; i < l && digits[i] == 0 ; ++i)
        digits[i] = 0;
    if(i == l)digits.push_back(1);
    else digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp)
{
    for(int i = 0 ; i < temp ; ++i)
        ++(*this);
    BigInt aux(*this);
    return aux;
}
BigInt &BigInt::operator--()
{
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");

    int i , l = digits.size();
    for(i = 0 ; digits[i] == 0 && i < l ; ++i)
        digits[i] = 9;

    digits[i]--;
    if(l > 1 && digits[l - 1] == 0)digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp)
{
    for(int i = 0 ; i < temp ; ++i)
        --(*this);
    BigInt aux(*this);
    return aux;
}
BigInt &operator+=(BigInt &a , const BigInt& b)
{
    int t = 0 , s , i;
    int l1 = Length(a) , l2 = Length(b);
    if(l2 > l1)
    {
        a.digits.append(l2 - l1 , 0);
    }
    l1 = Length(a);
    for(i = 0 ; i < l1 ; ++i)
    {
        if(i < l2)
        {
            s = (a.digits[i] + b.digits[i]) + t;
        }
        else s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt& a , const BigInt& b)
{
    BigInt temp(a);
    temp += b;
    return temp;
}
BigInt &operator-=(BigInt &a , const BigInt& b)
{
    if(a < b)throw("UNDERFLOW");
    int l1 = Length(a) , l2 = Length(b);
    int i , t = 0 , s;
    for(i = 0 ; i < l1 ; ++i)
    {
        if(i < l2)
            s = a.digits[i] - b.digits[i];
        else s = a.digits[i] + t;

        if(s < 0)
        {
            s += 10;
            t -= 1;
        }
        else t = 0;
        a.digits[i] = s;
    }
    while(l1 > 1 && a.digits[l1 - 1] == 0)
        a.digits.pop_back(),l1--;
    return a;
}
BigInt operator-(const BigInt &a , const BigInt &b)
{
    BigInt temp(a);
    temp -= b;
    return temp;
}
BigInt &operator*=(BigInt &a , const BigInt &b)
{
    if(Null(a) or Null(b))
    {
        a = BigInt();
        return a;
    }
    int l1 = a.digits.size() , l2 = b.digits.size();
    std::vector<int>v(l1 + l2 , 0);
    for(int i = 0 ; i < l1 ; ++i)
    {
        for(int j = 0 ; j < l2 ; ++j)
            v[i + j] += (a.digits[i]) * (b.digits[j]);
    }

    l1 += l2;
    a.digits.resize(v.size());

    for(int s,i = 0,t = 0 ; i < l1 ; ++i)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }
    for(int i = l1 - 1 ; i >= 1 && !v[i];--i)
    {
        a.digits.pop_back();
    }
    return a;

}
BigInt operator*(const BigInt& a , const BigInt& b)
{
    BigInt temp(a);
    temp *= b;
    return temp;
}

#endif //BIGINT_MAIN_H
