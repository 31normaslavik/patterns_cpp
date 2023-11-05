#include "decorator.h"
#include <iostream>


Transmitter::Transmitter(std::string d): data{d}{}

void Transmitter::process(){
    std::cout<<"Данные "<<data<<" переданы по каналу связи"
              <<std::endl;
}

Shell::Shell(Processor *pr): processor{pr}{}

void Shell::process(){
    processor->process();
}

HammingCoder::HammingCoder(Processor *pr): Shell(pr){}

void HammingCoder::process(){
    std::cout<<"Наложен помехоустойчивый код Хамминга->";
    processor->process();
}

Encryptor::Encryptor(Processor *pr): Shell(pr){}

void Encryptor::process(){
    std::cout<<"Шифрование данных->";
    processor->process();
}
