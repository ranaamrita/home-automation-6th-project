// pin are defined for mq2

int led_pin = 5;
int sensor_pin = A0;
int siron_mq = 6;


// Pin are defined for ultrasonic

int siron_ult = 7;
#define trigPin 8
#define echoPin 9
#define led 10

// code 

void setup(){
  
  //code for ultrasonic
  
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (led, OUTPUT);
  pinMode(siron_ult, OUTPUT);

 // code for mq2

 Serial.begin(9600);
 pinMode(led_pin, OUTPUT);
 pinMode(siron_mq, OUTPUT);
 pinMode(sensor_pin, INPUT);
}

void loop(){

  // code for ultrasonic
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 50){
      digitalWrite(led,HIGH);
      digitalWrite(siron_ult,HIGH); 
      Serial.print(distance);
      Serial.println("cm");
      Serial.println("Out of Range");
  }
  delay(500);

  //code of ultrasonic finished.

   // code of mq2 starts

  int sensor_pin = analogRead(sensor_pin);
  Serial.println(sensor_pin);
  if(sensor_pin >= 32){
    digitalWrite(led_pin, HIGH);
    digitalWrite(siron_mq, HIGH);
  }
  else{
    digitalWrite(led_pin, LOW);
    digitalWrite(siron_mq, LOW);
  }
  delay(1000);
}
