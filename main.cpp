#include "Keeper.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    Keeper keeper;
    int choice;
    
    do {
        cout << "\n========================================" << endl;
        cout << "       СИСТЕМА УЧЁТА ГРУЗОПЕРЕВОЗОК       " << endl;
        cout << "========================================" << endl;
        cout << "1. Добавить новый объект" << endl;
        cout << "2. Удалить объект по номеру" << endl;
        cout << "3. Вывести все объекты" << endl;
        cout << "4. Найти объекты по типу" << endl;
        cout << "5. Сохранить данные в файл (data.txt)" << endl;
        cout << "6. Загрузить данные из файла (data.txt)" << endl;
        cout << "0. Выход" << endl;
        cout << "========================================" << endl;
        cout << "Ваш выбор: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите число!" << endl;
            continue;
        }
        cout << "----------------------------------------" << endl;
        
        switch (choice) {
            case 1:
                keeper.addFromMenu();
                break;
            case 2:
                keeper.removeFromMenu();
                break;
            case 3:
                keeper.printAll();
                break;
            case 4:
                keeper.findByType();
                break;
            case 5:
                keeper.saveToFile("data.txt");
                break;
            case 6:
                keeper.loadFromFile("data.txt");
                break;
            case 0:
                cout << "Завершение работы программы..." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
        }
    } while (choice != 0);
    
    return 0;
}