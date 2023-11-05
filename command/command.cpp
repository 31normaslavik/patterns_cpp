#include "command.h"
#include <iostream>

void Conveyor::on(){
    std::cout<<"Конвеер запущен"<<std::endl;
}

void Conveyor::off(){
    std::cout<<"Конвеер остановлен"<<std::endl;
}

void Conveyor::speedIncrease(){
    std::cout<<"Увеличена скорость конвеера"<<std::endl;
}

void Conveyor::speedDecrease(){
    std::cout<<"Снижена скорость конвеера"<<std::endl;
}

ConveyorWorkCommand::ConveyorWorkCommand(Conveyor *_conveyor): conveyor{_conveyor}{}

void ConveyorWorkCommand::positive(){
    conveyor->on();
}

void ConveyorWorkCommand::negative(){
    conveyor->off();
}

ConveyorAdjustCommand::ConveyorAdjustCommand(Conveyor *_conveyor): conveyor{_conveyor}{}

void ConveyorAdjustCommand::negative(){
    conveyor->speedDecrease();
}

void ConveyorAdjustCommand::positive(){
    conveyor->speedIncrease();
}

MultiPult::MultiPult(){
    commands.resize(2);
}

void MultiPult::setCommand(int button, Command *command){
    commands[button] = command;
}

void MultiPult::pressOn(int button){
    commands[button] ->positive();
    history.push(commands[button]);
}

void MultiPult::pressCancel(){
    if(!history.empty()){
        history.top()->negative();
        history.pop();
    }
}
