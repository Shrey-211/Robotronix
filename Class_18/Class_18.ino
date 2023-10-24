#include <WiFi.h>
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "SECRET_SSID";   // your network SSID (name) 
char pass[] = "SECRET_PASS";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = 123456789;
const char * myWriteAPIKey = "SECRET_WRITE_APIKEY";

#define LED 2
#define LDR 36
bool LED_Status = false;

void setup() 
{
  pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);

  Serial.begin(115200);  //Initialize serial
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
  float val = analogRead(LDR);
  int light_intensity = map(val, 0, 1023, 0, 100);

  if(light_intensity>50)
  {
    digitalWrite(LED,HIGH);
    LED_Status =true;
  }else
  {
    digitalWrite(LED,LOW);
    LED_Status=false;
  }

  // set the fields with the values
  ThingSpeak.setField(1, light_intensity);
  ThingSpeak.setField(2, LED_Status);

  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  
  delay(20000); // Wait 20 seconds to update the channel again
}

























