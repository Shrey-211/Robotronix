
#define LED_1 0
#define LED_2 1
#define LED_3 2
#define LED_4 3
#define LED_5 4

void setup() 
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);

}

void loop() 
{
  for(int i=0; i<5; i++)
  {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
  }
  for(int i=5; i>5; i--)
  {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
  }
}
