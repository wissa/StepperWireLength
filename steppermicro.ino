const int stepPin = 2; 
const int dirPin = 3; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 3200 pulses for making one full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(200); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(200); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,HIGH); //Changes the rotations direction
  // Makes 3200 pulses for making two full cycle rotation
  for(int x = 0; x < 3200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(200);
  }
  delay(1000);
}
