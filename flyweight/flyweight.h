#pragma once

/*
    Легковес
    Позволяет вместить большее количество объектов в отведеную оперативную память
    Легкосес экономит память выделяя и сохраняя общие параметры объектов
    Однако при использовании данного патерна расходуется процессорное время на поиск,
    а так же из-за введения дополнительных классов усложняется код программы

*/

/*
    Учет представителей разных компаний, прехавших на конференцию
    по IT технологиям
*/

#include <string>
#include <unordered_map>
struct Shared{
    std::string position;
    std::string company;

    Shared(const std::string& company_, const std::string& position_);
};


struct Unique{
    std::string passport;
    std::string name;
    Unique(const std::string& name_, const std::string& passport_);
};

class Flyweight{
private:
    Shared* shared;
public:
    Flyweight(const Shared* shared_);
    Flyweight(const Flyweight& other);

    ~Flyweight();
    void Process(const Unique& unique)const;

};


class FlyweightFactory{
private:
    std::unordered_map<std::string,Flyweight> flyweights;
    std::string GetKey(const Shared& shared)const;

public:
    FlyweightFactory(std::initializer_list<Shared> shareds);

    Flyweight GetFlyweight(const Shared& shared);

    void ListFlyweights()const;


};

void addSpecialistDatabase(FlyweightFactory& ff,
                           const std::string company,
                           const std::string& position,
                           const std::string& name,
                           const std::string& passport);



