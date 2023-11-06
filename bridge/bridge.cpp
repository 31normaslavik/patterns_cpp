#include "bridge.h"
#include <iostream>



void DataBaseReader::read(){
    std::cout<<"Данные из базы данных ";
}

void FileReader::read(){
    std::cout<<"Данные из файла ";
}

Sender::Sender(DataReader *dr): reader{dr}{}

void Sender::setDataReader(DataReader *dr){
    reader = dr;
}

EmailSander::EmailSander(DataReader *dr): Sender(dr){}

void EmailSander::send(){
    reader->read();
    std::cout<<" отправлены при помощи Email"<<std::endl;
}

TelegramBotSander::TelegramBotSander(DataReader *dr): Sender(dr){}

void TelegramBotSander::send(){
    reader->read();
    std::cout<<" отправлены при помощи Telegram Bot"
              <<std::endl;
}
