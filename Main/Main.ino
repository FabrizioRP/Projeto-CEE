#include<Ultrasonic.h>
#include "Motor.h"
#include "Sensor.h"
#include "Naveg.h"

Motor motor(11, 10, 6, 5);
Sensor sensor(7, 8, 9, 12, 13);

uint8_t ind = 1, deg = 0;

void Sweep();

void setup() {
    Serial.begin(9600);
}

void loop() {
    Sweep();
    Serial.print(sensor.Ult(1));
    Serial.print("          ");
    Serial.println(sensor.Ult(2));
}

void Sweep(){
    deg+= (ind*15);

    if (deg >= 200) ind = -1;
    else if (deg <= 00) ind = 1; 

    sensor.Servo(deg);

    delay(110);
}
