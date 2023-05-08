import serial
import keyboard

ser = serial.Serial('COM8', 9600) # serial connection, verander COM8 naar de juiste poort

# Define the key combinations and the corresponding commands
key_commands = {
    ('d', 's'): b'3',
    ('d', 'w'): b'2',
    ('a', 's'): b'4',
    ('a', 'w'): b'1',
    ('w',): b'w',
    ('s',): b's',
    ('f',): b'f',
    ('e',): b'e'
}

while True:
    # Find the first matching key combination and send the corresponding command
    for keys, command in key_commands.items():
        if all(keyboard.is_pressed(key) for key in keys):
            ser.write(command)
            while all(keyboard.is_pressed(key) for key in keys):
                pass
            ser.write(b' ')
            break
