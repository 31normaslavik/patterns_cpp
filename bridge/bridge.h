#pragma once

/*
    Мост
    Разделяет абстракцию и реализацию так
    чтобы они могли изменяться независимо
    Шаблон мост использует инкапсуляцию, агрегирование и
    может использовать наследование для того чтобы разделить
    ответственность между классами
*/

/*
    Чтение данных из различных хранилищ и передачу их в сеть
    различными способами
*/

class DataReader{
public:
    virtual void read() = 0;
};

// Имитация чтения данных
class DataBaseReader: public DataReader{
public:
    void read()override;
};

class FileReader: public DataReader{
public:
    void read()override;
};

class Sender{
protected:
    DataReader* reader;
public:
    Sender(DataReader* dr);
    void setDataReader(DataReader* dr);

    virtual void send() = 0;
};

class EmailSander: public Sender{
public:
    EmailSander(DataReader* dr);
    void send()override;

};


class TelegramBotSander: public Sender{
public:
    TelegramBotSander(DataReader* dr);
    void send()override;

};
































