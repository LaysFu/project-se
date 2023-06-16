#include "Motors.h"

//Berekenen van de positie op de lijn, het midden is 2000. Zodra de x in 'pos - x' verandert, zal de error kleiner worden waardoor de robot minder nauwkeurig de lijn volgt. 
//Zo kan je wel ervoor zorgen dat de robot niet direct stopt met de lijn volgen als hij hem even kwijt is.
void Motors::motorCalculations(uint16_t pos){
  	error = pos - 1500;
    
    //Hier worden de leftSpeed en rightSpeed berekend op basis van een berekening met de error.
    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;
}

//Hier wordt de functie motorCalculations gebruikt om de leftSpeed en rightSpeed te 'binden' in een threshold van -200 tot de maxSpeed.
// Daarna wordt de setSpeeds gedaan om daadwerkelijk de snelheid aan te passen.
void Motors::setMotorSpeeds(int i, uint16_t pos) {
    motorCalculations(pos);

    leftSpeed = constrain(leftSpeed, -200, maxSpeed);
    rightSpeed = constrain(rightSpeed, -200, maxSpeed);
    setSpeeds((leftSpeed/i), (rightSpeed/i));
}
 
//Het snelheidsverschil wordt berekend door middel van de calculateSpeedDifference met de error.
//Door verandering aan de '2' en '3' kan je de marge van error verfijnen.
int Motors::calculateSpeedDifference(int error) {
    return error / 2 + 3 * (error - lastError);
}

//Deze functie wordt gebruikt als links grijs wordt gelezen. Zo krijg je standaard een consistente 90 graden bocht naar links.
//De setSpeeds en delay zijn via finetuning op deze waarden gekomen.
void Motors::turnLeft() {
    setSpeeds(-100, 300);
    delay(500);
}

//Deze functie wordt gebruikt als rechts grijs wordt gelezen. Zo krijg je standaard een consistente 90 graden bocht naar rechts.
//De setSpeeds en delay zijn via finetuning op deze waarden gekomen.
void Motors::turnRight() {
    setSpeeds(300, -100);
    delay(500);
}


// Start handbediening methodes------------------------------------------------------------------------

//Functie om aan te roepen met de handbediening voor naar voren rijden.
void Motors::forward() {
    setSpeeds(200, 200); 
}

//Functie om aan te roepen met de handbediening voor naar achter rijden.
void Motors::backward() {
    setSpeeds(-200, -200);
}

//Functie om aan te roepen met de handbediening voor naar linksvoor rijden.
void Motors::left() {
    setSpeeds(50, 300);
}

void Motors::right() {
    setSpeeds(300, 50);
}

void Motors::bLeft() {
    setSpeeds(-50, -300);
}

void Motors::bRight() {
    setSpeeds(-300, -50);
}

void Motors::stop() {
    setSpeeds(0, 0);
}

void Motors::playSong() {
    buzzer.playSong();
}

void Motors::stopSong() {
    buzzer.stopPlaying();
}
