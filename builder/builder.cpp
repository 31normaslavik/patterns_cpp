#include "builder.h"


std::string nb::Phone::aboutPhone(){
    return data;
}

void nb::Phone::appendData(std::string d){
    data+=d;
}

nb::AndroidDeveloper::AndroidDeveloper(): phone{new Phone}{}

nb::AndroidDeveloper::~AndroidDeveloper(){delete phone;}

void nb::AndroidDeveloper::createDisplay(){
    phone->appendData("Произведен дисплей Samsung; ");
}

void nb::AndroidDeveloper::createBox(){
    phone->appendData("Произведен корпус Samsung; ");

}

void nb::AndroidDeveloper::systemInstall(){
    phone->appendData("Установлена система Android; ");

}

nb::Phone *nb::AndroidDeveloper::getPhone(){
    return phone;
}

nb::IphoneDeveloper::IphoneDeveloper(): phone{new Phone}{}

nb::IphoneDeveloper::~IphoneDeveloper(){delete phone;}

void nb::IphoneDeveloper::createDisplay(){
    phone->appendData("Произведен дисплей Apple; ");
}

void nb::IphoneDeveloper::createBox(){
    phone->appendData("Произведен корпус Apple; ");

}

void nb::IphoneDeveloper::systemInstall(){
    phone->appendData("Установлена система IOS; ");

}

nb::Phone *nb::IphoneDeveloper::getPhone(){
    return phone;
}

nb::Director::Director(Developer *dev): developer{dev}{}

void nb::Director::setDeveloper(Developer *dev){
    developer = dev;
}

nb::Phone *nb::Director::MountOnlyPhone(){
    developer->createBox();
    developer->createDisplay();
    return developer->getPhone();
}

nb::Phone *nb::Director::MountFullPhone(){
    developer->createBox();
    developer->createDisplay();
    developer->systemInstall();
    return developer->getPhone();
}
