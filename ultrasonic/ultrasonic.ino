/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
*/

#define trigPin 7
#define echoPin 8
#define led 13
#define fan 4

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led, OUTPUT);
pinMode(fan, OUTPUT);
}

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);  // Added this line
delayMicroseconds(2); // Added this line
digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
delayMicroseconds(10); // Added this line
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 50) { 
  
 digitalWrite(led,HIGH);
 digitalWrite(4,HIGH); // This is where the LED On/Off happens digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(led2,LOW); } else { digitalWrite(led,LOW); digitalWrite(led2,HIGH); } if (distance >= 200 || distance <= 0){
 Serial.println("Fan is ON");
 Serial.println(distance);
}
else {
  digitalWrite(led,LOW);
  digitalWrite(4,LOW);
Serial.print(distance);
Serial.println(" cm");
Serial.println("Out of Range");
}
delay(500);
}
