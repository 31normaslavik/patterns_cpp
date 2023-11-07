#pragma once

/*
    Состояние
    Позволяет объектам менять поведение в зависимости
    от своего состояния
    Паттерн может найти широкое приминение в системах где
    необходимо избавиться от большого количества условных
    операторов
*/

/*
    пример работы светофора
*/

class TrafficLight;

class State{
protected:
    TrafficLight* trafficlight;
public:
    virtual ~State() = default;
    void setTrafficLight(TrafficLight* tl);
    virtual void nextState() = 0;
    virtual void previousState() = 0;
};

class TrafficLight{
private:
    State* state;
public:
    TrafficLight(State* st);

    void setState(State* st);

    void nextState();

    void previousState();
};

class GreenState: public State{
public:
    void nextState() override;
    void previousState() override;
};

class YellowState: public State{
public:
    void nextState() override;
    void previousState() override;
};



class RedState: public State{
public:
    void nextState() override;
    void previousState() override;
};













































