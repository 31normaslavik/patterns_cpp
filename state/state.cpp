#include "state.h"
#include <iostream>


void State::setTrafficLight(TrafficLight *tl){
    trafficlight = tl;
}

TrafficLight::TrafficLight(State *st): state{nullptr}{
    setState(st);
}

void TrafficLight::setState(State *st){
    if(state!= nullptr){
        delete state;
    }
    state = st;
    state->setTrafficLight(this);
}

void TrafficLight::nextState(){
    state->nextState();
}

void TrafficLight::previousState(){
    state->previousState();
}

void GreenState::nextState(){
    std::cout<<"Из зеленого в желтый цвет"<<std::endl;
    trafficlight->setState(new YellowState());
}

void GreenState::previousState(){
    std::cout<<"Зеленый цвет"<<std::endl;
}

void YellowState::previousState(){
    std::cout<<"Из желтого в зеленый цвет"<<std::endl;
    trafficlight->setState(new GreenState());
}

void RedState::nextState(){
    std::cout<<"Красный цвет"<<std::endl;
}

void RedState::previousState(){
    std::cout<<"Из красного в желтый цвет"<<std::endl;
    trafficlight->setState(new YellowState());
}

void YellowState::nextState(){
    std::cout<<"Из желтого в красный цвет"<<std::endl;
    trafficlight->setState(new RedState());
}
