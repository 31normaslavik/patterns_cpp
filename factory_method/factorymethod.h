#pragma once

/*
    Фабричный метод
    Предоставляет дочерним классам интерфейс для создания экземпляров
    некоторого класса
    В момент создания наследники могут определить какой
    класс создавать
    Иными словами - Данный шаблон делегирует создание объектов
    наследникам родительского класса
    Это позволяет использовать в коде программы неспецифические
    классы, а манипулировать абстрактными объектами на более
    высоком уровне
    +Позволяет делать код создания объекта более универсальным
    не привязываясь к конкретным классам, оперируя лишь
    общим интерефейсом
    Позволяет установить связь между паралельными иерархиями
    классов
    -Необходимость создавать наследника для каждого нового типа
*/

namespace fm{

class Production{
public:
    virtual void release() = 0;
};

class Car: public Production{
public:
    void release() override;
};

class Truck: public Production{
public:
    void release() override;
};

class WorkShop{
public:
    virtual Production* create() = 0;
};

class CarWorkShop: public WorkShop{
public:
    Production *create() override;
};

class TruckWorkShop: public WorkShop{
public:
    Production *create() override;
};

} // fm






















