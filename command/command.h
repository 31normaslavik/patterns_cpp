#pragma once

/*
    Команда
    Объект используется для инкапсуляции всей информации
    необходимой для выполнения действий или вызова событий
    в более позднее время
    Эта информация включает в себя имя метода
    объект которой является владельцем метода
    и значение параметров метода
*/

// Пульт управления конвеерной установкой

#include <vector>
#include <stack>
class Command{
public:
    virtual void positive()=0;
    virtual void negative()=0;
};

class Conveyor{
public:
    void on();
    void off();

    void speedIncrease();
    void speedDecrease();
};

class ConveyorWorkCommand: public Command{
private:
    Conveyor* conveyor;
public:
    ConveyorWorkCommand(Conveyor* _conveyor);

    void positive()override;

    void negative()override;
};

class ConveyorAdjustCommand: public Command{
private:
    Conveyor* conveyor;
public:
    ConveyorAdjustCommand(Conveyor* _conveyor);

    void negative() override;

    void positive()override;
};

class MultiPult{
private:
    std::vector<Command*> commands;
    std::stack<Command*> history;
public:
    MultiPult();
    void setCommand(int button, Command* command);

    void pressOn(int button);

    void pressCancel();
};
















