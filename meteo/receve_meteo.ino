/* -------------------------------------------- */
/* Script de récéption et affichage des données */
/* Par GalixX [-] https://github.com/galixX/    */
/* -------------------------------------------- */
#include <VirtualWire.h>
float temperature; // température : 32,50
float hum; // humidité : 42,00
int tempbrute; // temperature sans virgule : 3250
long humbrute; // hum sans virgule : 4200
int detector; // detecteur de pluie

void setup()
{
   Serial.begin(9600);  
//   Serial.println("Start !"); //debug only -> on retire cette ligne pour éviter qu'il l'enregistre dans nos donnée

   vw_setup(2000);  
    vw_rx_start();      
}

void loop()
{
   long buf[4];
   uint8_t buflen = sizeof(buf);

   if (vw_get_message((uint8_t *)buf, &buflen)) 
   {
//on print juste le résultat du buf, le raspberry le redécoupe quand il l'enregistre. Le résultat est récuperé en écoutant la sortie du port avec le raspberry.
//ex:  3250|4200|1
//     --1-|--2-|3
// 1 = température brute, 2 = humidité brute, 3 = état du détécteur de pluie
     Serial.println(buf[0]);
//     Serial.println(" :"); //debug only
//     tempbrute=((buf[0]) * 0.00001); //debug only
//     humbrute=((buf[0]) - (tempbrute * 100000)); //debug only
//     temperature=(tempbrute * 0.01); //debug only
//     hum=(humbrute * 0.001); //debug only
//     detector = (humbrute - (hum * 100)); //debug only
//     Serial.print(temperature); //debug only
//     Serial.print(" / "); //debug only
//     Serial.print(hum); //debug only
//     Serial.print(" / "); //debug only
//     Serial.print(detector); //debug only : ici on a un problème de calcule surement a cause des longs.
//     Serial.println(); //debug only

   }
}
