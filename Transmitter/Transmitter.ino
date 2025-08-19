//--------------------------------------
// THIS IS THE TRANSMITTER CODE
//--------------------------------------



#include "BluetoothSerial.h"

#include <ESP32Servo.h>
#include <Arduino.h>


BluetoothSerial SerialBT;  // Create Bluetooth Serial Object
HardwareSerial mySerial(2);  // '2' selects UART2
Servo jawServo; 

// Define your custom pins for UART2
const int RX_PIN = 16;  // RX for this board (should connect to the TX of the transmitter)
const int TX_PIN = 17;  // Not used in receiver for now, but set for initialization
int jawservoPin = 18;
int soundSensorPin = 34;


void setup() {
  Serial.begin(115200);
  pinMode(soundSensorPin, INPUT);
  
 
  SerialBT.begin("ESP32_BT");  // Bluetooth Name
    //Serial.println("✅ Bluetooth Started! Connect to 'ESP32_BT'");

  mySerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  delay(1000);  // Give some time for the serial ports to initialize
  jawServo.attach(jawservoPin); 
  jawServo.write(120);

  
  neckServo.attach(neckservoPin);
  
    
    }
void loop() {
    String message = "";

  // ----------------------
  // Read Bluetooth Input
  // ----------------------

    while (SerialBT.available()) {
    
      char receivedChar = SerialBT.read();
    
    
      message += receivedChar;  // Concatenate character

    }
  // ----------------------
  // If a message was received, send over UART2
  // ----------------------
  if (message.length()>0){
    
    mySerial.println(message);  // Send the message over UART2
    Serial.print("Sent: ");
    Serial.println(message);
    delay(1000);  // Send a message every second
  } 

  // ----------------------
  // Sound Sensor Reaction
  // ----------------------

  int soundLevel = analogRead(soundSensorPin);
  if (soundLevel > 300) {
    for (int j = 0; j <= 3; j += 1){
    int soundLevel = analogRead(soundSensorPin);
    Serial.println(soundLevel);
    for (int angle = 120; angle <= 150; angle += 1) {  // Sweep from 0° to 180°
        jawServo.write(angle);
        delay(10);
    }
  
    for (int angle = 150; angle >= 120; angle -= 1) {  // Sweep from 180° back to 0°
          jawServo.write(angle);
          delay(10);
        }
          Serial.println("Loud sound detected!");
      }
  }

    
    
  
}

  

