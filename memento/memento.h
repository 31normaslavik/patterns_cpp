#pragma once
/*
    Снимок
    Позволяет сохранять и восстанавливать прошлое состояние
    объектов, не раскрывая подробности их рализации
    +Не нарушает инкапсуляцию исходного объекта и
    упрощает его структуру
    -Большое количество памяти выделяемой при частом создании
    снимка состояния
*/

/*
    Имитация системы анализа работы биржи
    Позволит безболезнено откатиться назад, без финансовых потерь
*/

#include <stack>
class Memento{
public:
    virtual int getDollars() = 0;
    virtual int getEuro() = 0;
    virtual ~Memento();
};

class ExchangeMemento: public Memento{
private:
    int dollars;
    int euro;
public:
    ExchangeMemento(int d, int e);
    int getDollars()override;

    int getEuro()override;

};

class Exchange{
private:
    int dollars;
    int euro;
public:
    Exchange(int d, int e);
    void getDollars();
    void getEuro();
    void sell();

    void buy();

    ExchangeMemento* save();

    void restore(Memento* exchangememento);
};

class Memory{
private:
    std::stack<Memento*> history;
    Exchange* exchange;
public:
    Memory(Exchange* ex);
    void backup();
    void undo();
};











