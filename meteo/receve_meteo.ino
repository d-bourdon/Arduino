/* -------------------------------------------- */
/* Script de récéption et affichage des données */
/* -------------------------------------------- */
#include <VirtualWire.h>
float temperature;
float hum;
int tempbrute;
int humbrute;

void setup()
{
   Serial.begin(9600);  
    Serial.println("setup");

   vw_setup(2000);  
    vw_rx_start();      
}

void loop()
{
   int buf[2];
   uint8_t buflen = sizeof(buf);

   if (vw_get_message((uint8_t *)buf, &buflen)) 
   {
     Serial.print(buf[0]);
     Serial.println(" :");
     tempbrute=((buf[0]) * 0.0001);
     humbrute=((buf[0]) - (tempbrute * 10000));
     temperature=(tempbrute * 0.01);
     hum=(humbrute * 0.01);
     Serial.print(temperature);
     Serial.print(" / ");
     Serial.print(hum);
     Serial.println();

   }
}