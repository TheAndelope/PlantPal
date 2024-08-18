#include <WiFi.h>  // For ESP32
#include <WiFiClient.h>
#include <HTTPClient.h>
#include "config.h"
#include <LiquidCrystal.h>

bool jokeTold = false;
int receivedValue = 0;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (Serial.available() > 0) {
    receivedValue = Serial.parseInt();  // Read the incoming integer value
    Serial.println(receivedValue);      // Print the received value for debugging
  }

  if (receivedValue < 30) {
    jokeTold = false;
  }

  if (receivedValue < 20) {
        if (WiFi.status() == WL_CONNECTED) {  // Check if we are connected to the WiFi
      HTTPClient http;

      String serverPath = "http://10.0.0.125:5000/say_insult";  // Replace with your computer's IP address

      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();  // Send the GET request

      if (httpResponseCode > 0) {
        String payload = http.getString();  // Get the response from the server
        Serial.println("Joke: " + payload);  // Print the returned string from create_text()
      } else {
        Serial.println("Error on HTTP request");
      }

      http.end();  // Free resources
    }
  }

  if (receivedValue > 40 && !jokeTold) {
    jokeTold = true;
    if (WiFi.status() == WL_CONNECTED) {  // Check if we are connected to the WiFi
      HTTPClient http;

      String serverPath = "http://10.0.0.125:5000/call_function";  // Replace with your computer's IP address

      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();  // Send the GET request

      if (httpResponseCode > 0) {
        String payload = http.getString();  // Get the response from the server
        Serial.println("Joke: " + payload);  // Print the returned string from create_text()
      } else {
        Serial.println("Error on HTTP request");
      }

      http.end();  // Free resources
    }
  }
  delay(10000);
}
