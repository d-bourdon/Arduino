/* --------------------------- */
/* Script d'envoie des données */
/* --------------------------- */
#include <VirtualWire.h>
#include "DHT.h"
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int ledPin = 13;
 
int report[2];
//float temp=22.35;
int tmp1;
int hum1;
int total_int;
 
 
void setup()
{
   dht.begin();
   Serial.begin(9600);  
   Serial.println("setup");
 
   vw_setup(2000);  
}
 
void loop()
{
  float temp = dht.readTemperature();
   tmp1 = (temp * 100);
   Serial.println(tmp1); //2440-> OK
  float hum = dht.readHumidity();
   hum1 = (hum * 100);   //4100-> OK
   Serial.println(hum1);
   total_int = ((tmp1)*10000);
   Serial.println(total_int);  //20608-> Euh nop :p 24400000
   total_int = (total_int + hum1);
   Serial.println(total_int); //24708-> OK il fait l'adition déjà: 24404100
   report[0] = total_int;
 
   vw_send((uint8_t *)report, sizeof(report));
   vw_wait_tx();
   
   delay(5000);
}