#ifndef BUZZER_H
#define BUZZER_H

#include <Zumo32U4Buzzer.h>
#include <Arduino.h>


class Buzzer : public Zumo32U4Buzzer{

    public:
        void playSong();
        void stopSong();
        void melodyOne();
        void melodyTwo();
        void melodyThree();
        static const char song[] PROGMEM;
};

#endif