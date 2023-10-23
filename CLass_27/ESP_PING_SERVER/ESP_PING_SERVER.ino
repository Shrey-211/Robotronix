#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";
const char* apiUrl = "https://example.com/api/endpoint";  // Replace with your API URL

const int ledPin = 2;  // Change this to the GPIO pin where your LED is connected

void setup() {
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);

  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Send a GET request to the API
    http.begin(apiUrl);

    int httpResponseCode = http.GET();

    if (httpResponseCode == HTTP_CODE_OK) {
      String response = http.getString();
      Serial.println("HTTP Response Code: " + String(httpResponseCode));
      Serial.println("Response: " + response);

      // Parse the JSON response
      int buttonState = parseButtonState(response);

      // Control the LED based on the button state
      digitalWrite(ledPin, buttonState);

    } else {
      Serial.println("Error on HTTP request");
    }

    http.end();

    // Wait for a while before sending another request
    delay(5000);  // You can adjust the delay to control the frequency of requests
  } else {
    Serial.println("WiFi Disconnected. Reconnecting...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
  }
}

int parseButtonState(String response) {
  // Parse the JSON response to extract the button_state
  // Assuming the JSON response format is like: {"button_state": 1}
  int buttonState = 0; // Default to off
  int index = response.indexOf("button_state");
  if (index != -1) {
    buttonState = response.substring(index + 15, index + 16).toInt();
  }
  return buttonState;
}
 

























