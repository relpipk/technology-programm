#include "Airplane.h"
#include <iostream>
#include <cstring>

using namespace std;
Airplane::Airplane() : Base() {
    cout << "[Airplane] Вызван конструктор по умолчанию" << endl;
    type = nullptr;
    cargoVolume = 0.0;
    dimensions = nullptr;
    cities = nullptr;
}
Airplane::Airplane(const char* n,const char* t,double vol, const char* dim,const char* c) : Base(n) {
    cout << "[Airplane] Вызван конструктор с параметрами" << endl;
    cargoVolume = vol;
    if (t != nullptr) {
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    } else {
        type = nullptr;
    }
    if (dim != nullptr) {
        dimensions = new char[strlen(dim) + 1];
        strcpy(dimensions, dim);
    } else {
        dimensions = nullptr;
    }
     if (c != nullptr) {
        cities = new char[strlen(c) + 1];
        strcpy(cities, c);
    } else {
        cities = nullptr;
    }
}
Airplane:: ~Airplane(){
    cout<< "[Airplane] Вызван деструктор"<<endl;
    delete[] type;
    type=nullptr;
    delete[] dimensions;
    dimensions = nullptr;
    delete[] cities;
    cities = nullptr;
}
Airplane::Airplane(const Airplane& other): Base(other){
    cout<< "[Airplane] Вызван конструктор копирования" << endl;
    if (other.type!=nullptr){
        type=new char[strlen(other.type)+1];
        strcpy(type, other.type);
    }else{
        type=nullptr;
    }if (other.dimensions!=nullptr){
        dimensions=new char[strlen(other.dimensions)+1];
        strcpy(dimensions, other.dimensions);
    }else{
        dimensions=nullptr;
    }if (other.cities!=nullptr){
        cities=new char[strlen(other.cities)+1];
        strcpy(cities, other.cities);
    }else{
        cities=nullptr;
    }
    cargoVolume = other.cargoVolume;
}
const char* Airplane::getTypePlane() const {
    return type;
}const char* Airplane:: getDim() const{
    return dimensions;
}const char* Airplane::getCit() const{
    return cities;
}double Airplane::  getCargoVol() const {
    return cargoVolume;
}
void Airplane::setType(const char* t) {
    delete[] type;
    if (t != nullptr) {
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    } else {
        type = nullptr;
    }
}void Airplane::setDim(const char* dim){
    delete[] dimensions;
    if (dim != nullptr) {
        dimensions = new char[strlen(dim) + 1];
        strcpy(dimensions, dim);
    }else {
        dimensions = nullptr; 
    }
}void Airplane:: setCit(const char* c){
    delete[] cities;
    if (c != nullptr) {
        cities = new char[strlen(c) + 1];
        strcpy(cities, c);
    }else {
        cities = nullptr; 
    }
}void Airplane ::setCargoVolume(double vol) {
    if (vol < 0) {
        throw "Ошибка: объём груза не может быть отрицательным!";
    }
    cargoVolume = vol; 
}
void Airplane::print() const {
    cout << "=== САМОЛЕТ ===" << endl;
    cout << "Наименование: " << getName() << endl;
    cout << "Тип: " << (type ? type : "Не указан") << endl;
    cout << "Объём груза: " << cargoVolume << " т." << endl;
    cout << "Габариты: " << (dimensions ? dimensions : "Не указаны") << endl;
    cout << "Города: " << (cities ? cities : "Не указаны") << endl;
    cout << "===============" << endl;
}
void Airplane::input() {
    char buffer[256];  // Временный буфер для строк
    
    cout << "Введите наименование: ";
    cin >> buffer;
    setName(buffer);
    
    cout << "Введите тип: ";
    cin >> buffer;
    setType(buffer);
    
    cout << "Введите объём груза: ";
    cin >> cargoVolume;
    
    cout << "Введите габариты: ";
    cin >> buffer;
    setDim(buffer);
    
    cout << "Введите города (через запятую, без пробелов): ";
    cin >> buffer;
    setCit(buffer);
}
Base* Airplane::clone() const {
    return new Airplane(*this); 
}
const char* Airplane::getType() const {
    return "Airplane";
}
void Airplane::saveToFileStream(std::ofstream& file) const {
    file << getType() << "\n"
         << (getName() ? getName() : "None") << "\n"
         << (type ? type : "None") << "\n"
         << cargoVolume << "\n"
         << (dimensions ? dimensions : "None") << "\n"
         << (cities ? cities : "None") << "\n";
}

void Airplane::loadFromFileStream(std::ifstream& file) {
    char buf[256];
    double vol;
    file >> buf; setName(buf);
    file >> buf; setType(buf);
    file >> vol; setCargoVolume(vol);
    file >> buf; setDim(buf);
    file >> buf; setCit(buf);
}
