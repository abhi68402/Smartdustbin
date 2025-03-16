#define BLYNK_TEMPLATE_ID "TMPL3XGYqRMBy"
#define BLYNK_TEMPLATE_NAME "Distance Measure"
#define BLYNK_AUTH_TOKEN "HGwAXJ8VGOw15Tt8ge2vTjncMwYFt2lj"    // Your Blynk Auth Token

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <NewPing.h>

// WiFi credentials
char ssid[] = "Abhinav";  // Your WiFi SSID
char pass[] = "12345678";  // Your WiFi Password

// Blynk Auth Token from the app
char auth[] = BLYNK_AUTH_TOKEN;

// HC-SR04 sensor configuration
#define TRIG_PIN        5    // Trig pin for HC-SR04
#define ECHO_PIN        18   // Echo pin for HC-SR04
#define MAX_DISTANCE    40   // Maximum distance 40 cm
#define ALERT_DISTANCE  8    // Distance threshold for event trigger

// Create NewPing object
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Start serial monitor for debugging
  Serial.begin(115200);

  // Initialize WiFi and Blynk connection
  Serial.println("Connecting to WiFi...");
  Blynk.begin(auth, ssid, pass);

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

  // Check Blynk connection status
  if (Blynk.connected()) {
    Serial.println("Blynk connected!");
  } else {
    Serial.println("Blynk connection failed.");
  }
}

void loop() {
  Blynk.run();  // Run Blynk connection

  // Measure the distance with HC-SR04
  unsigned int distance = sonar.ping_cm();

  // Check if the measured distance is valid
  if (distance > 0 && distance <= MAX_DISTANCE) {
    // Send the distance to the Blynk app (virtual pin V0)
    Blynk.virtualWrite(V0, distance);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if distance is below the alert threshold
    if (distance < ALERT_DISTANCE) {
      // Trigger an event through Blynk
      Blynk.logEvent("low_distance_alert", "Distance is less than 8 cm!");
    }
  } else {
    Serial.println("No valid distance measured or out of range");
  }

  // Delay for 10 seconds between measurements
  delay(10000);
}
