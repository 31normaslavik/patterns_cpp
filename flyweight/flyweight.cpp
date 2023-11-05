#include "flyweight.h"
#include <iostream>


Shared::Shared(const std::string &company_, const std::string &position_):
    company{company_}, position{position_}{}

Unique::Unique(const std::string &name_, const std::string &passport_):
    name{name_}, passport{passport_}{}

Flyweight::Flyweight(const Shared *shared_): shared{new Shared(*shared_)}{}

Flyweight::Flyweight(const Flyweight &other): shared{new Shared(*other.shared)}{}

Flyweight::~Flyweight(){
    delete shared;
}

void Flyweight::Process(const Unique &unique) const{
    std::cout<<"Отображаем новые данные: общее - "<<shared->company<<"_"
              << shared->position<<" и уникальное - "<< unique.name<<"_"
              <<unique.passport<<")."<<std::endl;
}

std::string FlyweightFactory::GetKey(const Shared &shared) const{
    return shared.company + "_" + shared.position;
}

FlyweightFactory::FlyweightFactory(std::initializer_list<Shared> shareds){
    for (const auto& shared : shareds) {
        this->flyweights.insert(std::make_pair(this->GetKey(shared),
                                               Flyweight(&shared)));
    }
}

Flyweight FlyweightFactory::GetFlyweight(const Shared &shared){
    std::string key = this->GetKey(shared);
    if(this->flyweights.find(key) == this->flyweights.end()){
        std::cout<<"Фабрика легковесов: Общий объект по ключу "<<key
                  <<" не найден. Создаем новый."<<std::endl;
        this->flyweights.insert(std::make_pair(key,Flyweight(&shared)));
    }else{
        std::cout<<"Фабрика легковесов: извлекаем данные из записей по ключу "
                  << key<<"."<<std::endl;
    }
    return this->flyweights.at(key);

}

void FlyweightFactory::ListFlyweights() const{
    size_t count = this ->flyweights.size();
    std::cout<<std::endl << "Фабрика легковесов: Всего "
              <<count<<" записей"<<std::endl;
        for(std::pair<std::string,Flyweight> pair: this->flyweights){
        std::cout<<pair.first<<std::endl;

    }
}

void addSpecialistDatabase(FlyweightFactory &ff, const std::string company, const std::string &position, const std::string &name, const std::string &passport){

    std::cout<<std::endl;
    const Flyweight& flyweight = ff.GetFlyweight({company,position});
    flyweight.Process({name,passport});


}
