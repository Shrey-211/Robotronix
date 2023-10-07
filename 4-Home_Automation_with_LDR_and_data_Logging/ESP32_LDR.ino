#define LIGHT_SENSOR_PIN 36 // ESP32 pin GIOP36 (ADC0)
#define LED 22

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40) {
    Serial.println(" => Dark");
    digitalWrite(LED,HIGH);
  } else if (analogValue < 800) {
    Serial.println(" => Dim");
  } else if (analogValue < 2000) {
    Serial.println(" => Light");
    digitalWrite(LED,LOW);
  } else if (analogValue < 3200) {
    Serial.println(" => Bright");
  } else {
    Serial.println(" => Very bright");
  }

  delay(500);
}
