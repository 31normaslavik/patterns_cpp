#include "facade.h"
#include <iostream>


void fd::ProviderCommunication::receive(){
    std::cout<<"Получение продукции"<<std::endl;
}

void fd::ProviderCommunication::payment(){
    std::cout<<"Оплата поставщику с удержанием комиссии "
                 "за продажу продукции"<<std::endl;
}

void fd::Site::placement(){
    std::cout<<"Размещение на сайте"<<std::endl;
}

void fd::Site::del(){
    std::cout<<"Удаление с сайта"<<std::endl;
}

void fd::DataBase::insert(){
    std::cout<<"Запись в базу данных"<<std::endl;
}

void fd::DataBase::del(){
    std::cout<<"Удаление из базы данных"<<std::endl;
}

void fd::MarketPlace::productReceipt(){
    providerCom.receive();
    site.placement();
    database.insert();
}

void fd::MarketPlace::productRelease(){
    providerCom.payment();
    site.del();
    database.del();
}
