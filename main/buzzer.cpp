#include "buzzer.h"

const char Buzzer::song[] PROGMEM =
  "! V10 O5 L8 T125" 
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16";

const char Buzzer::melOne[] PROGMEM =
  "! V10 O5 L8 T125"
  "ceg";

const char Buzzer::melTwo[] PROGMEM =
  "! V10 O5 L8 T125"
  "gec";

const char Buzzer::melThree[] PROGMEM =
  "! V10 O5 L8 T125"
  "dad";

void Buzzer::playSong() {
  playFromProgramSpace(Buzzer::song);
}

void Buzzer::stopSong() {
  stopPlaying();
}

void Buzzer::melodyOne() {
  playFromProgramSpace(Buzzer::melOne);
}

void Buzzer::melodyTwo() {
  playFromProgramSpace(Buzzer::melTwo);
}

void Buzzer::melodyThree() {
  playFromProgramSpace(Buzzer::melThree);
}