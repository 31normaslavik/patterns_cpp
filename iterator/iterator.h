#pragma once

/*
    Итератор
    Представляет объект позволяющий получить последовательный
    доступ к элементам объекта агрегата без использования описания
    каждого из агрегированых объектов

*/

class DataStack{
private:
    int items[10];
    int lenght;

public:
    friend class StackIterator;
    DataStack();

    void push(int value);

    int pop();
};


class StackIterator{
private:
    const DataStack& stack;
    int index;
public:
    StackIterator(const DataStack& st);

    void operator++();

    int operator*();

    bool operator()();

};


bool operator==(const DataStack& s1, const DataStack& s2);
























