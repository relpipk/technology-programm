#include "Train.h"
#include <iostream>
#include <cstring>
#include "Base.h"

Train::Train() : Base() {
    cout << "[Train] Вызван конструктор по умолчанию" << endl;
    year = 0;
    route = nullptr;
    vagonCount = 0;
    cargoVolume = 0.0;
}
Train::Train(const char* n, int y, const char* r, int vagCnt, double vol) : Base(n) {
    cout << "[Train] Вызван конструктор с параметрами" << endl;
    year=y;
    vagonCount=vagCnt;
    cargoVolume=vol;
    if (r != nullptr) {
        route = new char[strlen(r) + 1];
        strcpy(route, r);
    } else {
        route = nullptr;
    }
}
Train::~Train() {
    cout << "[Train] Вызван деструктор" << endl;
    delete[] route;
    route = nullptr;
}
Train::Train(const Train& other): Base(other){
    cout << "[Train] Вызван конструктор копирования" << endl;
    year = other.year;
    vagonCount = other.vagonCount;
    cargoVolume = other.cargoVolume;
    
    if (other.route != nullptr) {
        route = new char[strlen(other.route) + 1];
        strcpy(route, other.route);
    } else {
        route = nullptr;
    }
}
int Train:: getYear() const{
    return year;
}
const char* Train:: getRoute() const{
    return route;
}
int Train:: getVagonCnt() const{
    return vagonCount;
}
double Train ::getCargoVolume() const{
    return cargoVolume;
}

void Train::setYear(int y){
    if (y < 0) throw "Ошибка: год не может быть отрицательным!";
    year = y;
}
void Train :: setRoute(const char* r){
    delete[] route;
    if (r != nullptr) {
        route = new char[strlen(r) + 1];
        strcpy(route, r);
    } else {
        route = nullptr; 
    }
}
void Train :: setVagonCnt(int vagCnt){
    if (vagCnt < 0) throw "Ошибка: количество вагонов не может быть отрицательным!";
    vagonCount = vagCnt;
}
void Train:: setCargoVolume(double vol) {
    if (vol < 0) {
        throw "Ошибка: объём груза не может быть отрицательным!";
    }
    cargoVolume = vol; 
}

void Train::print() const {
    cout << "=== ПОЕЗД ===" << endl;
    cout << "Наименование: " << getName() << endl;
    cout << "Год выпуска: " << year << endl;
    cout << "Маршрут: " << (route ? route : "Не указан") << endl;
    cout << "Вагонов: " << vagonCount << endl;
    cout << "Объём груза: " << cargoVolume << " т." << endl;
    cout << "=============" << endl;
}
void Train::input() {
    char buffer[256];
    
    cout << "Введите наименование поезда: ";
    cin >> buffer;
    setName(buffer);
    
    cout << "Введите год выпуска: ";
    int y; cin >> y;
    setYear(y);
    
    cout << "Введите маршрут (без пробелов): ";
    cin >> buffer;
    setRoute(buffer);
    
    cout << "Введите количество вагонов: ";
    int w; cin >> w;
    setVagonCnt(w);
    
    cout << "Введите объём груза: ";
    double v; cin >> v;
    setCargoVolume(v);
}
Base* Train::clone() const {
    return new Train(*this);
}
const char* Train::getType() const {
    return "Train";
}
void Train::saveToFileStream(std::ofstream& file) const {
    file << getType() << "\n"
         << (getName() ? getName() : "None") << "\n"
         << year << "\n"
         << (route ? route : "None") << "\n"
         << vagonCount << "\n"
         << cargoVolume << "\n";
}

void Train::loadFromFileStream(std::ifstream& file) {
    char buf[256];
    int y, w;
    double vol;
    
    file >> buf; setName(buf);
    file >> y; setYear(y);
    file >> buf; setRoute(buf);
    file >> w; setVagonCnt(w);
    file >> vol; setCargoVolume(vol);
}