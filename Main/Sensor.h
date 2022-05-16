class Sensor{
    public:
        uint8_t servo, t1, t2, e1, e2;

        Sensor(uint8_t ser, uint8_t ultra1_t, uint8_t ultra1_e, uint8_t ultra2_t, uint8_t ultra2_e){
            servo = ser;
            t1 = ultra1_t;
            e1 = ultra1_e;

            t2 = ultra2_t;
            e2 = ultra2_e;
            
            pinMode(ser, OUTPUT);

            pinMode(t1 ,OUTPUT);
            pinMode(e1, INPUT);

            pinMode(t2, OUTPUT);
            pinMode(e2, INPUT);
        }

        void Servo(int deg = 70){//70 eh mais ou menos meio
            int ang = map(deg, 0, 180, 600, 2400);

            digitalWrite(servo, HIGH);
            delayMicroseconds(ang);
            digitalWrite(servo, LOW);
            delayMicroseconds(20000 - ang);
        }

        float Ult(uint8_t num){
            uint8_t trig = 0;
            uint8_t echo = 0;
            if (num == 1) trig = t1;
            else trig = t2;

            if (num == 1) echo = e1;
            else echo = e2;

            int duration = 0;

            float dist = 0;

            digitalWrite(trig, LOW);
            delayMicroseconds(2);
            digitalWrite(trig, HIGH);
            delayMicroseconds(10);
            digitalWrite(trig, LOW);

            duration = pulseIn(echo, HIGH);
            dist = (duration/2) / 29.1;
            
            return dist;
        }
};