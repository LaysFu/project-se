#include <iostream>
#include "Zumo32U4ProximitySensors.h"
#include "Zumo32U4LineSensors.h"
#include "Zumo32U4Motors.h"

class Block{
    private:
        Zumo32U4ProximitySensors proxySensy;
        Zumo32U4LineSensors linySensy;
        Zumo32U4Motors motor;

        // staat block aan
        bool status = false;;

        // sensors
        int cleft_sensor = 0;
        int left_sensor = 0;
        int cright_sensor = 0;
        int right_sensor = 0;
        unsigned int line_sensor[3];

        // bool voor logic
        bool blockLinedUp = false;
        bool lineSensor = false;

        // lees prox sensors uit
        void readProxySensors();
        // lees line sensors uit
        void readLineSensors();
        // als blockLinedUp en line geregistreerd stop
        bool checkWin();

    public: 
        Block();
        ~Block() = default;

        // vind het block door area te scannen
        bool findBlock();
        // zorg dat je niet over de line gaat
        void avoidLine();
        // als block gevonden is zorgen dat je er goed voor komt te staan
        void lineUpBlock();
        // als blockLinedUp duw block 
        void pushBlock();
        
};
