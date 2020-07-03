#include <Servo.h>
Servo  moto1;
int RDLstate1=0;
int RDLstate2=0;
int RDLstate3=0;
int x=0;

void setup()
{
   moto1.attach(5); //motor1 connected to pin5 arduino
 
  pinMode(2, INPUT);   // connected to LDR1
  pinMode(3, INPUT);   // CONNECTED TO LDR2
  pinMode(4, INPUT);    //CONNECTED TO LDR3
}

void loop()
{
  delay(250);
                             //We have 3 LDR sensors fixed linearly with 10cm distance between each other ,and we have 3 different size of boxesin our production line 
                                //10,20,30cm  we want to separate them form each other
  RDLstate1=digitalRead(2);
  RDLstate2=digitalRead(3);    //now read the situation of each LDR SENSOR
  RDLstate3=digitalRead(4);
     delay(750);

  if( RDLstate1==RDLstate3) // if RDL1=RDL3 thats's mean if they are LOW the box of size 30cm block the light to reach the sensors,so the motor will place it at zero degree
  {
   x=0;                     //or the RDL1=RDL3 ARE HIGH ,so that's mean there is no box ,the place is empty.
     moto1.write(x);
   delay(2000);
  }
  
  if( RDLstate2!=RDLstate3){ //if RDL2 != RDL3  that's mean the box of 20cm size block the light to reach LDR1,LDR2 so the motor will place it at 90 degree
   x=90;
     moto1.write(x);
   delay(2000);
  }
  
   if( RDLstate1!=RDLstate2){ // RDL1 !=RDL2 thats mean the box of 10cm block the light to reach RDL1, SO the motor will place it at 180 degree
   x=180;
     moto1.write(x);
   delay(2000);
  }
  
    


}