# Humanized Robot Voice Assistant

This repository contains the Arduino programs for a **robotic voice assistant with expressive, human-like features**, created by the **DreamSpace Academy team in Batticaloa, Sri Lanka**.  
The project was showcased on **February 23, 2025** and integrates **ChatGPT conversational AI**, **facial animations** via servo motors, and **voice interaction** powered by ESP32 microcontrollers.  
Applications include **education, healthcare, customer engagement, and entertainment**.  

## Team Members

- Harishpavan  
- Sanojan  
- Kishopan  
- Krishanth  
- Sajiv  
- Subeetshan  

---

## Project Summary

The system uses **two ESP32 boards**:  

- **Transmitter**: Captures audio with a sound sensor, animates the jaw servo, and sends data over **UART** or **Bluetooth**.  
- **Receiver**: Communicates with the **ChatGPT API**, generates speech using **Text-to-Speech (TTS)**, and animates facial features with servos.  

### Key Features

- **Conversational AI**: Real-time voice interaction using ChatGPT API + TTS.  
- **Expressive Animations**: Mouth and eye movements with servo motors.  
- **Connectivity**: Wi-Fi for API calls, Bluetooth/UART for ESP32 communication.  
- **Hardware Setup**: ESP32 boards, sensors, speakers, microphones, and servo motors.  

---

## Hardware Requirements

- 2 × ESP32 Development Boards  
- 2 × Servo Motors (jaw/eye movement)  
- Sound Sensor (GPIO 34 on transmitter)  
- I2S Audio Module (MAX98357A recommended)  
- Microphones & Speakers  
- Breadboard, jumper wires, and 5V power supply  

### Pin Configuration

#### Transmitter
- Sound Sensor → GPIO 34  
- Jaw Servo → GPIO 18  
- UART2 → RX (GPIO 16), TX (GPIO 17)  

#### Receiver
- Upper Servo → GPIO 18  
- Lower Servo → GPIO 19  
- I2S Audio → DOUT (GPIO 25), BCLK (GPIO 27), LRC (GPIO 26)  
- UART2 → RX (GPIO 16), TX (GPIO 17)  

---

## Software Requirements

- Arduino IDE (v2.x recommended)  
- ESP32 Board Support Package  
- Libraries:  
  - `ESP32Servo`  
  - `BluetoothSerial`  
  - `ArduinoJson`  
  - `HTTPClient`  
  - `Audio`  

> ⚠️ Don’t forget to add your **WiFi credentials** and **OpenAI API key** in `Receiver.ino`.  

---

## Setup Instructions

1. **Hardware Setup**  
   - Assemble ESP32 boards with sensors, servos, and audio module.  
   - Connect UART2 pins between transmitter and receiver.  
   - Power both boards with 5V.  

2. **Software Setup**  
   - Install libraries in Arduino IDE.  
   - Upload `Transmitter.ino` to the transmitter board.  
   - Upload `Receiver.ino` to the receiver board.  

3. **Running the Project**  
   - Power on both boards.  
   - Connect to transmitter’s Bluetooth device (`ESP32_BT`).  
   - Send text/voice input → processed by ChatGPT → robot responds with **speech + facial animation**.  

---

## Code Structure

- **Transmitter.ino**  
  - Reads sound sensor input and animates jaw servo.  
  - Sends input via Bluetooth/UART to receiver.  

- **Receiver.ino**  
  - Sends input to ChatGPT API and parses the response.  
  - Generates TTS audio output and animates servos.  

---

## Usage

- Send text messages (e.g., `hi`) via Bluetooth to start conversation.  
- Speak near the sound sensor to trigger jaw movement.  
- Robot responds with **TTS audio + expressive animations**.  

---

## Future Enhancements

- Multilingual support.  
- Touch/gesture-based interactions.  
- Emotion-aware responses.  
- Improved conversational models.  

---

## References

- InMoov Neck & Jaw: YouTube Tutorials  
- Smartphone-Controlled Humanoid Robot: Instructables  
- DreamSpace Academy: [Website](https://dreamspace.academy)  
- ESP32 Audio Library: GitHub  

---

## License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.  

---

## Acknowledgments

Developed as part of **DreamSpace Academy’s mission** to empower grassroots innovation in Sri Lanka.  
Special thanks to the mentors and team members for their contribution and guidance.  
