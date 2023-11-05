#include "abstract_factory/abstractfactory.h"
#include "adapter/adapter.h"
#include "command/command.h"
#include "composite/composite.h"
#include "decorator/decorator.h"
#include "flyweight/flyweight.h"
#include "iterator/iterator.h"
#include "observer/observer.h"
#include "proxy/proxy.h"
#include "singleton/singleton.h"
#include <iostream>

DatabaseHelper* DatabaseHelper::databaseConnection = nullptr;

int main()
{
    using namespace std;

    // НАБЛЮДАТЕЛЬ /////////////////////

    Product *product = new Product(400);

    Wholesaler* wholesaler = new Wholesaler(product);

    Buyer* buyer = new Buyer(product);


    product ->changePrice(320);
    product ->changePrice(280);
    cout<<endl;

    ////////////////////////////////////


    // Одиночка ////////////////////////


    //DatabaseHelper* connection = new DatabaseHelper();

    DatabaseHelper::getConnection()->insertData("321");

    std::cout<< DatabaseHelper::getConnection()->selectData()<<std::endl;

    cout<<endl;
    ////////////////////////////////////


    // Абстрактная фабрика //////////////

    Factory* jfactory = new JapaneseFactory();

    Engine* jengine = jfactory->createEngine();
    Car* jcar = jfactory->createCar();

    jcar->releaseCar(jengine);

    Factory* rfactory = new RussianFactory();

    Engine* rengine = rfactory->createEngine();
    Car* rcar = rfactory->createCar();

    rcar->releaseCar(rengine);

    cout<<endl;

    ///////////////////////////////////////////////////////


    // Адаптер реализация на уровне классов ///////////////////////////////////////////

    float kg = 55.0; // кг
    float lb = 55.0;  // фунты

    Scales* rScales = new RussianScales(&kg);
    //Scales* bScales = new AdapterforBritishScales(&lb);
    Scales* bScales = new AdapterforBritishScales(new BritishScales(&lb));

    cout<<*rScales->getWeight()<<endl;
    cout<<*bScales->getWeight()<<endl;

    rScales->adjust();
    bScales->adjust();

    cout<<endl;

    //////////////////////////////////////////////////////


    // Декоратор ////////////////////////////////////////

    Processor* transmitter = new Transmitter("12355");
    transmitter->process();

    Shell* hammingCoder = new HammingCoder(transmitter);
    hammingCoder->process();

    Shell* encryptor = new Encryptor(transmitter);
    encryptor->process();

    cout<<endl;

    /////////////////////////////////////////////////////

    // Заместитель //////////////////////////////////////

    ISite* mySite = new SiteProxy(new Site());

    cout<< mySite->getPage(1)<<endl;
    cout<< mySite->getPage(2)<<endl;
    cout<< mySite->getPage(4)<<endl;
    cout<< mySite->getPage(1)<<endl;
    cout<< mySite->getPage(4)<<endl;

    cout<<endl;

    /////////////////////////////////////////////////////

    // Итератор /////////////////////////////////////////

    DataStack stack1;

    for(int i = 1; i<5; i++){
        stack1.push(i);
    }

    DataStack stack2(stack1);

    cout<<boolalpha<<(stack1 == stack2)<<endl;

    stack1.push(10);

    cout<<boolalpha<<(stack1 == stack2)<<endl;

    cout<<endl;

    /////////////////////////////////////////////////////

    // Команда //////////////////////////////////////////

    Conveyor* conveyor = new Conveyor();

    MultiPult* multipult = new MultiPult();
    multipult->setCommand(0,new ConveyorWorkCommand(conveyor));
    multipult->setCommand(1,new ConveyorAdjustCommand(conveyor));

    multipult->pressOn(0);
    multipult->pressOn(1);

    multipult->pressCancel();
    multipult->pressCancel();

    cout<<endl;

    /////////////////////////////////////////////////////


    // Компоновщик //////////////////////////////////////

    Item* file = new DropDownItem("File->");

    Item* create = new DropDownItem("Create->");
    Item* open = new DropDownItem("Open->");
    Item* exit = new ClickableItem("Exit");

    file->add(create);
    file->add(open);
    file->add(exit);

    Item* project= new ClickableItem("Projekt...");
    Item* repository = new ClickableItem("Repository...");

    create->add(project);
    create->add(repository);

    Item* solution = new ClickableItem("Solution...");
    Item* folder = new ClickableItem("Folder...");

    open->add(solution);
    open->add(folder);

    file->display();
    cout<<endl;

    file->remove(create);

    file->display();

    cout<<endl;

    /////////////////////////////////////////////////////

    // Легковес /////////////////////////////////////////

    FlyweightFactory* factory = new FlyweightFactory({
        {"Microsoft", "Управляющий"},
        {"Google", "Android-разработчик"},
        {"Google", "Web-разработчик"},
        {"Apple", "Iphone-разработчик"}});
    factory->ListFlyweights();

    addSpecialistDatabase(*factory,
                          "Google",
                          "Web-разработчик",
                          "Борис",
                          "AM-234234234");

    addSpecialistDatabase(*factory,
                          "Apple",
                          "управляющий",
                          "Александр",
                          "ВУ-23423423");

    factory->ListFlyweights();

    delete factory;

    cout<<endl;


    /////////////////////////////////////////////////////

    return 0;
}
