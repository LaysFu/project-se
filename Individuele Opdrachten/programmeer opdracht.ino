#include <Wire.h>     //importeren van de wire libary
#include <Zumo32U4.h> //importeren van de zumo32u4 library

Zumo32U4Motors motors;


void setup()
{
  Serial1.begin(9600); //initialiseren van de seriële verbinding via de xbee
}

void loop()
{ 
  if (Serial1.available() > 0) { //checkt of de seriële connectie beschikbaar is.
    char input = Serial1.read();  //karakter inlezen vanaf de seriële verbinding
    switch (input) {
      case 'w': //checkt of het karakter een w is
        motors.setLeftSpeed(200); //zetten van de motor aan de linker kant op een snelheid van 200
        motors.setRightSpeed(200); //zetten van de motor aan de rechterkant kant op een snelheid van 200
        delay(1000); //een seconde wachten
        break;
      case 's': //checkt of het karakter een s is
        motors.setLeftSpeed(-200); //zetten van de motor aan de linker kant op een snelheid van -200
        motors.setRightSpeed(-200); //zetten van de motor aan de rechter kant op een snelheid van -200
        delay(1000); //een seconde wachten
        break;
      case 'a': // checkt of het karakter een a is
        motors.setLeftSpeed(-100); //zetten van de motor aan de linker kant op een snelheid van -100
        motors.setRightSpeed(100); //zetten van de motor aan de rechter kant op een snelheid van 100
        delay(1000);
        break;
      case 'd': // checkt of het karakter een d is
        motors.setLeftSpeed(100); //zetten van de motor aan de linker kant op een snelheid van 100
        motors.setRightSpeed(-100); //zetten van de motor aan de rechterkant kant op een snelheid van 200
        delay(1000); // een seconde wachten
        break;
      case 'f': // checkt of het karakter een f is
        motors.setLeftSpeed(200); //zetten van de motor aan de linker kant op een snelheid van 200
        motors.setRightSpeed(200); //zetten van de motor aan de rechet kant op een snelheid van 200
        delay(1000);  //een seconde wachten
        motors.setLeftSpeed(-200);//zetten van de motor aan de linker kant op een snelheid van -200
        motors.setRightSpeed(-200); //zetten van de motor aan de rechter kant op een snelheid van -200
        delay(1000);  //een seconde wachten
        motors.setLeftSpeed(200); //zetten van de motor aan de linker kant op een snelheid van 200
        motors.setRightSpeed(-200); //zetten van de motor aan de rechter kant op een snelheid van -200
        delay(1000);  //een seconde wachten
        motors.setLeftSpeed(-200); //zetten van de motor aan de linker kant op een snelheid van -200
        motors.setRightSpeed(200); //zetten van de motor aan de rechter kant op een snelheid van 200
        delay(1000);  //een seconde wachten
        break;
      default: // wanneer er geen karakter wordt ingevoerd of het ingevoerde karakter niet aan de bovenstaande kriteria voeldoet
        motors.setLeftSpeed(0); //uitzetten van de motor aan de linker kant
        motors.setRightSpeed(0); //uitzetten van de motor aan de rechter kant
        break;
    }
  }
}