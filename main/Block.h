#include "Zumo32U4ProximitySensors.h"
#include "readLine.h"
#include "Motors.h"

class Block{
    private:
        Zumo32U4ProximitySensors proxySensy;
        readLine& blockRL;
        Motors motor;

        /* Sensor Variables
         0 = geen obstakel
         6 = obstakel heel dichtbij */   
        int left_sensor, right_sensor;     
        // bool voor logic
        bool blockLinedUp;

        // lees prox sensors uit
        void readProxySensors();
        // lees line sensors uit
        void readLineSensors();

    public: 
        Block(readLine&);
        ~Block() = default;

        // staat block aan
        bool status = false;
        // vind het block door area te scannen
        bool findBlock();
        // als block gevonden is zorgen dat je er goed voor komt te staan
        void lineUpBlock();
        // als blockLinedUp duw block 
        void pushBlock();
        // als blockLinedUp en line geregistreerd stop
        bool checkWin();
        
};
