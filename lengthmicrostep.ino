const int stepPin = 2; 
const int dirPin = 3; 
int incomingByte = 0;   // for incoming serial data
char lengthmm[10];
int mm=0;
int n =0;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter the length in mm");
}

void loop() {

 if (Serial.available() > 0) {
     incomingByte = Serial.read();
      if (incomingByte == '\n')         //Enter Key
     {
      lengthmm[n]='\0';
      n=0;
      DoTheJob();
      }
     else
     {
      lengthmm[n]=incomingByte;
      n=n+1;
     }
 }
}

 void DoTheJob(){
  mm = atoi(lengthmm);
    Serial.println("\n Length=");
    Serial.println(mm);
    
  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < mm*100; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(200); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(200); 
  }
  delay(1000); // One second delay
 }
