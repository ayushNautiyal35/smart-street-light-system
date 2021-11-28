# smart-street-light-system
## Smart street light using adruino uno and using ultrasonic sensors and leds
#define trigpin1 9
#define trigpin2 11
#define trigpin3 13
#define echopin1 10
#define echopin2 7
#define echopin3 8
#define led_white1 12
#define led_white2 6
#define led_white3 5
int light;
#define led_blue1 2
#define led_blue2 3
#define led_blue3 4
void setup() {
Serial.begin(9600);
pinMode(led_blue1,OUTPUT);
pinMode(led_blue2,OUTPUT);
pinMode(led_blue3,OUTPUT);
pinMode(trigpin1,OUTPUT);
pinMode(trigpin2,OUTPUT);
pinMode(trigpin3,OUTPUT);
pinMode(echopin1,INPUT);
pinMode(echopin2,INPUT);
pinMode(echopin3,INPUT);
pinMode(led_white1,OUTPUT);
pinMode(led_white2,OUTPUT);
pinMode(led_white3,OUTPUT);
}

void loop() {
light=analogRead(A0);
Serial.println(light);
//digitalWrite(led_white1,LOW);
//digitalWrite(led_white2,LOW);
//digitalWrite(led_white3,LOW);
if(light<50)
{
digitalWrite(led_blue1,HIGH);
digitalWrite(led_blue2,HIGH);
digitalWrite(led_blue3,HIGH);

long duration,distance,first_sensor,second_sensor,third_sensor;
digitalWrite(trigpin1,LOW);
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1,LOW);
duration=pulseIn(echopin1,HIGH);
distance=(duration/2)/29.1; 
 

first_sensor=distance;

digitalWrite(trigpin2,LOW);
delayMicroseconds(2);
digitalWrite(trigpin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2,LOW);
duration=pulseIn(echopin2,HIGH);
distance=(duration/2)/29.1; 
 

second_sensor=distance;

digitalWrite(trigpin3,LOW);
delayMicroseconds(2);
digitalWrite(trigpin3,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin3,LOW);
duration=pulseIn(echopin3,HIGH);
distance=(duration/2)/29.1; 
 

third_sensor=distance;

if( first_sensor<=20)
digitalWrite(led_white1,HIGH);
else
digitalWrite(led_white1,LOW);

if(second_sensor<=20)
digitalWrite(led_white2,HIGH);
else
digitalWrite(led_white2,LOW);


if(third_sensor<=20)
digitalWrite(led_white3,HIGH);

else
digitalWrite(led_white3,LOW);
delay(100);

}
else
{digitalWrite(led_blue1,LOW);
digitalWrite(led_blue2,LOW);
digitalWrite(led_blue3,LOW);
}}
