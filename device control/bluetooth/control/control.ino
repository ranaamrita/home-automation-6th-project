String voice;
int 
led2 = 13, //Connect LED 2 To Pin #12 
led1 = 11; //Connect LED 2 To Pin #11
//--------------------------Call A Function-------------------------------//
void allon(){
     digitalWrite(led1, HIGH); 
     digitalWrite(led2, HIGH); 
     }
     
void alloff(){
     digitalWrite(led1, LOW); 
     digitalWrite(led2, LOW); 
     
}
//-----------------------------------------------------------------------//  
 void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
 
}
//-----------------------------------------------------------------------//  
 void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
  //----------Control Multiple Pins/ LEDs----------//  
    
  if(voice == "*everything on")
  {
    allon();
  }  //Turn Off All Pins (Call Function)
  
  else if(voice == "*everything off")
    {
      alloff();
    } //Turn On  All Pins (Call Function)
  
  //----------Turn On One-By-One----------// 
  
  else if(voice == "* fun on") 
    {
      digitalWrite(led1, HIGH);
    } 
 
  else if(voice == "* light on")
    {
      digitalWrite(led2, HIGH);
    }
  
  else if(voice == "*all on")
    {
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH);}
 
  //----------Turn Off One-By-One----------// 
  else if(voice == "*fan off")
    {
      digitalWrite(led1, LOW);
    } 
  
  else if(voice == "*light off")
    {
      digitalWrite(led2, LOW);
    }
  
  else if(voice == "*all off")
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
 
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
