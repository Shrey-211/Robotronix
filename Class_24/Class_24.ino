#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
#define BLYNK_TEMPLATE_NAME         "Device"
#define BLYNK_AUTH_TOKEN            "YourAuthToken"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define LED_1 0
#define LED_2 1 
#define LED_3 2
#define LED_4 3
#define LED_5 4

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  int Slider_val = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(Slider_val ==1){pattern_1();}
  else if(Slider_val ==2){pattern_2();}
  else if (Slider_val == 3){pattern_3();}
  else if (Slider_val == 4){pattern_4();}
  else if(Slider_val == 5){pattern_5();}
}

void setup()
{
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  pinMode(LED_5,OUTPUT);

  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}

void pattern_1()
{
  for(int i =0; i<5; i++)
  {
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    delay(500);
  }
}

void pattern_2()
{
  for(int i =4; i >= 0; i--)
  {
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    delay(500);
  }
}

void pattern_3()
{
  for(int i =4; i >= 0; i--)
  {
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    delay(500);
  }
  for(int i =0; i<5; i++)
  {
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
    delay(500);
  }
}

void pattern_4()
{
  digitalWrite(random(0,5), HIGH);
  delay(100);
  digitalWrite(random(0,5), LOW);
  delay(100);
}

void pattern_5()
{
  for(int j =1000;j>10; j=j-100 )
  {
    for(int i =0; i<5; i++)
    {
      digitalWrite(i,HIGH);
      delay(j);
      digitalWrite(i,LOW);
      delay(j);
    }
  }
}





























