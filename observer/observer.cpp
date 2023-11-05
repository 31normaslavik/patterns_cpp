#include "observer.h"
#include <algorithm>
#include <iostream>


Product::Product(double p) : price{p} {}

void Product::changePrice(double p) {
    price = p;
    notify();
}

void Product::addObserver(Observer *o) { observers.emplace_back(o); }

void Product::removeObserver(Observer *o) {
    observers.erase(std::remove(observers.begin(), observers.end(), o),
                    observers.end());
}

void Product::notify() {
    for (const auto &o : observers)
        o->update(price);
}

Wholesaler::Wholesaler(Observable *obj) : product{obj} {
    // Дабавить экземпляр текущего наблюдателя
    obj->addObserver(this);
}

void Wholesaler::update(double p) {
    if (p < 300) {
        std::cout << "Оптовик закупил товар по цене " << p << std::endl;
        // Удалить наблюдателя
        product->removeObserver(this);
    }
}

Buyer::Buyer(Observable *obj) : product{obj} {
    // Дабавить экземпляр текущего наблюдателя
    obj->addObserver(this);
}

void Buyer::update(double p) {
    if (p < 350) {
        std::cout << "Покупатель закупил товар по цене " << p << std::endl;
        // Удалить наблюдателя
        product->removeObserver(this);
    }
}
