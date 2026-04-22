import serial
import keyboard
import time

ARDUINO_PORT = 'COM3' 
BAUD_RATE = 9600

print(f"{ARDUINO_PORT}")

try:
    ser = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout = 1)
    
    print("Connected")
except Exception as e:
    print(f"Error connecting: {e}")
    
    exit()

select_mode_active = False 

while True:
    if ser.in_waiting > 0:
        command = ser.readline().decode('utf-8').strip()
        
        if command == "MOVE_UP":
            keyboard.press_and_release('up')
        elif command == "MOVE_DOWN":
            keyboard.press_and_release('down')
        elif command == "MOVE_LEFT":
            keyboard.press_and_release('left')
        elif command == "MOVE_RIGHT":
            keyboard.press_and_release('right')
            
        elif command == "SELECT_PRESSED":
            select_mode_active = not select_mode_active
            if select_mode_active:
                keyboard.press('shift')
                print("Select Mode: ON")
            else:
                keyboard.release('shift')
                print("Select Mode: OFF")
                
        elif command == "DELETE_PRESSED":
            keyboard.press_and_release('backspace')
            
            print("Delete")
            
            if select_mode_active:
                keyboard.release('shift')
                select_mode_active = False
                
                print("Select Mode: OFF")
            
    time.sleep(0.01)