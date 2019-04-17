   
// Creating unalterable trigger pin declarations
const int trigP1=2;         //UtlraSonic Sensor 1
const int echoP1=3;

const int trigP2=6;         //UtlraSonic Sensor 2
const int echoP2=7;

const int trigP3=8;         //UtlraSonic Sensor 3
const int echoP3=9;

const int trigP4=11;         //UtlraSonic Sensor 4
const int echoP4=12;

// defining variables for calculating distance in centimeters.

long duration1,duration2,duration3,duration4;
int distance1,distance2,distance3,distance4;

// The setup funtion will be implemented at the start of the program.

void setup() {
  // trigger pin as output and echo pin as input
  pinMode(trigP1, OUTPUT); 
  pinMode(echoP1, INPUT);

  pinMode(trigP2, OUTPUT);
  pinMode(echoP2, INPUT);
  
  pinMode(trigP3, OUTPUT); 
  pinMode(echoP3, INPUT);
  
  pinMode(trigP4, OUTPUT);
  pinMode(echoP4, INPUT);
  
  Serial.begin(9600); 
}
void loop() {
  
  // Clears the trigger pins
  
  digitalWrite(trigP1, LOW);
  
  digitalWrite(trigP2, LOW);
  
  digitalWrite(trigP3, LOW);
  
  digitalWrite(trigP4, LOW);
  
  delayMicroseconds(1000);
  
  // Sending output for 10 ms from trigger pins
  
  digitalWrite(trigP1, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigP1, LOW);
  duration1 = pulseIn(echoP1, HIGH);
  distance1= duration1*0.034/2;
  delayMicroseconds(1000);
  digitalWrite(trigP2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigP2,LOW);
  duration2=pulseIn(echoP2, HIGH);
  distance2= duration2*0.034/2;
  
  digitalWrite(trigP3, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigP3, LOW);
  duration3 = pulseIn(echoP3, HIGH);
  distance3= duration3*0.034/2;
  
  digitalWrite(trigP4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigP4,LOW);
  duration4=pulseIn(echoP4, HIGH);
  distance4= duration4*0.034/2;

  Serial.print("Sensor 1: ");
  Serial.print(distance1);

  Serial.print("\tSensor 2:");
  Serial.print(distance2);

  Serial.print("\tSensor 3: ");
  Serial.print(distance3); 
  
  Serial.print("\tSensor 4:");
  Serial.println(distance4);

  delay(1000);
}
