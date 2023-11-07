#include "templatemethod.h"
#include <iostream>


void tmpm::Transmitter::voiceRecord(){
    std::cout<<"Запись фрагмента речи"<<std::endl;
}

void tmpm::Transmitter::simpling(){}

void tmpm::Transmitter::digitization(){}

void tmpm::Transmitter::transmission(){
    std::cout<<"Передача сигнала по радиоканалу"<<std::endl;
}

void tmpm::Transmitter::processStart(){
    voiceRecord();
    simpling();
    digitization();
    modulation();
    transmission();
}

void tmpm::AnalogTransmitter::modulation(){
    std::cout<<"Модуляция аналогово сигнала"<<std::endl;
}

void tmpm::DigitalTransmitter::modulation(){
    std::cout<<"Модуляция цифрового сигнала"<<std::endl;
}

void tmpm::DigitalTransmitter::simpling(){
    std::cout<<"Дискретизация записанного фрагмента"<<std::endl;
}

void tmpm::DigitalTransmitter::digitization(){
    std::cout<<"Оцифровка"<<std::endl;
}
