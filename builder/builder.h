#pragma once

/*
    Строитель
    Предоставляет способ создания составного объекта
    Он отделяет коструирование сложного объкта от его представления
    так, что в результате одного и того же процесса коструирования
    могут получаться разные представления
    +Позволяет изменять внутренее представление продукта,
    изолирует код реализующий конструирование и представление
    Дает более тонкий контроль над процессом конструирования
    Алгоритм создания сложного объекта не должен зависеть от того
    из каких частей состоит объект и как они стыкуются между собой

*/

#include <string>

namespace nb {

class Phone{
    std::string data;
public:
    std::string aboutPhone();
    void appendData(std::string d);
};

class Developer{
public:
    virtual void createDisplay() = 0;
    virtual void createBox() = 0;
    virtual void systemInstall() = 0;

    virtual Phone* getPhone() = 0;
};

class AndroidDeveloper: public Developer{
private:
    Phone* phone;
public:
    AndroidDeveloper();
    ~AndroidDeveloper();
    void createDisplay() override;
    void createBox() override;
    void systemInstall() override;
    Phone *getPhone() override;
};

class IphoneDeveloper: public Developer{
private:
    Phone* phone;
public:
    IphoneDeveloper();
    ~IphoneDeveloper();
    void createDisplay() override;
    void createBox() override;
    void systemInstall() override;
    Phone *getPhone() override;
};

class Director{
    Developer* developer;
public:
    Director(Developer* dev);

    void setDeveloper(Developer* dev);

    Phone* MountOnlyPhone();
    Phone* MountFullPhone();


};

} // namespace nb
