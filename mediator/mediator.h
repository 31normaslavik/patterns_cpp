#pragma once
#include <string>

/*
    Медиатор
    Позволяет уменьшить связаность множества классов между
    собой, благодаря перемещению этих связей в один класс посредник
    Упрощает взаимодействие между компонентами и централизует
    управление в одном классе
*/

/*
    Пример организации в которой есть работник дизайнер и директор,
    а так же котроллер посредник, через которого директор
    взаимодействует с дизайнером
*/

class Employee;

class Mediator
{
public:
    virtual void Notify(Employee* emp, std::string msg) = 0;
};

class Employee{
protected:
    Mediator* mediator;
public:
    Employee(Mediator* med = nullptr);
    void setMediator(Mediator* med);

    virtual ~Employee() = default;
};

class Designer: public Employee{
private:
    bool isWorking;
public:
    Designer(Mediator* med = nullptr);
    void executerWork();

    void setWork(bool state);
};

class Director: public Employee{
private:
    std::string text;
public:
    Director(Mediator* med = nullptr);
    void giveCommand(std::string txt);
};

class Controller: public Mediator{
private:
    Designer* designer;
    Director* director;
public:
    Controller(Designer* des, Director* dir);

    void Notify(Employee* emp, std::string msg)override;
};














