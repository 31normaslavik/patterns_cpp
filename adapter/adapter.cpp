#include "adapter.h"
#include <iostream>



RussianScales::RussianScales(float *cw): currentWeight{cw}{

}

RussianScales::~RussianScales(){
    delete currentWeight;
}

float *RussianScales::getWeight(){
    return currentWeight;
}

void RussianScales::adjust(){
    std::cout<<"Регулировка российских весов"<<std::endl;
}

BritishScales::BritishScales(float *cw): currentWeight{cw}{

}


BritishScales::~BritishScales(){
    delete currentWeight;
}

float *BritishScales::getWeight() {
    return currentWeight;
}

void BritishScales::adjust(){
    std::cout<<"Регулировка британских весов";
}

AdapterforBritishScales::AdapterforBritishScales(float *cw)
    : BritishScales(cw){}

AdapterforBritishScales::AdapterforBritishScales(BritishScales* bs)
    : AdapterforBritishScales(bs->getWeight()){}

AdapterforBritishScales::~AdapterforBritishScales(){
    std::cout<<"Destructor\n";
    if(cw != nullptr) delete cw;
    if(britishScale != nullptr) delete britishScale;
}

float *AdapterforBritishScales::getWeight(){
    cw = BritishScales::getWeight();
    *cw = *cw * 0.453;
    return cw;
}

void AdapterforBritishScales::adjust(){
    BritishScales::adjust();
    std::cout<<" в методе регулировки adjust адаптера"<<std::endl;
}
