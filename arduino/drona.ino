
#include <Servo.h> 
#include <math.h>

// fata dronei e unde bagi cablul micro usb
Servo MOTOR_1; //spate dreapta 
Servo MOTOR_2; //spate stanga
Servo MOTOR_3; //fata stanga 
Servo MOTOR_4; //fata dreapta 

static uint16_t power=1000, maxim_power=1500, minim_power=1000;
static int16_t direction; 
static double sweep;
static int8_t maxim_direction_power; 
static int8_t maxim_sweep_power;

// sweep se roteste spre stanga pentru valoarea -100 si la drapta pentru 100
// power (min 1000ms, max 2000ms)
// direction (min 0°, max 360°) 


static int  PIN_RX_1 = 0, PIN_RX_2 = 0, PIN_RX_3 = 0, PIN_RX_4 = 0, PIN_RX_5 = 0, PIN_RX_6 = 0, PIN_RX_7 = 0, PIN_RX_8 = 0;

// obs 1
// PIN_RX_1 - STANGA 
// PIN_RX_2 - DREAPTA
// PIN_RX_3 - FATA
// PIN_RX_4 - SPATE

// obs 2
// PIN_RX_5 - Stanga
// PIN_RX_6 - Dreapta 

// obs 3
// PIN_RX_7 DOWN MINECRAFT
// PIN_RX_8 UP MINECRAFT

void setup()
{

Serial.begin(115200);

MOTOR_1.attach(17,1000,2000);
MOTOR_2.attach(20,1000,2000);
MOTOR_3.attach(22,1000,2000);
MOTOR_4.attach(23,1000,2000);

set_up_calibration();

}

void loop() {

  if(Serial.available())
  {
    uint8_t val[9];
    val[1] = 0; val[2] = 0; val[3] = 0; val[4] = 0; val[5] = 0; val[6] = 0; val[7] = 0; val[8] = 0;
    while(Serial.available())
    {
      char recv_msg= Serial.read();
      val[ int(recv_msg -'0')]++;
      Serial.print(recv_msg);
    }
    if(val[1])
      PIN_RX_1=1;
    if(val[2])
      PIN_RX_2=1;
    if(val[3])
      PIN_RX_3=1;
    if(val[4])
      PIN_RX_4=1;
    if(val[5])
      PIN_RX_5=1;
    if(val[6])
      PIN_RX_6=1;
    if(val[7])
      PIN_RX_7=1;
    if(val[8])
      PIN_RX_8=1;
    if(val[7]==val[8]){
      PIN_RX_7=0;
      PIN_RX_8=0;
    }
    RX();
  }
    else{
      motor();
      PIN_RX_1 = 0; PIN_RX_2 = 0; PIN_RX_3 = 0; PIN_RX_4 = 0; PIN_RX_5 = 0; PIN_RX_6 = 0; PIN_RX_7 = 0; PIN_RX_8 = 0;
    }
}

void motor()
{
  static uint16_t power_1, power_2, power_3, power_4;

  power_1 = power + (sweep / 100) * maxim_sweep_power;
  power_3 = power + (sweep / 100) * maxim_sweep_power;
  ////////////////////
  power_2 = power - (sweep / 100) * maxim_sweep_power;
  power_4 = power - (sweep / 100) * maxim_sweep_power;

  if(counter_direction()){
    if(direction>=0 && direction<90)
    {
      double cosine, sine; 
      cosine=cos(direction/180);
      sine=sin(direction/180);
      power_1 = power_1 + maxim_direction_power * (cosine + sine);
      power_2 = power_2 - maxim_direction_power * sine;
      power_3 = power_3 - maxim_direction_power * (cosine + sine);
      power_4 = power_4 - maxim_direction_power * cosine;
    }
    else if(direction>=90 && direction<180)
    {
      double cosine, sine; 
      cosine=cos(direction/180);
      sine=sin(direction/180);
      power_1 = power_1 - maxim_direction_power * cosine;
      power_2 = power_2 - maxim_direction_power * (cosine*(-1) + sine);
      power_3 = power_3 - maxim_direction_power * sine;
      power_4 = power_4 + maxim_direction_power * (cosine*(-1) + sine);
    }
    else if(direction>=180 && direction<270)
    {
      double cosine, sine; 
      cosine=cos(direction/180);
      sine=sin(direction/180);
      power_1 = power_1 + maxim_direction_power * (cosine + sine);
      power_2 = power_2 + maxim_direction_power * cosine;
      power_3 = power_3 - maxim_direction_power * (cosine + sine);
      power_4 = power_4 + maxim_direction_power * sine;
    }
    else
    {
      double cosine, sine; 
      cosine=cos(direction/180);
      sine=sin(direction/180);
      power_1 = power_1 + maxim_direction_power * sine;
      power_2 = power_2 + maxim_direction_power * (cosine + sine*(-1));
      power_3 = power_3 - maxim_direction_power * cosine;
      power_4 = power_4 - maxim_direction_power * (cosine + sine*(-1));
    }
  }
  MOTOR_1.writeMicroseconds(power_1);
  MOTOR_2.writeMicroseconds(power_2);
  MOTOR_3.writeMicroseconds(power_3);
  MOTOR_4.writeMicroseconds(power_4);
}

void set_up_calibration()
{
  for(uint16_t pos = 2000; pos>=1000; pos-=1000){
      MOTOR_1.writeMicroseconds(pos);
      MOTOR_3.writeMicroseconds(pos);  
      MOTOR_2.writeMicroseconds(pos);
      MOTOR_4.writeMicroseconds(pos); 
      delay(2000);
  }
  for(uint16_t pos = 2000; pos>=1000; pos-=1000){
      MOTOR_1.writeMicroseconds(pos);
      MOTOR_3.writeMicroseconds(pos);  
      MOTOR_2.writeMicroseconds(pos);
      MOTOR_4.writeMicroseconds(pos); 
      delay(2000);
   }
  delay(7000);
}
int counter_direction()
{
  uint8_t x=0;
  if(PIN_RX_1) x++;
  if(PIN_RX_2) x++;
  if(PIN_RX_3) x++;
  if(PIN_RX_4) x++;
  return x;
} 
void RX()
{
  if(counter_direction())
      direction=(0 * PIN_RX_2 + 90 * PIN_RX_3 + 180 * PIN_RX_1 + 270 * PIN_RX_4)/counter_direction();

    if(PIN_RX_5==1)
      sweep =- 100;
    else if(PIN_RX_6==1)
      sweep = 100; 
    if(PIN_RX_7==1){
      delay(20);
      if(power<maxim_power)
        power++;
    }
    else if(PIN_RX_8==1){
      delay(20);
      if(power>minim_power)
        power--;
    }
    if(power > 1000 && power <= 1100){
      maxim_direction_power = 2;
      maxim_sweep_power = 2;
    }
    else if(power > 1100 && power <= 1200){ 
      maxim_direction_power = 5;
      maxim_sweep_power = 5;
    }
    else if(power > 1200 && power <= 1300){
      maxim_direction_power = 7;
      maxim_sweep_power = 7;
    }
    else if(power > 1300 && power <= 1400){
      maxim_direction_power = 10;
      maxim_sweep_power = 10;
    }
    else if(power > 1400 && power <= 1500){
      maxim_direction_power = 15; 
      maxim_sweep_power = 15;
    }
    else if(power > 1500){
      maxim_direction_power = 20;
      maxim_sweep_power = 20;   
    }
    motor();
}
