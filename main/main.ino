#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  // Initiate Microsensor and LED light
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop(){
  // Flash light	
  digitalWrite(13, LOW);   
  delay(2000);
  digitalWrite(13, HIGH);

  // Show temperature after light has flashed
  Serial.print(F("Humidity: "));
  Serial.print(dht.readHumidity());
  Serial.print(F("%  Temperature: "));
  Serial.print(dht.readTemperature());
  Serial.println(F("°C "));
}
