#include "memento.h"
#include <iostream>


Memento::~Memento(){}

ExchangeMemento::ExchangeMemento(int d, int e): dollars{d}, euro{e}{}

int ExchangeMemento::getDollars(){
    return dollars;
}

int ExchangeMemento::getEuro(){
    return euro;
}

Exchange::Exchange(int d, int e): dollars{d}, euro{e}{}

void Exchange::getDollars(){
    std::cout<<"Долларов: "<<dollars<<std::endl;
}

void Exchange::getEuro(){
    std::cout<<"Евро: "<<euro<<std::endl;
}

void Exchange::sell(){
    dollars ? --dollars:0;
}

void Exchange::buy(){
    ++euro;
}

ExchangeMemento *Exchange::save(){
    return new ExchangeMemento(dollars,euro);
}

void Exchange::restore(Memento *exchangememento){
    dollars = exchangememento->getDollars();
    euro = exchangememento->getEuro();
    delete exchangememento;
}

Memory::Memory(Exchange *ex): exchange{ex}{}

void Memory::backup(){
    history.push(exchange->save());
}

void Memory::undo(){
    if(history.empty()){
        return;
    }
    exchange->restore(history.top());
    history.pop();
}
