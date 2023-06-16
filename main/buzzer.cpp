#include "buzzer.h"

//Aanmaken van het muziekje dat de Zumo kan afspelen.
const char Buzzer::song[] PROGMEM =
  "! V10 O5 L8 T125" 
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16";

//Aanmaken van de eerste melodie die afspeelt met het handmatig calibreren.
const char Buzzer::melOne[] PROGMEM =
  "! V10 O5 L8 T125"
  "ceg";

//Aanmaken van de tweede melodie die afspeelt met het handmatig calibreren.
const char Buzzer::melTwo[] PROGMEM =
  "! V10 O5 L8 T125"
  "gec";

//Aanmaken van de derde melodie die afspeelt met het handmatig calibreren.
const char Buzzer::melThree[] PROGMEM =
  "! V10 O5 L8 T125"
  "dad";

//Aanmaken van de vierde melodie die afspeelt met het handmatig calibreren.
const char Buzzer::melFour[] PROGMEM =
  "! V10 O5 L8 T125"
  "da O6 L2 c";

//Aanmaken van een statische toon die afspeelt als een bepaalde input binnenkomt.
const char Buzzer::toneC[] PROGMEM =
  "! V10 O5 L8 T125"
  "c";

//Aanmaken van een statische toon die afspeelt als een bepaalde input binnenkomt.
const char Buzzer::toneD[] PROGMEM =
  "! V10 O5 L8 T125"
  "d";

//Aanmaken van een statische toon die afspeelt als een bepaalde input binnenkomt.
const char Buzzer::toneE[] PROGMEM =
  "! V10 O5 L8 T125"
  "e";

//Koppelen van het muziekje aan een functie die aangeroepen kan worden.
void Buzzer::playSong() {
  playFromProgramSpace(Buzzer::song);
}

//Functie aanmaken zodat je het spelen van de muziek kan stoppen.
void Buzzer::stopSong() {
  stopPlaying();
}

//Koppelen van een melodie aan een functie zodat deze aangeroepen kan worden.
void Buzzer::melodyOne() {
  playFromProgramSpace(Buzzer::melOne);
}

//Koppelen van een melodie aan een functie zodat deze aangeroepen kan worden.
void Buzzer::melodyTwo() {
  playFromProgramSpace(Buzzer::melTwo);
}

//Koppelen van een melodie aan een functie zodat deze aangeroepen kan worden.
void Buzzer::melodyThree() {
  playFromProgramSpace(Buzzer::melThree);
}

//Koppelen van een melodie aan een functie zodat deze aangeroepen kan worden.
void Buzzer::melodyFour() {
  playFromProgramSpace(Buzzer::melFour);
}

//Koppelen van een toon aan een functie zodat deze aangeroepen kan worden.
void Buzzer::C() {
  playFromProgramSpace(Buzzer::toneC);
}

//Koppelen van een toon aan een functie zodat deze aangeroepen kan worden.
void Buzzer::D() {
  playFromProgramSpace(Buzzer::toneD);
}

//Koppelen van een toon aan een functie zodat deze aangeroepen kan worden.
void Buzzer::E() {
  playFromProgramSpace(Buzzer::toneE);
}
