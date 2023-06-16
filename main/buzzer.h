#ifndef BUZZER_H
#define BUZZER_H

#include <Zumo32U4Buzzer.h>
#include <Arduino.h>


class Buzzer : public Zumo32U4Buzzer{

    //Declareren van alle functies en aangemaakte melodieen.
    public:
        void playSong();
        void stopSong();
        void melodyOne();
        void melodyTwo();
        void melodyThree();
        void melodyFour();
        void C();
        void D();
        void E();
        static const char melOne[] PROGMEM;
        static const char melTwo[] PROGMEM;
        static const char melThree[] PROGMEM;
        static const char melFour[] PROGMEM;
        static const char toneC[] PROGMEM;
        static const char toneD[] PROGMEM;
        static const char toneE[] PROGMEM;
        static const char song[] PROGMEM;
};

#endif
