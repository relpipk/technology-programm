#ifndef AIRPLANE_H       
#define AIRPLANE_H
#include "Base.h"
#include <iostream>
#include <cstring> 

class Airplane: public Base{
public:

Airplane();
Airplane(const char* n,const char* t,double vol, const char* dim,const char* c);
~Airplane() override;
Airplane(const Airplane& other);
void print() const override;
void input() override;
Base* clone() const override;
const char* getType() const override;
const char* getTypePlane() const{
    return type;
}const char* getDim() const{
    return dimensions;
}const char* getCit() const{
    return cities;
}double getCargoVol() const {
    return cargoVolume;
}
void setType(const char* t){
    delete[] type;
    if (t != nullptr) {
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }else {
        type = nullptr; 
    }
}void setDim(const char* dim){
    delete[] dimensions;
    if (dim != nullptr) {
        dimensions = new char[strlen(dim) + 1];
        strcpy(dimensions, dim);
    }else {
        dimensions = nullptr; 
    }
}void setCit(const char* c){
    delete[] cities;
    if (c != nullptr) {
        cities = new char[strlen(c) + 1];
        strcpy(cities, c);
    }else {
        cities = nullptr; 
    }
}void setCargoVolume(double vol) {
    if (vol < 0) {
        throw "Ошибка: объём груза не может быть отрицательным!";
    }
    cargoVolume = vol; 
}

private:
char* type;
double cargoVolume;
char* dimensions;
char* cities;
};
#endif