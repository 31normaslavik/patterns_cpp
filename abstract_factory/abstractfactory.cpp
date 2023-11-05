#include "abstractfactory.h"
#include <iostream>

void JapaneseEngine::releaseEngine(){
    std::cout<<"японский двигатель"<<std::endl;
}

void RussianEngine::releaseEngine(){
    std::cout<<"российский двигатель"<<std::endl;
}

void JapaneseCar::releaseCar(Engine *engine){
    std::cout<<"Собрали японский автомобиль: ";
    engine->releaseEngine();
}

void RussianCar::releaseCar(Engine *engine){
    std::cout<<"Собрали российский автомобиль: ";
    engine->releaseEngine();
}

Engine *JapaneseFactory::createEngine(){
    return new JapaneseEngine();
}

Car *JapaneseFactory::createCar(){
    return new JapaneseCar();
}

Engine *RussianFactory::createEngine(){
    return new RussianEngine();
}

Car *RussianFactory::createCar(){
    return new RussianCar();
}
