#include "prototype.h"


void Animal::setName(std::string *name){}

Sheep::Sheep(const Sheep &donor){
    this->name = donor.name;
}

Sheep::~Sheep(){
    delete name;
}

std::string Sheep::getName() {
    return *name;
}

Sheep *Sheep::clone() const{
    return new Sheep(*this);
}

void Sheep::setName(std::string *name){
    this->name = name;
}
