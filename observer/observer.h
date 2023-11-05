#pragma once

/* НАБЛЮДАТЕЛЬ

   Система наблюдения за ценой товара
    на события изминения которой подписанны:
    Оптовый закупщик и обычный покупатель

*/

#include <vector>

/*
    Интерфейс наблюдателя
*/
class Observer {
public:
    virtual void update(double p) = 0;
};


/*
    Интерфейс наблюдаемого объекта
*/
class Observable {
public:
    // Добавление наблюдателя
    virtual void addObserver(Observer *o) = 0;

    // Удаление наблюдателя
    virtual void removeObserver(Observer *o) = 0;


    virtual void notify() = 0;
    virtual ~Observable() = default;
};


/*
    Объект наблюдаемого объекта
    Представляет собой цену за которой будут
    следить наблюдатели
*/
class Product : public Observable {
private:
    // Вектор наблюдателей
    std::vector<Observer *> observers;

    // Цены товаров
    double price;

public:
    Product(double p);

    void changePrice(double p);

    // Добавление наблюдателя
    void addObserver(Observer *o) override;

    // Удаление наблюдателя
    void removeObserver(Observer *o) override;

    // Уведомление всех наблюдателей о изминении цены на товар
    void notify() override;
};

// Оптовый покупатель
class Wholesaler : public Observer {
private:
    // Продукт за которым осуществляется наблюдение
    Observable *product;

public:
    // Передается наблюдаемый объект
    Wholesaler(Observable *obj);

    void update(double p) override;
};

// Покупатель
class Buyer : public Observer {
private:
    // Продукт за которым осуществляется наблюдение
    Observable *product;

public:
    // Передается наблюдаемый объект
    Buyer(Observable *obj);

    void update(double p) override;
};
