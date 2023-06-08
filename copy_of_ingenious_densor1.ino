#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define POT A1
#define POT2 A2
#define POT3 A3
#define pulsador1 7
#define pul2 6
#define pul3 5
#define pul4 4
int potvalue=0;
int potvalue2=0;
int potvalue3=0;
LiquidCrystal_I2C lcd(0x27,16,2);

#define pinbuzzer 12
int lectura;
int angulo=0;
int angulo2=0;
int angulo3=0;
int estado1;
int estado2;
int estado3;
int estado4;
Servo servoMotor;
Servo servoMotor2;
Servo servoMotor3;

#define OutPin(pulsador1) pinMode(pulsador1,INPUT)
#define OutPin(pul2) pinMode(pul2, INPUT)
#define OutPin(pul3) pinMode(pul3, INPUT)
#define OutPin(pul4) pinMode(pul4, INPUT)



void setup()
{
  Serial.begin(9600);
servoMotor.attach(9);
  servoMotor2.attach(10);
  servoMotor3.attach(11);
OutPin(pulsador1);
OutPin(pul2); 
OutPin(pul3);
OutPin(pul4);
  pinMode(POT,INPUT);
  pinMode(POT2,INPUT);
  pinMode(POT3,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Wire.begin(); // Inicia el puerto I2C
//attachInterrupt(digitalPinToInterrupt(2),movimiento,CHANGE);
}


void loop()
{
  potvalue=analogRead(POT);
Serial.print(potvalue);
angulo=map(potvalue,0,1023,0,180);
servoMotor.write(angulo);
delay (15);
  
potvalue2=analogRead(POT2);
Serial.print("potvalue2:");
Serial.print(potvalue2);
angulo2=map(potvalue2,0,1023,0,180);
Serial.println ("angulo2= ");
Serial.println (angulo2);
servoMotor2.write(angulo2);
delay (15);
  
  potvalue3=analogRead(POT3);
Serial.println("potvalue3:");
Serial.print(potvalue3);
angulo3=map(potvalue3,0,1023,0,180);
Serial.print ("angulo3= ");
Serial.println (angulo3);
servoMotor3.write(angulo3);
delay (15);

lcd.setCursor(0, 0);
lcd.print("====Moviendo====");
lcd.setCursor(0, 1);
lcd.print("====servomotor====");//Verifica que la contraseña esta correcta
Serial.println("Moviendo servomotor");
lcd.setCursor(7,1); 
lcd.print("θ:");                   
lcd.setCursor(8,1);                      
lcd.print(angulo); 
 estado1 = digitalRead(pulsador1);
estado2 = digitalRead(pul2);
estado3 = digitalRead(pul3);
estado4 = digitalRead(pul4);
  
  
  if(estado1 == 0){
  servoMotor.write(0);
   servoMotor2.write(0);
    servoMotor3.write(0);
    delay(1000);
  
  }
  
  if(estado2== 0){
  servoMotor.write(90);
    servoMotor2.write(45);
    servoMotor3.write(45);
    delay(1000);}
 
  if(estado3 == 0){
  servoMotor.write(90);
     servoMotor2.write(90);
     servoMotor3.write(90);
    delay(1000);}
  
  if(estado4 == 0){
  servoMotor.write(135);
    servoMotor2.write(135);
    servoMotor3.write(180);
    delay(1000);}
}
void movimiento(){
  servoMotor.write(60);
     servoMotor2.write(60);
     servoMotor3.write(60);
  tone(pinbuzzer, 1200);
       tone(pinbuzzer, 800);
       tone(pinbuzzer, 1200);
       tone(pinbuzzer, 800);
}
 