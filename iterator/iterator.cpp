#include "iterator.h"


DataStack::DataStack(): lenght{-1}{}

void DataStack::push(int value){
    items[++lenght] = value;
}

int DataStack::pop(){
    return items[lenght--];
}

StackIterator::StackIterator(const DataStack &st): stack{st}, index{0}{}

void StackIterator::operator++(){
    index++;
}

int StackIterator::operator*(){
    return stack.items[index];
}

bool StackIterator::operator()(){
    return index != stack.lenght + 1;
}

bool operator==(const DataStack &s1, const DataStack &s2){
    StackIterator it1(s1), it2(s2);

    for(; it1(); ++it1, ++it2){
        if(*it1 != *it2) break;
    }
    return !it1() && !it2();
}
