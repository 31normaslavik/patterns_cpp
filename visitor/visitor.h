#pragma once

/*
    Посетитель
    Позволяет добавлять в программу новые операции
    не изменяя классы объектов над которыми эти
    операции могут выполняться
    Объеденяет родственные операции в одном классе,
    упрощает добавление операций работающих со сложными структурами
    объектов
    минусы: возможное нарушение инкапсуляции объектов
*/

/*
    Посещение отдыхающим различных мест в городе
*/

#include <string>
class Zoo;
class Cinema;
class Circus;

class Visitor
{
public:
    virtual void visit(Zoo& ref) = 0;
    virtual void visit(Cinema& ref) = 0;
    virtual void visit(Circus& ref) = 0;
    virtual ~Visitor() = default;
};

class Place{
public:
    virtual void accept(Visitor& v) = 0;
    virtual ~Place() = default;
};

class Zoo: public Place{
public:
    void accept(Visitor& v)override;
};

class Cinema: public Place{
public:
    void accept(Visitor& v)override;
};

class Circus: public Place{
public:
    void accept(Visitor& v)override;
};

class HollidayMaker: public Visitor{
public:
    std::string value;
public:
    void visit(Zoo& ref)override;
    void visit(Cinema& ref)override;
    void visit(Circus& ref)override;
};

















