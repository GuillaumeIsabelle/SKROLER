#include "Keyboard.h"

#include "Mouse.h"



/* SKROLER
  * ------------
  * SKROLER is a small Device that scroll using a Joystick
  * Read more : https://github.com/jgwill/SKROLER/
  * https://github.com/jgwill/SKROLER/blob/master/README.md
  * 
  * THIS FILE: https://github.com/jgwill/SKROLER/blob/master/skroler.ino

  * http://guillaumeisabelle.com 
  * copyleft 2018 Guillaume Descoteaux-Isabelle
  * 
  * http://www.0j0.org | http://arduino.berlios.de
  * copyleft 2005 DojoDave for DojoCorp
  */




int scrollDelayInterval = 190;










 int j__Pin1 = A0;                 // slider variable connecetd to analog pin 0
 int j__Pin2 = A1;                 // slider variable connecetd to analog pin 1
 int j__vX = 0;                  // variable to read the value from the analog pin 0
 int j__vY = 0;                  // variable to read the value from the analog pin 1

int j__mvY = 0;
int j__mvX = 0;
int j__n=52;  //neutral position of both Joystick Potentiometer
int j__maxv = 56;
int j__minv = 48;


int j__x = 0;
int j__y = 0;



int debug=0;
 void setup() { 
 if (debug==1) Serial.begin(9600);
 }

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void loop() {
j__read();

if (debug==1)
{
  

  Serial.print("J X:");
  Serial.print(j__mvX);
  Serial.print("  Analog: ");
  Serial.println(j__vX);


  
  Serial.print("J Y:");
  Serial.print(j__mvY);
  Serial.print("  Analog: ");
  Serial.println(j__vY);
}

 j__MouseScroll();
   

  delay(11);
 }
void  j__MouseScroll()
{
   
  if (j__mvX != 0 || j__mvY != 0) 
   {
    //SCROOL
    Mouse.move( j__mvX, j__mvY *-1 ,j__mvY*-1 );
    delay(scrollDelayInterval);
   }

}

 
 int j__treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 void j__read() {
  j__vX = analogRead(j__Pin1);   
  //delay(1);             
  j__vY = analogRead(j__Pin2);   
  delay(3);       

  j__x = j__treatValue(j__vX);
  j__y = j__treatValue(j__vY);
  j__mvX = j__n-j__x;
  j__mvY = j__n-j__y;
  
 }
 
