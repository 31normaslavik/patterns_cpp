#pragma once

/*
    Компоновщик
    Объеденяющий объекты в древовидную структуру для представления
    иерархии
    Позволяет обращаться к отдельным объектам и группам объектов одинаково

*/

// Меню программы

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Item{
protected:
    std::string itemName;
    std::string ownerName;
public:
    Item(std::string name): itemName{name}{}

    void setOwner(std::string owner){
        ownerName = owner;
    }

    virtual void add(Item* subItem) = 0;
    virtual void remove(Item* subItem) = 0;

    virtual void display() = 0;
};

class ClickableItem: public Item{
public:
    ClickableItem(std::string name): Item(name){}

    void add(Item* subItem)override{
        throw std::exception();
    }

    void remove(Item* subItem) override{
        throw std::exception();
    }

    void display()override{
        std::cout<<itemName<<std::endl;
    }
};

class DropDownItem: public Item{
private:
    std::vector<Item*> children;
public:
    DropDownItem(std::string name): Item(name){}

    void add(Item* subItem) override{
        subItem->setOwner(this->itemName);
        children.push_back(subItem);
    }

    void remove(Item* subItem)override{
        children.erase(std::remove(children.begin(), children.end(), subItem)
                       , children.end());
    }

    void display()override{
        for(const auto& child: children){
            if(ownerName != "")
                std::cout<<ownerName;
            child->display();
        }
    }

};












