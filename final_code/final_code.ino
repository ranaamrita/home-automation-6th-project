// code for ultrasonic

#define trigPin 7
#define echoPin 8
#define led 13
#define fan 4

// Pin are defined for ultrasonic in above

void setup(){
  
  //code for ultrasonic
  
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (led, OUTPUT);
  pinMode (fan, OUTPUT);
}

void loop(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 50){
     digitalWrite(led,HIGH);
      digitalWrite(4,HIGH); 
      Serial.print(distance);
      Serial.println("cm");
      Serial.println("Out of Range");
  }
  delay(500);
}
