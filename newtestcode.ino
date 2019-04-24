const int trigP1=2;         //UtlraSonic Sensor 1
const int echoP1=3;

const int trigP2=5;         //UtlraSonic Sensor 2
const int echoP2=6;

const int trigP3=8;         //UtlraSonic Sensor 3
const int echoP3=9;

const int trigP4=11;         //UtlraSonic Sensor 4
const int echoP4=12;

// defining variables for calculating distance in centimeters.

long duration1,duration2,duration3,duration4;
long distance1,distance2,distance3,distance4;

// The setup funtion will be implemented at the start of the program.

void setup() {
  // trigger pin as output and echo pin as input
  Serial.flush();
  delay(1000);
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
  
  duration1 = read_Sensor(trigP1,echoP1);
  duration2 = read_Sensor(trigP2,echoP2);
  duration3 = read_Sensor(trigP3,echoP3);
  duration4 = read_Sensor(trigP4,echoP4);

  distance1 = duration1*0.034/2;
  distance2 = duration2*0.034/2;
  distance3 = duration3*0.034/2;
  distance4 = duration4*0.034/2;
  String s = String(distance1)+" "+String(distance2)+" "+String(distance3)+" "+String(distance4);
  Serial.flush();
  delayMicroseconds(50);
  Serial.println(s);
  Serial.flush();
  delay(500);
}

unsigned long read_Sensor(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}
