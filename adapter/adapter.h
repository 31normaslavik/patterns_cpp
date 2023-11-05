#pragma once

/*
    Адаптер  реализация на уровне классов
    Предназначен для организации использования функции объекта
    не доступного для модификации через специально созданный интерфейс

    Позволяет объектам с несовместимыми интерфейсами работать
    вместе

*/

// Адаптация британских весов измеряющих массу в фунтах
// к российскому весовому номиналу килограмм


class Scales{
public:
    virtual float* getWeight()=0;
    virtual void adjust() = 0;
    virtual ~Scales() = default;
};

class RussianScales: public Scales{
private:
    float* currentWeight;
public:
    RussianScales(float* cw);
    ~RussianScales();

    float* getWeight() override;

    void adjust()override;
};

class BritishScales {
private:
    float* currentWeight;
public:
    BritishScales(float* cw);
    ~BritishScales();

    float* getWeight();

protected:
    void adjust();


};

class AdapterforBritishScales: public Scales, public BritishScales{
private:
    float* cw;
    BritishScales* britishScale;
public:
    AdapterforBritishScales(float* cw);
    AdapterforBritishScales(BritishScales* bs);
    ~AdapterforBritishScales();

    float *getWeight() override;
    void adjust() override;
};





































