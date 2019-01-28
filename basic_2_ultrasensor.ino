const int trigP1=2;
const int echoP1=3;
const int trigP2=4;
const int echoP2= 5;
// defining variables
long duration1,duration2;
int distance1,distance2;
void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1= duration1*0.034/2;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  duration2=pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(distance1); 
  Serial.print("\t\tSensor 2:");
  Serial.println(distance2);
}
