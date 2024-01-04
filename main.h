//
// Created by lazar on 03.01.2024.
//

#ifndef MOSTENIRE_MAIN_H
#define MOSTENIRE_MAIN_H
#include <string>
#include <iostream>
#include <cstring>
#pragma once
class Person
{
private:
    int id;
    char name[100];
public:
    Person();
    Person(int id , char *);
    void set_Person();
    void set_Person(int , char *);
    void display_person();

};
Person::Person()
{
    this->id = 0;
    std::strcpy(this->name , "");
}
Person::Person(int id, char *s)
{
    this->id = id;
    std::strcpy(this->name , s);
}
void Person::set_Person()
{
    std::cout << "Enter the id : ";
    std::cin >> id;
    std::cout << "Enter the name : ";
    std::cin >> name;
}
void Person::set_Person(int id, char *s)
{
    this->id = id;
    std::strcpy(this->name , s);
}
void Person::display_person()
{
    std::cout << "id : " << id << " name : " << name;
    std::cout << "\n";
}
class Student : private Person
{
private:
    char course[50];
    int fee;
public:
    //Student() : Person() {};

    void set_course();

    void display_student();
};
Student::Student() : Person()
{
    this->fee = 0;
    std::strcpy(course , "");
}
void Student::set_course()
{
    set_Person();
    std::cout << "Enter the Course : ";
    std::cin >> course;
    std::cout << "Enter the Course fee : ";
    std::cin >> fee;
}
void Student::display_student()
{
    display_person();
    std::cout << "Course : " << course << " fee of the course : " << fee;
    std::cout << "\n";
}
#endif //MOSTENIRE_MAIN_H
