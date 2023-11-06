#include "visitor.h"

void Zoo::accept(Visitor &v){
    v.visit(*this);
}

void Cinema::accept(Visitor &v){
    v.visit(*this);
}

void Circus::accept(Visitor &v){
    v.visit(*this);
}

void HollidayMaker::visit(Zoo &ref){
    value = "Слон в зоопарке";
}

void HollidayMaker::visit(Cinema &ref){
    value = "Кино - Властелин колец";
}

void HollidayMaker::visit(Circus &ref){
    value = "Клоун в цирке";
}
