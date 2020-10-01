#include "asynchronous.h"

// Asynchronous
void Asynchronous::initialize()
{
    last_tick = millis();
}

void Asynchronous::update()
{
    current_tick = millis();
}

unsigned long Asynchronous::delta()
{
    return current_tick - last_tick;
}

void Asynchronous::reset_tick()
{
    last_tick = current_tick;
}

// Task
Task::Task(int workPin, unsigned long time, void (*func)(int))
{
    work_pin = workPin;
    work_time = time;
    elapsed_time = 0;
    this->func = func;
}

Task::Task(unsigned long time, void (*func)()) : work_time(time), func2(func), elapsed_time(0), work_pin(-1) {}

Task::~Task()
{
    work_pin = 0;
    work_time = 0;
    elapsed_time = 0;
    func = NULL;
    func2 = NULL;
}

void Task::update()
{
    elapsed_time += Asynchronous::get_instance()->delta();
    if (elapsed_time >= work_time)
    {
        elapsed_time -= work_time;
        if (func != NULL)
        {
            if (work_pin == -1)
                func2();
            else
                func(work_pin);
        }
        else if (func2 != NULL)
            func2();
    }
}