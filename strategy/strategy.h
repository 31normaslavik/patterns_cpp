#pragma once

/*
    Стратегия
    Определяет семейство схожих алгоритмов и помещает
    каждый из них в собственный класс
    +Паттерн изолирует код алгоритмов от остальных классов
    Алгоритмы можно быстро заменять во время выполнения программы

*/

/*
    Система сбора новостей с различных информационных ресурсов
    Применяет к каждому из них свою стратегию
*/


#include <string>
class Reader{
public:
    virtual ~Reader() = default;
    virtual void parse(std::string& url) = 0;
};

class ResourceReader{
private:
    Reader* reader;
public:
    ResourceReader(Reader* rd);
    ~ResourceReader();

    void setStrategy(Reader* rd);

    void read(std::string& url);
};

class NewsSiteReader: public Reader{
public:
    void parse(std::string &url) override;
};

class SocialNetworkReader: public Reader{
public:
    void parse(std::string &url) override;
};

class TelegramChannelReader: public Reader{
public:
    void parse(std::string &url) override;
};

























