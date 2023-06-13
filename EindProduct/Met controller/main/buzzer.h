#include <Zumo32U4.h>
#include <Arduino.h>

#ifndef BUZZER_H
#define BUZZER_H

class Buzzer {

public:
    void playSong();
    void stopSong();
    static const char song[] PROGMEM;

private:
    Zumo32U4Buzzer buzzer;
};

#endif