#pragma once

/*
    Абстрактная фабрика
    Предоставляет интерфейс для сознания семейств
    взаимосвязаных либо взаимозависимых объектов
    не специфицируя их конкретных классов

    Шаблон применяется в случаях когда программа должна быть
    независима от процессов и типов создаваемых новых объектах,
    а так же когда необходимо создать семейство или групы
    независимых объектов

    Плюсы патерна: Изолирует конкретные классы, упрощает замену
    семейств продуктов, гарантирует сочитаемость продуктов

    Минусы: Сложность добавления нового вида продуктов
*/


class Engine{
public:
    virtual void releaseEngine() = 0;
};

class JapaneseEngine : public Engine{
public:
    void releaseEngine()override;
};

class RussianEngine: public Engine{
public:
    void releaseEngine() override;
};

class Car{
public:
    virtual void releaseCar(Engine* engine) = 0;
};

class JapaneseCar: public Car{
public:
    void releaseCar(Engine* engine) override;
};

class RussianCar: public Car{
public:
    void releaseCar(Engine* engine) override;
};


class Factory{
public:
    virtual Engine* createEngine() = 0;
    virtual Car* createCar() = 0;
};

class JapaneseFactory: public Factory{
public:
    Engine* createEngine() override;

    Car* createCar() override;
};

class RussianFactory: public Factory{
public:
    Engine* createEngine()override;

    Car* createCar()override;
};











































