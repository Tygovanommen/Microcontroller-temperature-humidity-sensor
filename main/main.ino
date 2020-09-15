#include "DHT.h"

DHT dht(2, DHT11);

void setup(){
  // Initiate hardware
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop(){ 
  lightOFF();
  delay(1000);
  lightON();
  delay(1000);

  //showDhtValues(); // If you want to see DHT values
  showLmValues(); // If you want to see LM values
}

// Get air humisty and temprature values
void showDhtValues() {
  Serial.print(F("Humidity: "));
  Serial.print(dht.readHumidity());
  Serial.print(F("%  Temperature: "));
  Serial.print(dht.readTemperature());
  Serial.println(F("°C "));
}

// Get soil moisture values
void showLmValues() {
   float sensor0 = analogRead(0);
   Serial.print("Humidity: ");   
   Serial.print(sensor0);
     
   float sensor0P = 100.00 - ( ( 100.00 * sensor0 ) / 1023.00 );
   int sensorInt = (int) sensor0P;
   Serial.print(" Humidity percent: ");   
   Serial.println(sensorInt); 
}

// Turn LED light on
void lightON() {
    digitalWrite(13, HIGH);  
}

// Turn LED light off
void lightOFF() {
   digitalWrite(13, LOW);
}
