#pragma once

/*
    Фасад
*/
/*
    Маркетплейс и его составные подразделения
*/

namespace fd {

class ProviderCommunication{
public:
    void receive();

    void payment();
};

class Site{
public:
    void placement();

    void del();
};

class DataBase{
public:
    void insert();
    void del();
};

class MarketPlace{
private:
    ProviderCommunication providerCom;
    Site site;
    DataBase database;
public:
    void productReceipt();
    void productRelease();
};
} // namespace fd
