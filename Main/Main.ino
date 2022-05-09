#include "Motor.h"

Motor motor(11, 10, 6, 5);

void setup() {
    
}

void loop() {
    motor.Move(100, 100);//56 mais rapido 
}
