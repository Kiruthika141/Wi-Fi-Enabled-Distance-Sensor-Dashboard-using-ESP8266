#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char* ssid = "YOUR WIFI NAME";  //EDIT
const char* password = "YOUR WIFI PASSWORD"; //EDIT
WiFiServer server(80);
WiFiClient client;
unsigned long myChannelNumber = 2;//EDIT
const char * myWriteAPIKey = "YOUR WRITE API KEY"; //EDIT
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;
int echo=D6;
int trigger=D5;
void setup() 
{
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  Serial.println();
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  ThingSpeak.begin(client);
}
void loop() 
{
  if ((millis() - lastTime) > timerDelay)
  {
    delay(2500);
    digitalWrite(trigger,LOW);
    delayMicroseconds(2);
    digitalWrite(trigger,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);
    int duration=pulseIn(echo,HIGH);
    int distance=duration*0.017;
    Serial.print("Distance is ");
    Serial.print(distance);
    Serial.println(" cm");
    ThingSpeak.setField(1, distance);
    ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
    lastTime = millis();
  }
}