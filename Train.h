#ifndef TRAIN_H       
#define TRAIN_H
#include "Base.h"
#include <iostream>
#include <cstring> 
class Train : public Base{
    private:
    int year;
    char* route;
    int vagonCount;
    double cargoVolume;

    public:
    Train();
    Train(const char* n, int y, const char* r, int vagCnt, double vol);
    Train(const Train& other);
    ~Train() override;

    void print() const override;
    void input() override;
    Base* clone() const override;
    const char* getType() const override;

    int getYear() const;
    const char* getRoute() const;
    int getVagonCnt() const;
    double getCargoVolume() const;
    
    void setYear(int year);
    void setRoute(const char* r);
    void setVagonCnt(int wagCnt);
    void setCargoVolume(double vol);

};
#endif