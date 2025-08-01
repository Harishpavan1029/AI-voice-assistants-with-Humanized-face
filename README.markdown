# Humanized Robot Voice Assistant

This repository contains the Arduino code for a **humanized robot with voice chatting and expressive features**, developed by the DreamSpace Academy team in Batticaloa, Sri Lanka. Exhibited on **February 23, 2025**, this project integrates **conversational AI** powered by **ChatGPT**, expressive facial animations, and audio processing to create natural human-robot interactions. The robot uses **ESP32** microcontrollers, **servo motors** for facial movements, and **Bluetooth** for communication, with applications in education, healthcare, customer service, and entertainment.

## Team

- Harishpavan
- Sanojan
- Kishopan
- Krishanth
- Sajiv
- Subeetshan

## Project Overview

The system consists of two **ESP32** boards:

- **Transmitter**: Captures voice input via a sound sensor and sends it over **UART** or **Bluetooth** to the receiver, controlling a **servo motor** for jaw movement based on sound levels.
- **Receiver**: Processes voice input using the **ChatGPT API**, generates responses with **text-to-speech (TTS)**, and animates facial features (mouth and eyes) using **servo motors**.

### Key Features

- **Voice Interaction**: Real-time conversations via **ChatGPT API** and **TTS** (e.g., **Google Text-to-Speech** or **Whisper**).
- **Expressive Animations**: Synchronized mouth and eye movements using **servo motors**.
- **Connectivity**: **WiFi** for **API** calls and **Bluetooth**/**UART** for inter-board communication.
- **Hardware**: **ESP32**, **microphones**, **speakers**, and **servo motors** for a lifelike robot head.

## Hardware Requirements

- 2x **ESP32** Dev Boards (e.g., ESP32-WROOM-32)
- 2x **Servo Motors** (for jaw, mouth, or eye movements)
- Sound Sensor (connected to GPIO 34 on transmitter)
- **I2S** Audio Module (e.g., MAX98357A) for **TTS** output
- **Microphones** and **Speakers** for voice input/output
- Jumper wires, breadboard, and power supply (5V recommended)

### Pin Configuration

#### Transmitter

- **Sound Sensor**: GPIO 34
- **Jaw Servo**: GPIO 18
- **UART2**: RX (GPIO 16), TX (GPIO 17)

#### Receiver

- **Up Servo**: GPIO 18
- **Down Servo**: GPIO 19
- **I2S Audio**: DOUT (GPIO 25), BCLK (GPIO 27), LRC (GPIO 26)
- **UART2**: RX (GPIO 16), TX (GPIO 17)

## Software Requirements

- Arduino IDE (2.x recommended)
- **ESP32** Board Support Package
- Libraries:
  - `ESP32Servo` (for **servo motor** control)
  - `BluetoothSerial` (for **Bluetooth** communication)
  - `ArduinoJson` (for **API** response parsing)
  - `HTTPClient` (for **ChatGPT API** calls)
  - `Audio` (for **I2S** audio processing)
- **OpenAI API Key** (replace `openai_api_key` in `Receiver.ino`)

## Setup Instructions

1. **Hardware Setup**:

   - Connect **servo motors**, sound sensor, and **I2S** audio module to the respective **ESP32** boards as per the pin configuration.
   - Wire **UART2** pins (RX/TX) between the transmitter and receiver for serial communication.
   - Ensure a stable 5V power supply for both boards.

2. **Software Setup**:

   - Install the Arduino IDE and add **ESP32** board support via Boards Manager.
   - Install required libraries via Library Manager or manually.
   - Update `Receiver.ino` with your **WiFi** credentials (`ssid`, `password`) and **OpenAI API Key** (`openai_api_key`).
   - Upload `Transmitter.ino` to the transmitter **ESP32** and `Receiver.ino` to the receiver **ESP32**.

3. **Running the Project**:

   - Power on both **ESP32** boards.
   - Connect to the transmitter’s **Bluetooth** device (`ESP32_BT`) using a smartphone or PC.
   - Send voice or text input via **Bluetooth** or trigger the sound sensor to start interaction.
   - The receiver processes input via **ChatGPT**, generates **TTS** output, and animates the robot’s face.

## Code Structure

- **Transmitter.ino**:
  - Reads sound levels from a sensor to animate the jaw **servo motor**.
  - Sends text input from **Bluetooth** to the receiver via **UART**.
- **Receiver.ino**:
  - Receives input via **UART**, sends it to **ChatGPT API**, and processes the response.
  - Generates **TTS** audio and controls **servo motors** for facial animations.

## Usage

- Send text messages (e.g., “hi”) via **Bluetooth** to the transmitter to initiate a conversation.
- Speak near the sound sensor to trigger jaw animations and voice processing.
- The robot responds with **TTS** audio and synchronized mouth/eye movements.

## Future Enhancements

- Add **multilingual support** for **ChatGPT** responses.
- Implement **touch sensors** for interactive gestures.
- Enhance **emotional intelligence** with context-aware expressions.
- Upgrade **AI** models for improved conversation quality.

## References

- InMoov Neck and Jaw: YouTube Tutorial
- Smartphone-Controlled 3D-Printed Humanoid Robot: Instructables Guide
- DreamSpace Academy: Website
- ESP32 Audio Library: GitHub

## License

This project is licensed under the MIT License. See LICENSE for details.

## Acknowledgments

Developed as part of DreamSpace Academy’s mission to foster grassroots innovation in Sri Lanka. Special thanks to our team and mentors for their support.