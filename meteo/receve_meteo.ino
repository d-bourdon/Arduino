/* -------------------------------------------- */
/* Script de récéption et affichage des données */
/* -------------------------------------------- */
#include <VirtualWire.h>
float temperature;
float hum;
int tempbrute;
long humbrute;
int detector;

void setup()
{
   Serial.begin(9600);  
    Serial.println("setup");

   vw_setup(2000);  
    vw_rx_start();      
}

void loop()
{
   long buf[4];
   uint8_t buflen = sizeof(buf);

   if (vw_get_message((uint8_t *)buf, &buflen)) 
   {
   //on print juste le résultat du buf, le raspberry le redécoupe quand il l'enregistre
     Serial.print(buf[0]);
     Serial.println(" :");
     tempbrute=((buf[0]) * 0.00001);
     humbrute=((buf[0]) - (tempbrute * 100000));
     temperature=(tempbrute * 0.01);
     hum=(humbrute * 0.001);
     detector = (humbrute - (hum * 100));
     Serial.print(temperature);
     Serial.print(" / ");
     Serial.print(hum);
     Serial.print(" / ");
     Serial.print(detector);
     Serial.println();

   }
}