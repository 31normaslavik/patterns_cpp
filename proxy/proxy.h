#pragma once

/*
    Заместитель
*/

// Имитация работы веб браузера

#include <map>
#include <string>
class ISite{
public:
    virtual std::string getPage(int num)=0;
    virtual ~ISite() = default;
};

class Site: public ISite{
public:
    std::string getPage(int num) override{
        return std::string("Это страница сайта "
                           + std::to_string(num));
    }
};


class SiteProxy: public ISite{
private:
    ISite* site;
    std::map<int,std::string> cache;
public:
    SiteProxy(ISite* site): site{site}{}
    ~SiteProxy(){
        delete site;
    }

    std::string getPage(int num)override{
        std::string page;
        if(cache.find(num) == cache.end()){
            page = site->getPage(num);
            cache[num] = page;
        }else{
            page = cache[num];
            page.insert(0,"из кэша: ");
        }
        return page;
    }

};
