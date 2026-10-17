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

    const char* getTypePlane() const;
    const char* getDim() const;
    const char* getCit() const;
    double getCargoVol() const;
    

    void setType(const char* t);
    void setDim(const char* dim);
    void setCit(const char* c);
    void setCargoVolume(double vol);

    private:
    char* type;
    double cargoVolume;
    char* dimensions;
    char* cities;
    };
#endif