//--------------------------------------
// THIS IS THE RECEIVER CODE
//--------------------------------------




#include "Arduino.h"
#include "driver/i2s.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "Audio.h"
# include <ESP32Servo.h>

const char* ssid = "Redmi 10C"; //YOUR WIFI SSID
const char* password = "pavan1029"; //YOUR WIFI PASSWORD
const char* openai_api_key = "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"; // Your OpenAI API Key
const char* openai_endpoint = "https://api.openai.com/v1/chat/completions";
Servo DownServo;
Servo UpServo;



#define I2S_DOUT      25
#define I2S_BCLK      27
#define I2S_LRC       26

Audio audio;

HardwareSerial mySerial(2);

const int RX_PIN = 16;  // RX for this board (should connect to the TX of the transmitter)
const int TX_PIN = 17;  // Not used in receiver for now, but set for initialization
const int upservoPin = 18;  // Define the GPIO pin for the servo
const int downservoPin = 19; 

void setup() {
    Serial.begin(115200);
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");
    UpServo.attach(upservoPin); 
    UpServo.write(64);

    DownServo.attach(downservoPin); 
    DownServo.write(65);

    mySerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
    delay(1000);

    Serial.println("Receiver ready");
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(300);
    audio.connecttospeech("starting", "en");
    //while(true){
      
    
    
    }
   


void loop() {

  // ----------------------
  // Check for UART Messages
  // ----------------------
  if (mySerial.available() > 0) {
        String receivedMessage = mySerial.readStringUntil('\n');
        Serial.print("Received: ");
        UpServo.write(84);
        DownServo.write(45);
        if (receivedMessage.length()>2 or receivedMessage == "hi"){
          Serial.println(receivedMessage);
          String output = sendToChatGPT(receivedMessage);
          Serial.println(output);
        }
  }

    
    
            
            

  audio.loop();

   /* if (Serial.available() > 0) {  // Check if input is available
        String userInput = Serial.readStringUntil('\n'); // Read input until Enter key
        userInput.trim();  // Remove trailing newline/spaces
        
        if (userInput.length() > 0) {
            Serial.println("Sending to ChatGPT: " + userInput);
            sendToChatGPT(userInput);
        }*/
        
    
}

// ======================================================
// FUNCTION: Send text to ChatGPT API
// ======================================================

String sendToChatGPT(String text) {

  if (text=="hi"){
      text = "hello";
    }
    else{
      text += "give short answer with 90 letters without imoji"; // THIS IS BECAUSE ESP32 MEMORY ISSUE 
    }
   HTTPClient http;
    
    http.begin(openai_endpoint);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String("Bearer ") + openai_api_key);

    // Create JSON payload
    StaticJsonDocument<512> jsonDoc;
    jsonDoc["model"] = "chatgpt-4o-latest";
    JsonArray messages = jsonDoc.createNestedArray("messages");

    JsonObject userMessage = messages.createNestedObject();
    userMessage["role"] = "user";
    userMessage["content"] = text;

    String jsonPayload;
    serializeJson(jsonDoc, jsonPayload);

    Serial.println("Sending request to ChatGPT...");
    int httpResponseCode = http.POST(jsonPayload);
    String reply;

    if (httpResponseCode > 0) {
        String response = http.getString();
        
        // Parse JSON response
        StaticJsonDocument<1024> responseJson;
        DeserializationError error = deserializeJson(responseJson, response);

        if (!error) {
            String reply = responseJson["choices"][0]["message"]["content"].as<String>();
            Serial.println("\n💬 ChatGPT Says: " + reply);
            String out = reply.substring(0, 200);
            UpServo.write(64);
            DownServo.write(65);
            audio.connecttospeech(out.c_str(), "en");
            
        } else {
            Serial.println("JSON Parsing Error");
        }
    } else {
        Serial.print("HTTP Request failed. Error code: ");
        Serial.println(httpResponseCode);
    }
    
    http.end();
    return reply;
    
    
}

// ======================================================
// Audio Debug Info
// ======================================================
void audio_info(const char *info) {
  Serial.print("audio_info: "); Serial.println(info);
}
