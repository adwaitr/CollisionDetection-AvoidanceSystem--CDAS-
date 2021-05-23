
 int Switch,cm = 0;

 long readUltrasonicDistance(int pin)
 {
  pinMode(pin, OUTPUT);    // Set signal pin as output
  digitalWrite(pin, LOW);  // Send low signal
  delayMicroseconds(2);    // wait for 2 micro second
  
  digitalWrite(pin, HIGH); //Send high signal
  delayMicroseconds(10);   // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);     // set signal pin as input
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}
void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Switch= digitalRead(A0);
  if (Switch== HIGH)
  { 
  cm = 0.01723 * readUltrasonicDistance(7);
  int ftd = cm/30;
  if (ftd> 0 && ftd < 6)
  {
    digitalWrite(13, HIGH); //Warning light should be on
    digitalWrite(12, HIGH); //buzzer and steeringwheel vibrator should alert driver
    digitalWrite(11, HIGH); // automatic brakes shuld be turned on
    digitalWrite(10, LOW);  // Turn off Safe distance indicating Led
  }
     else if(ftd > 6 && ftd < 8)
  {
    digitalWrite(13, HIGH); //Warning light should be on
    digitalWrite(12, HIGH); //buzzer and steeringwheel vibrator should alert driver
    digitalWrite(11, LOW);  // automatic brakes shuld be turned off
    digitalWrite(10, LOW);  // Turn off Safe distance indicating Led
  }
  
  else if(ftd > 8 && ftd < 10)
  {
    digitalWrite(13, HIGH); //Warning light should be on
    digitalWrite(12, LOW);  //Turn off buzzer and steeringwheel vibrator
    digitalWrite(11, LOW);  // dont send automatic brake signal 
    digitalWrite(10, LOW);  // Turn off Safe distance indicating Led 
  }
   else if(ftd > 10)
  {
    digitalWrite(13, LOW);  //Warning light should be off
    digitalWrite(12, LOW);  //Turn off buzzer and steeringwheel vibrator
    digitalWrite(11, LOW);  // dont send automatic brake signal
    digitalWrite(10, HIGH); // Turn on Safe distance indicating Led
   }
  }
}