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
    prototype/prototype.h prototype/prototype.cpp )

include(GNUInstallDirs)
install(TARGETS pattern_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
