#pragma once

/*
    Цепочка обязанностей
    Предназначен для организации в системе уровня ответсвенности
*/

/*
    Разные этапы строительства дома возлагаются на лиц
    различных строительных профессий
*/

#include <string>
namespace cr {

class Worker{
public:
    virtual Worker* setNextWorker(Worker* worker) = 0;
    virtual std::string execute(std::string command) = 0;
};

class AbstractWorker : public Worker{
private:
    Worker* nextWorker;
public:
    AbstractWorker();
    Worker* setNextWorker(Worker* worker)override;
    std::string execute(std::string command) override;
};

class Designer: public AbstractWorker{
public:
    std::string execute(std::string command) override;
};

class Carpenters: public AbstractWorker{
public:
    std::string execute(std::string command) override;
};

class FinishWorker: public AbstractWorker{
public:
    std::string execute(std::string command) override;
};


void givecommand(Worker* worker, std::string command);

} // namespace cr









