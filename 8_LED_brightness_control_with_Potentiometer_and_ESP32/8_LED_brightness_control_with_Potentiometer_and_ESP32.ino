#define POTENTIOMETER_PIN  36  // ESP32 pin GPIO36 (ADC0) connected to Potentiometer pin
#define LED_PIN            21  // ESP32 pin GPIO21 connected to LED's pin

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // declare LED pin to be an output:
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // reads the input on analog pin A0 (value between 0 and 4095)
  int analogValue = analogRead(POTENTIOMETER_PIN);

  // scales it to brightness (value between 0 and 255)
  int brightness = map(analogValue, 0, 4095, 0, 255);

  // sets the brightness LED that connects to  pin 3
  analogWrite(LED_PIN, brightness);

  // print out the value
  Serial.print("Analog value = ");
  Serial.print(analogValue);
  Serial.print(" => brightness = ");
  Serial.println(brightness);
  delay(100);
}
