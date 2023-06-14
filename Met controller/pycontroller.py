import serial
import keyboard

ser = serial.Serial('COM8', 9600) # serial connection, verander COM8 naar de juiste poort

while True:
    if keyboard.is_pressed('d') and not (keyboard.is_pressed('a')):
        if keyboard.is_pressed('s'):
            ser.write(b'3')
            while keyboard.is_pressed('d') and keyboard.is_pressed('s') and not (keyboard.is_pressed('a')):
                pass
            ser.write(b' ')
        elif keyboard.is_pressed('w'):
            ser.write(b'2')
            while keyboard.is_pressed('d') and keyboard.is_pressed('w') and not (keyboard.is_pressed('a')):
                pass
            ser.write(b' ')
        else:
            ser.write(b'r')
            while keyboard.is_pressed('d') and not (keyboard.is_pressed('a') or keyboard.is_pressed('w') or keyboard.is_pressed('s')):
                pass
            ser.write(b' ')
    elif keyboard.is_pressed('a') and not (keyboard.is_pressed('d')):
        if keyboard.is_pressed('s'):
            ser.write(b'4')
            while keyboard.is_pressed('a') and keyboard.is_pressed('s') and not (keyboard.is_pressed('d')):
                pass
            ser.write(b' ')
        elif keyboard.is_pressed('w'):
            ser.write(b'1')
            while keyboard.is_pressed('a') and keyboard.is_pressed('w') and not (keyboard.is_pressed('d')):
                pass
            ser.write(b' ')
        else:
            ser.write(b'l')
            while keyboard.is_pressed('a') and not (keyboard.is_pressed('d') or keyboard.is_pressed('w') or keyboard.is_pressed('s')):
                pass
            ser.write(b' ')
    elif keyboard.is_pressed('w') and not (keyboard.is_pressed('s')):
        if keyboard.is_pressed('d') and keyboard.is_pressed('a'):
            ser.write(b'w')
            while keyboard.is_pressed('w') and keyboard.is_pressed('d') and keyboard.is_pressed('a'):
                pass
            ser.write(b' ')
        else:
            ser.write(b'w')
            while keyboard.is_pressed('w') and not (keyboard.is_pressed('d') or keyboard.is_pressed('a') or keyboard.is_pressed('s')):
                pass
            ser.write(b' ')
    elif keyboard.is_pressed('s') and not (keyboard.is_pressed('w')):
        if keyboard.is_pressed('d') and keyboard.is_pressed('a'):
            ser.write(b's')
            while keyboard.is_pressed('s') and keyboard.is_pressed('d') and keyboard.is_pressed('a'):
                pass
            ser.write(b' ')
        else:
            ser.write(b's')
            while keyboard.is_pressed('s') and not (keyboard.is_pressed('d') or keyboard.is_pressed('a') or keyboard.is_pressed('w')):
                pass
            ser.write(b' ')    
    elif keyboard.is_pressed('f'):
            ser.write(b'f')
            while keyboard.is_pressed('f'):
                pass
    elif keyboard.is_pressed('e'):
            ser.write(b'e')
            while keyboard.is_pressed('e'):
                pass
    elif keyboard.is_pressed('l'):
            ser.write(b'l')
            while keyboard.is_pressed('l'):
                pass