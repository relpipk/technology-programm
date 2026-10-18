#ifndef KEEPER_H
#define KEEPER_H
#include "Base.h"
class Keeper {
private:
    Base** items;  // указатель на массив указателей на объекты
    int count;     // Текущее количество объектов
    int capacity;  // Максимальная вместимость массива

    public:
    Keeper();
    ~Keeper();

    void add(Base* item);              // Добавить объект
    void remove(int index);            // Удалить объект по индексу
    void printAll() const;             // Вывести все объекты

    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    
    void addFromMenu();                // Добавить через меню
    void removeFromMenu();             // Удалить через меню
    void findByType();                 // Найти по типу

    int getCount() const;
};
#endif