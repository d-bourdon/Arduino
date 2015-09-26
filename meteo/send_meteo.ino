/* --------------------------- */
/* Script d'envoie des données */
/* --------------------------- */
#include <VirtualWire.h>
#include "DHT.h"
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);
int ledPin = 13;

long report[2];
//float temp=22.35;
int tmp1;
long hum1;
int out_detector;
int detector;
int range;
long total_int;

// ----------------------
//constante du rainsensor

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup()
{
   dht.begin();
   Serial.begin(9600);   
   //Serial.println("setup");
  
   vw_setup(2000);   
}

void loop()
{
  float temp = dht.readTemperature();
   tmp1 = (temp * 1000);
  // Serial.println(tmp1);
  float hum = dht.readHumidity();
   hum1 = (hum * 1000L);
  // Serial.println(hum1);
   total_int = (tmp1*10000L);
  // Serial.println(total_int);
   out_detector = analogRead(A0);
  //  Serial.println(out_detector);
   int range = map(out_detector, sensorMin, sensorMax, 0, 4);
   // Serial.println(range);
  switch (range) {
 case 0:    // pleut beaucoup
    detector = 4;
    break;
 case 1:    // pleut
    detector = 3;
    break;
 case 2:    // un peu de pluie
    detector = 2;
    break;
 case 3:    // pas de pluie
    detector = 1;
    break;
  }
  // Serial.println(detector);
   total_int = (total_int + hum1 + detector);
   report[0] = total_int;
  // Serial.println(report[0]);
   vw_send((uint8_t *)report, sizeof(report));
   vw_wait_tx(); 
   
   delay(5000);
}