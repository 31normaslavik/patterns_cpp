#include "strategy.h"
#include <iostream>
#include <ostream>

ResourceReader::ResourceReader(Reader *rd): reader{rd}{}

ResourceReader::~ResourceReader(){
    delete reader;
}

void ResourceReader::setStrategy(Reader *rd){
    if(rd != nullptr) delete reader;
    reader = rd;
}

void ResourceReader::read(std::string &url){
    reader->parse(url);
}

void NewsSiteReader::parse(std::string &url){
    std::cout<<"Парсинг с новостного сайта: "<< url<<std::endl;
}

void SocialNetworkReader::parse(std::string &url){
    std::cout<<"Парсинг ленты новостей социальной сети: "<< url<<std::endl;
}

void TelegramChannelReader::parse(std::string &url){
    std::cout<<"Парсинг канала мессенджера Telegram: "<< url<<std::endl;
}
