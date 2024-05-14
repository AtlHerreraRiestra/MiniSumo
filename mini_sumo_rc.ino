#include <SoftwareSerial.h>

SoftwareSerial BT(8,9);

#define pwma 6        // declaramos los pines del puente h y las salidas de arduino 
#define ain2 7
#define ain1 8
#define stby 9
#define bin1 10
#define bin2 11
#define pwmb 12

//variables

int estado= '0';          //variable para almacenar los datos recibidos por el bluetooth

void setup()

{
  Serial.begin(9600);   // configuramos el monitor seria para poder utilizar el bluetooth
  pinMode(pwma,OUTPUT);    // definimnos como salidas todos los pines para utilizar el puente h
  pinMode(ain2,OUTPUT); 
  pinMode(ain1,OUTPUT); 
  pinMode(stby,OUTPUT); 
  pinMode(bin1,OUTPUT); 
  pinMode(bin2,OUTPUT); 
  pinMode(pwmb,OUTPUT); 
    
}


void loop()
{
  
  if(Serial.available()>0)
  {                             // lee los caracteres recibidos por el bluetooth y almacena en la variable estado
    estado = Serial.read();
  }

  
  digitalWrite(stby,1);           //encendemos el standby del puente h tb6612 modo espera
  analogWrite(pwma,255);          // velocidad maxima en motor derecho
  analogWrite(pwmb,255);           // velocidad maxima en motor izquierdo

      if(estado=='1')

      {
        // adelante
        digitalWrite(ain1,1);
        digitalWrite(bin1,1);
        digitalWrite(ain2,0);
        digitalWrite(bin2,0);
      }


      if(estado=='2')

      {
        // atras
        digitalWrite(ain1,0);
        digitalWrite(bin1,0);
        digitalWrite(ain2,1);
        digitalWrite(bin2,1);
      }



      if(estado=='3')

      {
        // derecha
        digitalWrite(ain1,1);
        digitalWrite(bin1,0);
        digitalWrite(ain2,0);
        digitalWrite(bin2,1);
      }
      

      
      if(estado=='4')

      {
        // izquierda
        digitalWrite(ain1,0);
        digitalWrite(bin1,1);
        digitalWrite(ain2,1);
        digitalWrite(bin2,0);
      }


      if(estado=='5')

      {
        // paro
        digitalWrite(ain1,0);
        digitalWrite(bin1,0);
        digitalWrite(ain2,0);
        digitalWrite(bin2,0);
      }
 }
 
