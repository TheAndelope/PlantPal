void setup() {
  Serial.begin(9600); // Initialize serial communication at 115200 baud rate
}

void loop() {
  if (Serial.available() > 0) {
    int receivedValue = Serial.parseInt(); // Read the incoming integer value
    Serial.print("Received value: ");
    Serial.println(receivedValue); // Print the received value for debugging
  }
}
