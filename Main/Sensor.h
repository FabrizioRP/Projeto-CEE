class Sensor{
    public:
        uint8_t servo, t1, t2, e1, e2;

        Sensor(uint8_t ser, uint8_t ultra1_t, uint8_t ultra2_t, uint8_t ultra1_e, uint8_t ultra2_e){
            servo = ser;
            t1 = ultra1_t;
            t2 = ultra2_t;
            e1 = ultra1_e;
            e2 = ultra2_e;
            
            pinMode(ser, OUTPUT);

            pinMode(ultra1_t ,OUTPUT);
            pinMode(ultra1_e, INPUT);

            pinMode(ultra2_t, OUTPUT);
            pinMode(ultra2_e, INPUT);
        }

        void Servo(int deg = 90){
            int ang = map(deg, 0, 180, 530, 2800);

            digitalWrite(servo, HIGH);
            delayMicroseconds(ang);
            digitalWrite(servo, LOW);
            delayMicroseconds(20000 - ang);
        }

        float Ult(uint8_t num){
            uint8_t trig = (num == 1) ? t1 : t2;
            uint8_t echo = (num == 1) ? e1 : e2;

            int duration = 0;

            float dist = 0;

            digitalWrite(trig, LOW);
            delayMicroseconds(5);
            digitalWrite(trig, HIGH);
            delayMicroseconds(10);
            digitalWrite(trig, LOW);

            duration = pulseIn(echo, HIGH);
            dist = (duration/2) / 29.1;
            
            return dist;
        }
};