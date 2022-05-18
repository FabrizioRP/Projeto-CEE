#include "Motor.h"
#include "Sensor.h"

#define buz 3
#define minDist 30

Motor motor(11, 10, 6, 5);
Sensor sensor(7, 8, 9, 12, 13);

uint8_t ind = 1, deg = 0;

int arr[24] = {};

void Fill();

void JustGo();

void Rotate(int deg);

void setup() {
    Serial.begin(9600);
    for (int k=0; k<12; k++) Fill();
}

void loop() {
    Fill();
    JustGo();
}

void Fill(){
    deg+= (ind*15);

    if (deg >= 180) ind = -1;
    else if (deg <= 00) ind = 1; 

    sensor.Servo(deg);

    float med1 = 0, med2 = 0;

    arr[deg/15] = sensor.Ult(2);
    arr[24-(deg/15)] = sensor.Ult(1);

    delay(70);
}

void Rotate(int deg){
    int8_t spd  = 50*(deg/abs(deg));

    motor.Move(spd, -1*spd);

    delay(abs(deg)*7);

    motor.Move(0, 0);
    delay(100);
}

void JustGo(){
    uint8_t prio[4] = {12, 6, 18, 0};

    if (arr[12] > minDist && arr[11] > minDist && arr[10] > minDist) motor.Move(70, 70);

    else if (arr[6] > minDist && arr[5] > minDist && arr[7] > minDist) {
        Rotate(90);
        for (int k=0; k<12; k++) Fill();
    }

    else if (arr[18] > minDist && arr[17] > minDist && arr[19] > minDist) {
        Rotate(-90);
        for (int k=0; k<12; k++) Fill();
    }

    else if (arr[0] > minDist && arr[23] > minDist && arr[1] > minDist){
        Rotate(90);
        Rotate(90);
        for (int k=0; k<12; k++) Fill();
    }

    else tone(buz, 440, 50);
}