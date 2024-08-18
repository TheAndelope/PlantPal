#include <WiFi.h> // For ESP32
#include <WiFiClient.h>
#include <HTTPClient.h>

const char* ssid = "Your_SSID"; // Your Wi-Fi SSID
const char* password = "Your_PASSWORD"; // Your Wi-Fi Password
bool jokeTold=false;
int recievedValue=0;
void setup() {
  Serial.begin(9600);
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
      receivedValue = Serial.parseInt(); // Read the incoming integer value
      Serial.println(receivedValue); // Print the received value for debugging

      
    }
    if(recievedValue>40&&!jokeTold) {
        if (WiFi.status() == WL_CONNECTED) { // Check if we are connected to the WiFi
      HTTPClient http;
      
      String serverPath = "http://<Your_Computer_IP>:5000/call_function"; // Replace with your computer's IP address
      
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET(); // Send the GET request
      
      if (httpResponseCode > 0) {
        String payload = http.getString(); // Get the response from the server
        Serial.println(payload); // Print the returned string from create_text()
      } else {
        Serial.println("Error on HTTP request");
      }
      
      http.end(); // Free resources
    }
  }
}
