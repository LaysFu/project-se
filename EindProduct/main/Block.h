#include "Zumo32U4ProximitySensors.h"
#include "readLine.h"
#include "Zumo32U4Motors.h"

class Block{
    private:
        Zumo32U4ProximitySensors proxySensy;
        readLine& blockRL;
        Zumo32U4Motors motor;

        

        // Sensor Variables
        // 0 = geen obstakel
        // 6 = obstakel heel dichtbij    
        int left_sensor;
        int right_sensor;

        // bool voor logic
        bool blockLinedUp = false;

        // lees line sensors uit
        //void readLineSensors();
        // als blockLinedUp en line geregistreerd stop
        //bool checkWin();

    public: 
        Block();
        ~Block() = default;

        // staat block aan
        bool status = false;
        // vind het block door area te scannen
        bool findBlock();
        // zorg dat je niet over de line gaat
        //void avoidLine();
        // als block gevonden is zorgen dat je er goed voor komt te staan
        void lineUpBlock();
        // als blockLinedUp duw block 
        void pushBlock();
        // lees prox sensors uit
        void readProxySensors();
        
};
