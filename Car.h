#ifndef CAR_H       
#define CAR_H
#include "Base.h"
#include <iostream>
#include <cstring> 
class Car : public Base{
    private:
    int year;
    char* brand;
    char* model;
    char* deliveryInfo;
    double cargoVolume;

    public:
    Car();
    Car(const char* n, int y, const char* br, const char* mod, const char* dInf, double vol);
    Car(const Car& other);
    ~Car() override;

    void print() const override;
    void input() override;
    Base* clone() const override;
    const char* getType() const override;

    int getYear() const;
    const char* getBrand() const;
    const char* getModel() const;
    const char* getDeliveryInfo() const;
    double getCargoVolume() const;
    
    void setYear(int y);
    void setBrand(const char* br);
    void setModel(const char* mod);
    void setDeliveryInfo(const char* DInf);
    void setCargoVolume(double vol);

};
#endif