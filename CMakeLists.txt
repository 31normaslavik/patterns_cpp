cmake_minimum_required(VERSION 3.5)

project(pattern_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pattern_cpp main.cpp
    observer/observer.h
    singleton/singleton.h
    abstract_factory/abstractfactory.h
    abstract_factory/abstractfactory.cpp
    observer/observer.cpp
    singleton/singleton.cpp
    adapter/adapter.h adapter/adapter.cpp
    decorator/decorator.h decorator/decorator.cpp
    proxy/proxy.h proxy/proxy.cpp
    iterator/iterator.h iterator/iterator.cpp
    command/command.h command/command.cpp
    composite/composite.h composite/composite.cpp
    flyweight/flyweight.h flyweight/flyweight.cpp
    bridge/bridge.h bridge/bridge.cpp
    visitor/visitor.h visitor/visitor.cpp
    mediator/mediator.h mediator/mediator.cpp
    prototype/prototype.h prototype/prototype.cpp
    memento/memento.h memento/memento.cpp
    state/state.h state/state.cpp
    strategy/strategy.h strategy/strategy.cpp
    builder/builder.h builder/builder.cpp
    factory_method/factorymethod.h factory_method/factorymethod.cpp
    facade/facade.h facade/facade.cpp
    chain_of_responsibility/chainofresponsibility.h chain_of_responsibility/chainofresponsibility.cpp
    template_method/templatemethod.h template_method/templatemethod.cpp )

include(GNUInstallDirs)
install(TARGETS pattern_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
