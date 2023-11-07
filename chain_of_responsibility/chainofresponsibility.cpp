#include "chainofresponsibility.h"
#include <iostream>


cr::AbstractWorker::AbstractWorker(): nextWorker{nullptr}{}

cr::Worker *cr::AbstractWorker::setNextWorker(Worker *worker){
    nextWorker = worker;
    return worker;
}

std::string cr::AbstractWorker::execute(std::string command){
    if(nextWorker)
        return nextWorker->execute(command);
    return {};
}

std::string cr::Designer::execute(std::string command){
    if(command == "спроектировать дом"){
        return "Проектировщик выполнил команду: " + command;
    }else
        return AbstractWorker::execute(command);
}

std::string cr::Carpenters::execute(std::string command){
    if(command == "класть кирпич"){
        return "Плотник выполнил команду: " + command;
    }else
        return AbstractWorker::execute(command);
}

std::string cr::FinishWorker::execute(std::string command){
    if(command == "клеить обои"){
        return "Рабочий внутренней отделки "
               "выполнил команду: " + command;
    }else
        return AbstractWorker::execute(command);
}

void cr::givecommand(Worker *worker, std::string command){
    std::string str = worker->execute(command);
    if(str.empty()){
        std::cout<<command<<" - никто не умеет делать"<<std::endl;
    }else {
        std::cout<<str<<std::endl;
    }
}
