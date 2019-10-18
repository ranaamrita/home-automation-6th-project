int led_pin = 13;
int sensor_pin = A0;
int value = 200;
void setup() {
Serial.begin(9600);
pinMode(led_pin, OUTPUT);
pinMode(sensor_pin, INPUT);
}
void loop() {
 int sensor_pin  = analogRead(sensor_pin);
Serial.println(sensor_pin);
if(sensor_pin >=32){
  digitalWrite(led_pin, HIGH);
}
delay(1000);
}
