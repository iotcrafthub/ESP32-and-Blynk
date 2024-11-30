/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

int ledPin = 14; // GPIO 14 for the LED

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run(); // Keep the Blynk connection alive
}

// This function is called whenever the button on V1 is pressed in the Blynk app
BLYNK_WRITE(V1){
  int ledState = param.asInt(); // Get the button state (0 or 1)
  digitalWrite(ledPin, ledState); // Turn the LED on or off
}