#ifndef BASE_H       
#define BASE_H
#include <iostream>
#include <cstring> 
using namespace std;
class Base{
protected:
    char* name;

public:
    Base();
    Base(const char* n);
    Base(const Base& other);
    virtual ~Base();
    // Функция, которая выводит информацию (не меняет объект → const)
    virtual void print() const = 0;

    // Функция, которая считывает данные (меняет объект → без const)
    virtual void input() = 0;

    // Функция, которая создаёт копию объекта (возвращает указатель на Base)
    virtual Base* clone() const = 0;

    // Функция, которая возвращает тип объекта строкой
    virtual const char* getType() const = 0;
    const char* getName() const;
    void setName(const char* n);
};
#endif