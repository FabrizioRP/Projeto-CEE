class Motor {
    public:
        uint8_t porta11 = 100, porta21 = 100, porta12 = 100, porta22 = 100;//armazena as portas para cada motor

        Motor(uint8_t port11, uint8_t port21, uint8_t port12, uint8_t port22){//construtor da classe. apenas configura as portas como saída e armazean-as
            porta11 = port11;
            porta21 = port21;//direita

            porta12 = port12;
            porta22 = port22;//esquerda

            pinMode(porta11, OUTPUT);
            pinMode(porta21, OUTPUT);

            pinMode(porta12, OUTPUT);
            pinMode(porta22, OUTPUT);
        }

        void Move(int8_t spd1, int8_t spd2){//funcao q move os motores uma certa velocidade; velocidades entre -100-100
            if (spd1 < 0){
                analogWrite(porta11, round(255*(spd1/100.0)));
                analogWrite(porta21, 0);
            }
            else if (spd1 > 0){
                analogWrite(porta11, 0);
                analogWrite(porta21, round(255*(spd1/100.0)));
            }
            else{
                analogWrite(porta11, 255);
                analogWrite(porta21, 255); 
            }

            if (spd2 < 0){
                analogWrite(porta12, round(255*(spd1/100.0)));
                analogWrite(porta22, 0);
            }
            else if (spd2 > 0){
                analogWrite(porta12, 0);
                analogWrite(porta22, round(255*(spd1/100.0)));
            }
            else{
                analogWrite(porta12, 255);
                analogWrite(porta22, 255);
            }
        }
};