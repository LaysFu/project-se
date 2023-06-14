#include "controllerclass.h"

ControllerClass::ControllerClass(Buzzer& B) : player(B){}


bool ControllerClass::Controller() {
        if (Serial1.available() > 0) {
            char input = Serial1.read();
            switch (input) {
                case 'w':
                    motor.forward();
                    break;
                case 's':
                    motor.backward();
                    break;
                case '1':
                    motor.left();
                    break;
                case '2':
                    motor.right();
                    break;
                case '3':
                    motor.bLeft();
                    break;
                case '4':
                    motor.bRight();
                    break;
                case '5':
                motor.leftAxis();
                    break;
                case '6':
                    motor.rightAxis();
                    break;        
                case 'f':
                    player.playSong();
                    break;
                case 'e':
                    player.stopSong();
                    break;
                case 'l':
                    return false;
                    break;
                default:
                    motor.stop();
            }
        }
    return true;
}