#pragma once
#include <string>


/*
    Прототип
    Позволяет копировать объекты не вдаваясь в подробности
    их реализации
    Позволяет клонировать объекты не привязываясь к их конкретным
    классам, уменьшая повторяющийся код при инициализации объектов.
    Однако составные объекты, имеющие ссылки на другие классы
    клонировать сложнее
*/

/*
    Клонирование овечки Долли
*/

class Animal{
public:
    virtual void setName(std::string* name);
    virtual std::string getName() = 0;
    virtual Animal* clone() const = 0;
};

class Sheep: public Animal{
private:
    std::string* name;
    Sheep(const Sheep& donor);

public:
    Sheep() = default;
    ~Sheep();

    std::string getName() override;
    Sheep *clone() const override;

    void setName(std::string *name) override;
};
