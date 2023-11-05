#pragma once

/*
    Одиночка
    Гарантирует что в приложении будет
    единсвенный экземпляр и предоставляет
    глобальную точку доступа к этому экземпляру
*/

// Класс подключения к датабазе

#include <string>
class DatabaseHelper{
private:
    DatabaseHelper();

    static DatabaseHelper* databaseConnection;

    std::string data;

public:
    DatabaseHelper(const DatabaseHelper &) = delete;
    DatabaseHelper(DatabaseHelper &&) = delete;
    DatabaseHelper &operator=(const DatabaseHelper &) = delete;
    DatabaseHelper &operator=(DatabaseHelper &&) = delete;


    static DatabaseHelper* getConnection();

    std::string selectData() const;

    void insertData(std::string d);

};




