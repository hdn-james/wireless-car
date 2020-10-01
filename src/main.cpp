#include "control.h"

void setup()
{
  initialize();
  Asynchronous::get_instance()->initialize();
  wireless_task = new Task(100UL, wireless_controller);
  light_task = new Task(100UL, led_controller);
  motor_task = new Task(100UL, motor_controller);
  Serial.begin(9600);
}

void loop()
{
  Asynchronous::get_instance()->update();

  wireless_task->update();
  light_task->update();
  motor_task->update();

  Asynchronous::get_instance()->reset_tick();
}
