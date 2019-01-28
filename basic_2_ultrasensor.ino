// Creating unalterable trigger pin declarations
const int trigP1=2;
const int echoP1=3;
const int trigP2=4;
const int echoP2= 5;
// defining variables for calculating distance in centimeters.
long duration1,duration2;
int distance1,distance2;
// The setup funtion will be implemented at the start of the program.
void setup() {
  // trigger pin as output and echo pin as input
  pinMode(trigP1, OUTPUT); 
  pinMode(echoP1, INPUT);
  pinMode(trigP2, OUTPUT);
  pinMode(echoP2, INPUT);
  Serial.begin(9600); 
}
void loop() {
  // Clears the trigger pins
  digitalWrite(trigP1, LOW);
  digitalWrite(trigP2, LOW);
  delayMicroseconds(2);
  // Sending output for 10 ms from trigger pins
  digitalWrite(trigP1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP1, LOW);
  // Reads input from echo pin
  duration1 = pulseIn(echoP1, HIGH);
  // Calculating the distance
  distance1= duration1*0.034/2;
  digitalWrite(trigP2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP2,LOW);
  duration2=pulseIn(echoP2, HIGH);
  distance2= duration2*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(distance1); 
  Serial.print("\t\tSensor 2:");
  Serial.println(distance2);
}
