#include "Keeper.h"
#include "Airplane.h"
#include "Train.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Keeper::Keeper() {
    cout << "[Keeper] Контейнер создан" << endl;
    capacity = 10;  // Начальная вместимость
    count = 0;      // Пока объектов нет
    items = new Base*[capacity];  // Выделяем память под массив указателей
    for (int i = 0; i < capacity; i++) {
        items[i] = nullptr;
    }
}
Keeper::~Keeper() {
    cout << "[Keeper] Контейнер удалён" << endl;
    for (int i = 0; i < count; i++) {
        if (items[i] != nullptr) {
            delete items[i];
            items[i] = nullptr;
        }
    }
    delete[] items;// Удаляем сам массив
    items = nullptr;
}
void Keeper::add(Base* item) {//добавить обьект
    if (item == nullptr) {
        cout << "Ошибка: нельзя добавить nullptr!" << endl;
        return;
    }
    if (count >= capacity) {
        capacity *= 2;  // Удваиваем вместимость
        Base** newItems = new Base*[capacity];
        for (int i = 0; i < count; i++) {// Копируем старые указатели
            newItems[i] = items[i];
        }
        // Инициализируем новые ячейки
        for (int i = count; i < capacity; i++) {
            newItems[i] = nullptr;
        }
        // Удаляем старый массив
        delete[] items;
        items = newItems;
        cout << "[Keeper] Вместимость увеличена до " << capacity << endl;
    }
    items[count] = item;
    count++;
    cout << "[Keeper] Объект добавлен. Всего объектов: " << count << endl;
}
void Keeper::remove(int index) {
    if (index < 0 || index >= count) {
        cout << "Ошибка: неверный индекс!" << endl;
        return;
    }
    delete items[index];
    // Сдвигаем все последующие элементы влево
    for (int i = index; i < count - 1; i++) {
        items[i] = items[i + 1];
    }
    // Последний элемент теперь пустой
    items[count - 1] = nullptr;
    count--;
    cout << "[Keeper] Объект удалён. Всего объектов: " << count << endl;
}
void Keeper::printAll() const {
    if (count == 0) {
        cout << "Контейнер пуст!" << endl;
        return;
    }
    
    cout << "\n=== ВСЕ ОБЪЕКТЫ (" << count << " шт.) ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\n[Объект #" << (i + 1) << "]" << endl;
        items[i]->print(); 
    }
    cout << "================================\n" << endl;
}

void Keeper::addFromMenu() {
    cout << "\nВыберите тип объекта:" << endl;
    cout << "1. Самолёт" << endl;
    cout << "2. Поезд" << endl;
    cout << "3. Автомобиль" << endl;
    cout << "Выбор: ";
    int choice;
    cin >> choice;
    Base* newItem = nullptr;
    
    try {
        if (choice == 1) {
            newItem = new Airplane();
            newItem->input();
        } else if (choice == 2) {
            newItem = new Train();
            newItem->input();
        } else if (choice == 3) {
            newItem = new Car();
            newItem->input();
        } else {
            cout << "Неверный выбор!" << endl;
            return;
        }
        
        add(newItem);
    } catch (const char* msg) {
        cout << "Ошибка при вводе: " << msg << endl;
        delete newItem;  // Освобождаем память, если произошла ошибка
    }
}
void Keeper::removeFromMenu() {
    if (count == 0) {
        cout << "Контейнер пуст!" << endl;
        return;
    }
    printAll();
    
    cout << "Введите номер объекта для удаления (1-" << count << "): ";
    int index;
    cin >> index;
    remove(index - 1);  
}

void Keeper::findByType() {
    cout << "\nНайти по типу:" << endl;
    cout << "1. Самолёты" << endl;
    cout << "2. Поезда" << endl;
    cout << "3. Автомобили" << endl;
    cout << "Выбор: ";
    int choice;
    cin >> choice;
    const char* targetType;
    if (choice == 1) targetType = "Airplane";
    else if (choice == 2) targetType = "Train";
    else if (choice == 3) targetType = "Car";
    else {
        cout << "Неверный выбор!" << endl;
        return;
    }
    cout << "\n=== Объекты типа " << targetType << " ===" << endl;
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i]->getType(), targetType) == 0) {
            cout << "\n[Объект #" << (i + 1) << "]" << endl;
            items[i]->print();
            found++;
        }
    }
    
    if (found == 0) {
        cout << "Объекты типа " << targetType << " не найдены!" << endl;
    } else {
        cout << "\nНайдено объектов: " << found << endl;
    }
}
void Keeper::saveToFile(const char* filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл для записи!" << std::endl;
        return;
    }
    
    file << count << "\n"; // Сначала количество
    for (int i = 0; i < count; i++) {
        items[i]->saveToFileStream(file); // Каждый объект сохраняет себя сам
    }
    file.close();
    std::cout << "Данные успешно сохранены в файл " << filename << std::endl;
}

void Keeper::loadFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл для чтения!" << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        delete items[i];
    }
    count = 0;
    int n;
    file >> n; // Читаем количество
    char type[50];
    for (int i = 0; i < n; i++) {
        file >> type; // Читаем тип объекта
        
        if (std::strcmp(type, "Airplane") == 0) {
            Airplane* plane = new Airplane();
            plane->loadFromFileStream(file);
            add(plane);
        } else if (std::strcmp(type, "Train") == 0) {
            Train* train = new Train();
            train->loadFromFileStream(file);
            add(train);
        } else if (std::strcmp(type, "Car") == 0) {
            Car* car = new Car();
            car->loadFromFileStream(file);
            add(car);
        }
    }
    file.close();
    std::cout << "Данные успешно загружены из файла " << filename << std::endl;
}
int Keeper::getCount() const {
    return count;
}