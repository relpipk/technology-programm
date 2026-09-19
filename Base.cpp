#include "Base.h"
#include <iostream>
#include <cstring>
Base::Base(){
    name=nullptr;
    cout << "[Base] Вызван конструктор по умолчанию" << endl;
    
}
Base::Base(const char* n){
    cout << "[Base] Вызван конструктор с параметрами" << endl;
    if (n!=nullptr){
        name=new char[strlen(n)+1];
        strcpy(name,n);
    }else{
        name=nullptr;
    }

}
Base::Base(const Base& other){
    cout<< "[Base] Вызван конструктор копирования" << endl;
    if (other.name!=nullptr){
        name=new char[strlen(other.name)+1];
        strcpy(name, other.name);
    }else{
        name=nullptr;
    }
}
Base::~Base(){
    cout<< "[Base] Вызван деструктор"<<endl;
    delete[] name;
    name=nullptr;
}
const char* Base::getName() const{
    return name;
}
void Base::setName(const char* n) {
    delete[] name;
    if (n != nullptr) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else {
        name = nullptr;
    }
}