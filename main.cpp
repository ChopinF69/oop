#include <iostream>
#include "main.h"
int main()
{
    Student s;
    //s.set_course();
    s.display_student();
    Person p , p1 , p2(69 , "liga");
    p.set_Person(1 , "abc");
    p.display_person();
    p1.display_person();
    p2.display_person();
}