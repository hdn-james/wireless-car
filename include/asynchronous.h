#ifndef _ASYNCHRONOUS_H_
#define _ASYNCHRONOUS_H_

#include "initialize.h"

class Asynchronous
{
private:
    unsigned long last_tick;
    unsigned long current_tick;

    Asynchronous() {}
    ~Asynchronous() {}

public:
    static Asynchronous *get_instance()
    {
        static Asynchronous *instance = new Asynchronous();
        return instance;
    }
    void initialize();
    void update();
    unsigned long delta();
    void reset_tick();
};

class Task
{
private:
    unsigned long elapsed_time;
    unsigned long work_time;
    int work_pin;
    void (*func)(int);
    void (*func2)();

public:
    Task(int, unsigned long, void (*func)(int));
    Task(unsigned long, void (*func)());
    ~Task();

    void update();
};

#endif /* _ASYNCHRONOUS_H_ */