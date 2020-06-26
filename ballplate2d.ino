
// note: for my beam to be horizontal, Servo Motor angle should be 102 degrees.







#include<Servo.h>
#include<PID_v1.h>
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10, 11);

const int servoPin = 9;                                               //Servo Pin
const int servoPin2 = 8;                                               //Servo Pin
 
float Kpx = 4;                                                    //Initial Proportional Gain
float Kix = 2;                                                      //Initial Integral Gain
float Kdx = 3;//Intitial Derivative Gain

float Kpy = 2.2;                                                    //Initial Proportional Gain
float Kiy = 1;                                                      //Initial Integral Gain
float Kdy = 1.5;//Intitial Derivative Gain
double  Inputx, Outputx, ServoOutputx;                                       
double Inputy, Outputy, ServoOutputy;

double Setpointx ;
double  Setpointy;
int servoxzero=90;
int servoyzero=90;
char buffer[2];
int si;
int si2;
int siold,si2old;
PID myPIDx(&Inputx, &Outputx, &Setpointx, Kpx, Kix, Kdx, DIRECT);           //Initialize PID object, which is in the class PID.
PID myPIDy(&Inputy, &Outputy, &Setpointy, Kpy, Kiy, Kdy, DIRECT);                                                                      
                                                                     
                                                                     
                                                                     
Servo myServox;                                                       //Initialize Servo.
Servo myServoy;

void setup() {
  
  
  Serial.begin(9600);                                                //Begin Serial 
//  mySerial.begin(9600);
  myServox.attach(servoPin);                                          //Attach Servo
myServoy.attach(servoPin2);
  //Inputx = readPosition();                                            //Calls function readPosition() and sets the balls
  //Inputy=readPosition();                                                                   //  position as the input to the PID algorithm
                                                                     
  //myServox.write(90);
  //myServoy.write(90);
  pinMode(13,OUTPUT);
  myPIDx.SetMode(AUTOMATIC);                                          //Set PID object myPID to AUTOMATIC 
  myPIDx.SetOutputLimits(-70,70);  //Set Output limits to -80 and 80 degrees.
 
  myPIDy.SetMode(AUTOMATIC);                                          //Set PID object myPID to AUTOMATIC 
  myPIDy.SetOutputLimits(-70,70); 
siold=20;
si2old=20;

}

void loop()
{
 
Setpointx=20 ;  
Setpointy=20;
  
  //Inputx = readPosition();                                            //Calls function readPosition() and sets the balls
  
   Serial.readBytes(buffer, 2);
 si=(int)buffer[0];
 si2=(int)buffer[1];
  
  //Inputy=readPosition();                                                                   //  position as the input to the PID algorithm
      
      
   if(si<0)
{
si=siold;
}
   if(si2<0)
{
si2=si2old;
}

      if (si>40)
      {
      Inputx=si;
      Inputy=si2;
      }
      else
      {
        Inputx=si2;
      Inputy=si;
        
      }

      
   Inputx=Inputx-40;
  myPIDx.Compute();                                                   //computes Output in range of -80 to 80 degrees
  myPIDy.Compute();
  ServoOutputx=90+Outputx;                                            // 102 degrees is my horizontal 
  ServoOutputy=90-Outputy;
 
  myServox.write(ServoOutputx);                                        //Writes value of Output to servo
  myServoy.write(ServoOutputy);
 /*
  mySerial.print("INX:  ");
  mySerial.print(Inputx);
  mySerial.print(" ,");
 //mySerial.print("OUTX:  ");
  mySerial.print(ServoOutputx);
  mySerial.print(" ,");
  mySerial.print("INY:  ");
  mySerial.print(Inputy);
  mySerial.print(" ,");
  mySerial.print("OUTY:  ");
 mySerial.println(ServoOutputy);  
  */
  siold=si;   
si2old=si2;

}   
      
     

