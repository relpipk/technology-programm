#include "Car.h"
#include "Base.h"
#include <iostream>
#include <cstring> 

Car::Car():Base(){
    cout << "[Car] Вызван конструктор по умолчанию" << endl;
    year = 0;
    brand = nullptr;
    model = nullptr;
    deliveryInfo = nullptr;
    cargoVolume = 0.0;
}
Car::Car(const char* n, int y, const char* br, const char* mod, const char* dInf, double vol): Base(n){
    cout << "[Car] Вызван конструктор с параметрами" << endl;
    year=y;
    cargoVolume=vol;
    if (br != nullptr) {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
    } else {
        brand = nullptr;
    }
    if (mod != nullptr) {
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    } else {
        model = nullptr;
    }
    if (dInf != nullptr) {
        deliveryInfo = new char[strlen(dInf) + 1];
        strcpy(deliveryInfo, dInf);
    } else {
        deliveryInfo = nullptr;
    }
}
Car::Car(const Car& other):Base(other){
    year=other.year;
    cargoVolume=other.cargoVolume;
    if (other.brand != nullptr) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    } else {
        brand = nullptr;
    }
    if (other.model != nullptr) {
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    } else {
        model = nullptr;
    }
    if (other.deliveryInfo != nullptr) {
        deliveryInfo = new char[strlen(other.deliveryInfo) + 1];
        strcpy(deliveryInfo, other.deliveryInfo);
    } else {
        deliveryInfo = nullptr;
    }
}
Car::~Car() {
    cout << "[Car] Вызван деструктор" << endl;
    delete[] brand;
    brand = nullptr;
    delete[] model;
    model = nullptr;
    delete[] deliveryInfo;
    deliveryInfo = nullptr;
}

int Car::getYear() const{
    return year;
}
const char* Car:: getBrand() const{
    return brand;
}
const char* Car::getModel() const{
    return model;
}
const char* Car::getDeliveryInfo() const{
    return deliveryInfo;
}
double Car::getCargoVolume() const{
    return cargoVolume;
}
    
void Car::setYear(int y){
    if (y<0) throw "Ошибка: год не может быть отрицательным!";
    year = y;
}
void Car::setBrand(const char* br){
     delete[] brand;
    if (br != nullptr) {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
    } else {
        brand = nullptr;
    }
}
void Car::setModel(const char* mod){
    delete[] model;
    if (mod != nullptr) {
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    } else {
        model = nullptr;
    }
}
void Car::setDeliveryInfo(const char* dInf){
    delete[] deliveryInfo;
    if (dInf != nullptr) {
        deliveryInfo = new char[strlen(dInf) + 1];
        strcpy(deliveryInfo, dInf);
    } else {
        deliveryInfo = nullptr;
    }
}
void Car::setCargoVolume(double vol){
    if (vol < 0) throw "Ошибка: объём груза не может быть отрицательным!";
    cargoVolume = vol;
}

void Car::print() const {
    cout << "=== АВТОМОБИЛЬ ===" << endl;
    cout << "Наименование: " << getName() << endl;
    cout << "Год выпуска: " << year << endl;
    cout << "Марка: " << (brand ? brand : "Не указана") << endl;
    cout << "Модель: " << (model ? model : "Не указана") << endl;
    cout << "Информация о доставке: " << (deliveryInfo ? deliveryInfo : "Не указана") << endl;
    cout << "Объём груза: " << cargoVolume << " т." << endl;
    cout << "====================" << endl;
}
void Car::input() {
    char buffer[256];
    
    cout << "Введите наименование автомобиля: ";
    cin >> buffer;
    setName(buffer);
    
    cout << "Введите год выпуска: ";
    int y; cin >> y;
    setYear(y);
    
    cout << "Введите марку: ";
    cin >> buffer;
    setBrand(buffer);
    
    cout << "Введите модель: ";
    cin >> buffer;
    setModel(buffer);
    
    cout << "Введите информацию о доставке (формат: Город1:часы,Город2:часы): ";
    cin >> buffer;
    setDeliveryInfo(buffer);
    
    cout << "Введите объём груза: ";
    double v; cin >> v;
    setCargoVolume(v);
}
Base* Car::clone() const {
    return new Car(*this);
}

const char* Car::getType() const {
    return "Car";
}

void Car::saveToFileStream(std::ofstream& file) const {
    file << getType() << "\n"
         << (getName() ? getName() : "None") << "\n"
         << year << "\n"
         << (brand ? brand : "None") << "\n"
         << (model ? model : "None") << "\n"
         << (deliveryInfo ? deliveryInfo : "None") << "\n"
         << cargoVolume << "\n";
}

void Car::loadFromFileStream(std::ifstream& file) {
    char buf[256];
    int y;
    double vol;
    
    file >> buf; setName(buf);
    file >> y; setYear(y);
    file >> buf; setBrand(buf);
    file >> buf; setModel(buf);
    file >> buf; setDeliveryInfo(buf);
    file >> vol; setCargoVolume(vol);
}