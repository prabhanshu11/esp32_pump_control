#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

// Define the LED pin (replace with your actual LED pin)
const int ledPin = 2; // Commonly the built-in LED on ESP32 boards

// Replace with your network credentials
const char* ssid = "prab_jiofiber"; // Your local Wi-Fi SSID
const char* password = "cherryrocks"; // Your local Wi-Fi password

AsyncWebServer server(80);

// Variable to keep track of the LED state
bool ledState = false; // Start with LED off

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, !ledState); // Set initial LED state

  // Initialize LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
  Serial.println("LittleFS initialized.");

  // Connect to Wi-Fi network
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("
Connected to WiFi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Serve index.html from LittleFS (optional, could be served from laptop too)
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });

  // API endpoint to toggle LED state
  server.on("/led/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    ledState = !ledState; // Toggle the state
    digitalWrite(ledPin, !ledState); // Update the LED
    request->send(200, "text/plain", ledState ? "LED is now ON" : "LED is now OFF");
  });

  // API endpoint to get LED state (optional)
  server.on("/led/state", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", ledState ? "ON" : "OFF");
  });


  // Handle not found
  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Not found");
  });

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Keep the LED blinking logic for now, but it will be overridden by API calls
  // You might remove this blinking logic if you only want API control.
  digitalWrite(ledPin, HIGH); // Turn the LED on (HIGH is usually off for built-in LED)
  delay(500);
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(500);
}
