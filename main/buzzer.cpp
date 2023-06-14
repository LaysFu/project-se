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

const char Buzzer::melFour[] PROGMEM =
  "! V10 O5 L8 T125"
  "da O6 L2 c";

const char Buzzer::toneC[] PROGMEM =
  "! V10 O5 L8 T125"
  "c";

const char Buzzer::toneD[] PROGMEM =
  "! V10 O5 L8 T125"
  "d";

const char Buzzer::toneE[] PROGMEM =
  "! V10 O5 L8 T125"
  "e";

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

void Buzzer::melodyFour() {
  playFromProgramSpace(Buzzer::melFour);
}

void Buzzer::C() {
  playFromProgramSpace(Buzzer::toneC);
}

void Buzzer::D() {
  playFromProgramSpace(Buzzer::toneD);
}

void Buzzer::E() {
  playFromProgramSpace(Buzzer::toneE);
}