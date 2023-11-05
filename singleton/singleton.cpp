#include "singleton.h"
#include <iostream>

DatabaseHelper::DatabaseHelper(){
    std::cout<<"Подключение к бд"<<std::endl;
}

DatabaseHelper *DatabaseHelper::getConnection(){
    if (databaseConnection == nullptr)
        databaseConnection = new DatabaseHelper();
    return databaseConnection;
}

std::string DatabaseHelper::selectData() const {
    return data;
}

void DatabaseHelper::insertData(std::string d){
    std::cout<< "Новые данные: "<< d<<" внесены в бд"<<std::endl;
    data = d;
}
