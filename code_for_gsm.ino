#include <Thermistor>
#include <NTC_Thermistor.h>
#define LED PC13
#define SW PB4
#define SENSOR1_PIN PA0
#define SENSOR2_PIN PA1
#define REFERENCE_RESISTANCE 100000
#define NOMINAL_RESISTANCE 100000
#define NOMINAL_TEMPERATURE 30
#define B_VALUE 3950
#define STM32_ANALOG_RESOLUTION 4095
Thermistor* thermistor1;
Thermistor* thermistor2;
double celsius1;
double celsius2;
int celsius_1;
int celsius_2;
int flag1=0,flag2=0,flag3=0;
int sample_Array1[20] = {};
int sample_Array2[20] = {};
int sample_Counter = 0;
int count = 0;
int flag=0;
int mode = 0;
int SW_count = 0;
int S1_Temp1,S1_Temp2,S1_Temp3,S1_Temp4,S1_Temp5;
int S2_Temp1,S2_Temp2,S2_Temp3,S2_Temp4,S2_Temp5;
float calibration_value = 7.0;
// the setup function runs once when you press reset or power the board
void setup() 
{
 Serial.begin(9600);
 Serial1.begin(9600);
pinMode(LED,OUTPUT);
 pinMode(SW,INPUT);
 thermistor1 = 
newNTC_Thermistor(SENSOR1_PIN,REFERENCE_RESISTANCE,NOMINAL_RESISTA
NCE,NOMINAL_TEMPERATURE,B_VALUE,STM32_ANALOG_RESOLUTION);
 thermistor2 = 
newNTC_Thermistor(SENSOR2_PIN,REFERENCE_RESISTANCE,NOMINAL_RESISTA
NCE,NOMINAL_TEMPERATURE,B_VALUE,STM32_ANALOG_RESOLUTION);
}
// the loop function runs over and over again forever
void loop()
{
 digitalWrite(LED,HIGH);
 if(digitalRead(SW)==LOW)
 {
 digitalWrite(LED,HIGH);
 Serial.println("Calibrating Sensors..");
 calibrate_sensors();
 Serial.println("Calibration Copmleted !!!");
 digitalWrite(LED,LOW);
 while(digitalRead(SW)==LOW);
 }
 read_temperature();
 sample_Array1[sample_Counter] = celsius_1;
sample_Array2[sample_Counter] = celsius_2;
 sample_Counter++;
 if(sample_Counter == 6)
 {
 for(int i=0; i<5 ; i++)
 {
 if(i==0)
 {
 S1_Temp1 = sample_Array1[i];
 S2_Temp1 = sample_Array2[i]; 
 }
 if(i==1)
 {
 S1_Temp2 = sample_Array1[i];
 S2_Temp2 = sample_Array2[i]; 
 }
 if(i==2)
 {
 S1_Temp3 = sample_Array1[i];
 S2_Temp3 = sample_Array2[i]; 
 }
 if(i==3)
 {
 S1_Temp4 = sample_Array1[i];
S2_Temp4 = sample_Array2[i]; 
 }
 if(i==4)
 {
 S1_Temp5 = sample_Array1[i];
 S2_Temp5 = sample_Array2[i]; 
 }
