#pragma once

/*
    Шаблонный метод
    Определяет основу алгоритма и позволяет наследникам
    переопределять некоторые шаги алгоритма не изменяя
    его структуру в целом
    +Облегчает повторное использование кода
*/

// Передатчик речи который может быть аналоговым и цифровым

namespace tmpm {

class Transmitter{
protected:
    virtual void voiceRecord();
    virtual void simpling();
    virtual void digitization();
    virtual void modulation() = 0;
    virtual void transmission();

public:
    void processStart();

    virtual ~Transmitter() = default;
};

class AnalogTransmitter: public Transmitter{
public:
    void modulation() override;
};

class DigitalTransmitter: public Transmitter{
public:
    void modulation() override;
    void simpling() override;
    void digitization() override;
};

} // namespace tmpm
