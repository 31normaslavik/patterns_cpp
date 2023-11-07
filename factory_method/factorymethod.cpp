#include "factorymethod.h"
#include <iostream>


void fm::Car::release(){
    std::cout<<"Выпущен новый легковой автомобиль"<<std::endl;
}

void fm::Truck::release(){
    std::cout<<"Выпущен новый грузовой автомобиль"<<std::endl;
}

fm::Production *fm::CarWorkShop::create(){
    return new Car;
}

fm::Production *fm::TruckWorkShop::create(){
    return new Truck;
}
