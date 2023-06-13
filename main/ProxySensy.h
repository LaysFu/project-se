#ifndef PROXYSENSY_H
#define PROXYSENSY_H

#include <Zumo32U4LineSensors.h>

class ProxySensy : public Zumo32U4ProximitySensors {
    private: 

      /*Sensor Variables
        0 = geen obstakel
        6 = obstakel heel dichtbij*/   
        int left_sensor, right_sensor;  

    public:
        ProxySensy();
        ~ProxySensy() = default;
        int left();
        int right()
        void readProxySensors()
        
}

#endif // PROXYSENSY_H