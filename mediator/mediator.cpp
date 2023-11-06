#include "mediator.h"
#include <iostream>



Employee::Employee(Mediator *med): mediator{med}{}

void Employee::setMediator(Mediator *med){
    mediator = med;
}

Designer::Designer(Mediator *med): Employee(med){}

void Designer::executerWork(){
    std::cout<<"<-Дизайнер в работе"<<std::endl;
    mediator->Notify(this,"дизайнер проектирует...");
}

void Designer::setWork(bool state){
    isWorking = state;
    if(state)
        std::cout<<"<-Дизайнер освобожден от работы"<<std::endl;
    else
        std::cout<<"<-Дизайнер занят"<<std::endl;
}

Director::Director(Mediator *med): Employee(med){}

void Director::giveCommand(std::string txt){
    text = txt;
    if(text.empty())
        std::cout<<"->Диркетор знает, что дизайнер уже работает"
                  <<std::endl;
    else
        std::cout<<"->Директор дал команду: "<< text<<std::endl;
            mediator->Notify(this,text);
}

Controller::Controller(Designer *des, Director *dir){
    designer = des;
    director = dir;
    designer->setMediator(this);
    director->setMediator(this);
}

void Controller::Notify(Employee *emp, std::string msg){
    if(auto dir = dynamic_cast<Director*>(emp)){
        if(msg.empty()){
            designer->setWork(false);
        }else{
            designer->setWork(true);
        }
    }
    if(auto dir = dynamic_cast<Designer*>(emp)){
        if(msg == "дизайнер проектирует..."){
            director->giveCommand("");
        }
    }
}
