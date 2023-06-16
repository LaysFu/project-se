#include "buzzer.h"

const char Buzzer::song[] PROGMEM =
  "! V10 O5 L8 T125" 
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16";

void Buzzer::playSong() {
    buzzer.playFromProgramSpace(Buzzer::song);
}

void Buzzer::stopSong() {
    buzzer.stopPlaying();
}