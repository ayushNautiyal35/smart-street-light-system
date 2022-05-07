#define  trigpin1 9
#define trigpin2 10
#define trigpin3 11
#define echopin1 6
#define echopin2 7
#define echopin3 8
#define led_white1 12
#define led_white2 13
#define led_white3 5
int light;

int buzzer=A5;
#define led_blue1 2
#define led_blue2 3
#define led_blue3 4
void setup() {
Serial.begin(9600);

pinMode(A0, INPUT);
  pinMode(buzzer, OUTPUT);
  
pinMode(led_blue1,OUTPUT);
pinMode(led_blue2,OUTPUT);
pinMode(led_blue3,OUTPUT);
pinMode(trigpin1,OUTPUT);
pinMode(echopin1,INPUT);

pinMode(trigpin2,OUTPUT);
pinMode(echopin2,INPUT);

pinMode(trigpin3,OUTPUT);
pinMode(echopin3,INPUT);


pinMode(led_white1,OUTPUT);
pinMode(led_white2,OUTPUT);
pinMode(led_white3,OUTPUT);
}

void loop() {
light=analogRead(A3);
 
digitalWrite(led_white1,LOW);
digitalWrite(led_white2,LOW);
digitalWrite(led_white3,LOW);
if(light<100)
{
digitalWrite(led_blue1,HIGH);
digitalWrite(led_blue2,HIGH);
digitalWrite(led_blue3,HIGH);

long  duration,distance,first_sensor,second_sensor,third_sensor;


 while(1)
 {
  digitalWrite(trigpin1,LOW);
delayMicroseconds(2);
digitalWrite(trigpin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1,LOW);
duration=pulseIn(echopin1,HIGH);
distance=(duration/2)/29.1; 
 delay(100);

first_sensor=distance;

if( first_sensor<=10)
{digitalWrite(led_white1,HIGH);
digitalWrite(led_white2,HIGH);
delayMicroseconds(100000);
}
else
 break;
}

digitalWrite(led_white1,LOW);
while(1)
{
   
delayMicroseconds(10);
digitalWrite(trigpin2,LOW);
delayMicroseconds(2);
digitalWrite(trigpin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2,LOW);
duration=pulseIn(echopin2,HIGH);
distance=(duration/2)/29.1; 
delay(100);

second_sensor=distance;

if(second_sensor<=10)
{
  digitalWrite(led_white2,HIGH);
digitalWrite(led_white3,HIGH);

}
else
break;
}
digitalWrite(led_white2,LOW);

while(1)
{
  
delayMicroseconds(10);
digitalWrite(trigpin3,LOW);
delayMicroseconds(2);
digitalWrite(trigpin3,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin3,LOW);
duration=pulseIn(echopin3,HIGH);
distance=(duration/2)/29.1; 
delay(100);
 
 third_sensor=distance;

if(third_sensor<=10)
digitalWrite(led_white3,HIGH);
 
else
break;
}
digitalWrite(led_white3,LOW);

digitalWrite(led_white1,LOW);
digitalWrite(led_white2,LOW);

}
else
{digitalWrite(led_blue1,LOW);
digitalWrite(led_blue2,LOW);
digitalWrite(led_blue3,LOW);
}
noTone(buzzer);
int sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>300)
  tone(buzzer,100);
 else
  noTone(buzzer);
 
delay(100);
}
