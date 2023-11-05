#pragma once
/*
    Декоратор
*/

// Формирование данных для передачи по каналу связи

#include <string>
class Processor{
public:
    virtual void process()=0;
};

class Transmitter : public Processor{
private:
    std::string data;
public:
    Transmitter(std::string d);

    void process() override;

};

class Shell : public Processor{
protected:
    Processor* processor;
public:
    Shell(Processor* pr);
    void process() override;

};


class HammingCoder: public Shell{
public:
    HammingCoder(Processor* pr);

    void process()override;

};

class Encryptor: public Shell{
public:
    Encryptor(Processor* pr);
    void process()override;
};



































