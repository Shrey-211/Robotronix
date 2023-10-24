#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Motor A
int motor1Pin1 = 27; 
int motor1Pin2 = 26; 
int enable1Pin = 14; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 0;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

bool fan_state = false;

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  int Slider_val = param.asInt(); // assigning incoming value from pin V1 to a variable

  dutyCycle = map(Slider_val, 0, 100, 0, 255);
  ledcWrite(pwmChannel, dutyCycle);   
  Serial.print("Forward with duty cycle: ");
  Serial.println(dutyCycle);

  if(fan_state == true)
  {
    Serial.println("Moving Forward");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH); 
  }else
  {
    Serial.println("Motor Stopped");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW); 
  }
  // process received value
}

BLYNK_WRITE(V1)
{
  int Button_val = param.asInt(); // assigning incoming value from pin V1 to a variable
  fan_state = Button_val;
  // process received value
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);

}

void loop()
{
  Blynk.run();
}
