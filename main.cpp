//
// Created by lazar on 25.12.2023.
//

#include "ceva.h"

Fractie Fractie::operator+(const Fractie &other_fractie) const
{
    Fractie rezultat;
    rezultat.a = a * other_fractie.b + b * other_fractie.a;
    rezultat.b = b * other_fractie.b;
    rezultat.simplifica();

    return rezultat;
}
Fractie Fractie::operator-(const Fractie &other_fractie) const
{
    Fractie rezultat;
    rezultat.a = a * other_fractie.b - b * other_fractie.a;
    rezultat.b = b * other_fractie.b;
    rezultat.simplifica();

    return rezultat;
}
Fractie Fractie::operator/(const Fractie &other_fractie) const
{
    Fractie rezultat;
    rezultat.a = a * other_fractie.b;
    rezultat.b = b * other_fractie.a;

    rezultat.simplifica();
    return rezultat;
}
Fractie Fractie::operator*(const Fractie &other_fractie) const
{
    Fractie rezultat;
    rezultat.a = a * other_fractie.a;
    rezultat.b = b * other_fractie.b;
    rezultat.simplifica();
    rezultat.simplifica();
    return rezultat;
}

//---------------------------------------------------------------------------------------------------------------
Fractie Fractie::operator+=(const Fractie &other_fractie) {
    a += other_fractie.a;
    b += other_fractie.b;
    this->simplifica();
    return *this;
}
Fractie Fractie::operator-=(const Fractie &other_fractie)
{
    a -= other_fractie.a;
    b -= other_fractie.b;
    this->simplifica();
    return *this;
}
Fractie Fractie::operator*=(const Fractie &other_fractie)
{
    a = a * other_fractie.b + b * other_fractie.a;
    b = b * other_fractie.b;
    this->simplifica();
    return *this;
}
Fractie Fractie::operator/=(const Fractie &other_fractie)
{
    a = a * other_fractie.b;
    b = b * other_fractie.a;
    this->simplifica();
    return *this;
}
//----------------------------------------------------------------------------------------------------
//aici vom face cei de tip bool , == , != , > , < , >= , <=
bool Fractie::operator==(const Fractie &other_fractie) const
{
    return (a == other_fractie.a && b == other_fractie.b);
}
bool Fractie::operator!=(const Fractie & other_fractie) const
{
    return (a != other_fractie.a || b != other_fractie.b);
}
bool Fractie::operator>(const Fractie &other_fractie) const
{
    if(a > other_fractie.a)return true;
    else if(b < other_fractie.b && a == other_fractie.a)return true;
    else return false;
}
bool Fractie::operator<(const Fractie &other_fractie) const
{
    if(a < other_fractie.a)return true;
    else if(b > other_fractie.b && a == other_fractie.a)return true;
    else return false;
}
bool Fractie::operator>=(const Fractie &other_fractie) const
{
    if(a > other_fractie.a)return true;
    else if(b <= other_fractie.b && a == other_fractie.a)return true;
    else return false;
}
bool Fractie::operator<=(const Fractie &other_fractie) const
{
    if(a < other_fractie.a)return true;
    else if(b >= other_fractie.b && a == other_fractie.a)return true;
    else return false;
}
//------------------------------------------------------------------------------------------------
//citire si afisare , adica >> , <<
std::istream& operator>>(std::istream& in , Fractie& fractie_citita)
{
    int x , y;
    std::cout << "Ce fractie sa fie ? ";
    in >> x >> y;
    fractie_citita.a = x;
    fractie_citita.b = y;
}
std::ostream& operator<<(std::ostream& out , Fractie& fractie_afisata)
{
    int x = fractie_afisata.get_numitor() , y = fractie_afisata.get_numarator();
    out << x << " " << y << "\n";
}
//--------------------------------------------------------------------------------
//sa obtinem un double dintr-o fractie
Fractie::operator double() const
{
    return (double )(a / b);
}
signed main()
{
    Fractie f1(1 , 3) , f2(2 , 3);

    std::cout << "Prima fractie este : ";
    f1.afiseaza();

    std::cout << "A doua fractie este : ";
    f2.afiseaza();

    Fractie f_suma = f1 + f2;
    std::cout << "Suma fractiilor este = " ;
    f_suma.afiseaza();


    Fractie f_diferenta = f1 - f2;
    std::cout << "Diferenta fractiilor este : ";
    f_diferenta.afiseaza();

    Fractie f_produs = f1 * f2;
    std::cout << "Produsul fractiilor este : ";
    f_produs.afiseaza();

    Fractie f_impartire = f1 / f2;
    std::cout << "Impartirea fractiilor este : ";
    f_impartire.afiseaza();

    Fractie f_suma_atribuire(0 , 69);
    f_suma_atribuire += f1;
    f_suma_atribuire += f2;
    std::cout <<"Suma atribuire : ";
    f_suma_atribuire.afiseaza();

    Fractie f_diferenta_atribuire(0 , 120);
    f_diferenta_atribuire -= f1;
    f_diferenta_atribuire -= f2;
    std::cout << "Diferenta atribuire : ";
    f_diferenta_atribuire.afiseaza();

    Fractie f_egal_1(2 , 2) ,f_egal_2(2 , 2);
    std::cout << "Afisam daca sunt egale : ";
    bool ok = f_egal_1 == f_egal_2;
    std::cout << ok << "\n";

    Fractie f_egal_3(2 , 1) ,f_egal_4(2 , 2);
    std::cout << "Afisam daca sunt egale : ";
    bool ok2 = f_egal_3 == f_egal_4;
    std::cout << ok2 << "\n";

    Fractie f_diferit_1(2 , 1) ,f_diferit_2(2 , 2);
    std::cout << "Afisam daca sunt diferite : ";
    bool ok3 = f_diferit_1 != f_diferit_2;
    std::cout << ok3 << "\n";

    Fractie f_diferit_3(2 , 1) ,f_diferit_4(2 , 1);
    std::cout << "Afisam daca sunt diferite : ";
    bool ok4 = f_diferit_3 != f_diferit_4;
    std::cout << ok4 << "\n";

    Fractie f_mare_1 (2 , 1) , f_mic_1 (1 , 1);
    std::cout << "Afisam daca prima e mai mare strict ca a doua ";
    bool ok5 = f_mare_1 > f_mic_1;
    std::cout << ok5 << "\n";

    std::cout << "Afisam daca prima e mai mica ca a doua : ";
    bool ok6 = f_mare_1 < f_mic_1;
    std::cout << ok6 << "\n";

    Fractie fractie_citita;
    std::cin >> fractie_citita;
    std::cout << fractie_citita;

    double numar = fractie_citita;
    std::cout << numar;
}
