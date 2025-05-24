#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Define the LED pin
#define LED_BUILTIN 2

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// SSID for the Access Point
const char* ssid = "ESP32-Status-AP";

// put function declarations here:
// int myFunction(int, int);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  // Set the LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
  // int result = myFunction(2, 3);

  // Initialize WiFi in AP mode
  Serial.print("Setting up AP: ");
  Serial.println(ssid);
  WiFi.softAP(ssid);

  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Define a handler for the root URL ("/")
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<!DOCTYPE html><html><head><title>ESP32 Status</title></head><body><h1>ESP32 Status: Online and Blinking!</h1><p>Connect to this WiFi AP to see this page.</p></body></html>");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Turn the LED ON
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED ON");
  delay(1000); // Wait for 1 second

  // Turn the LED OFF
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED OFF");
  delay(1000); // Wait for 1 second
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }