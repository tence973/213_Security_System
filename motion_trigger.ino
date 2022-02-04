//#define buzzer 12; // GPIO pin for active buzzer
#define echoPin 12
#define trigPin 13
long duration;
int distance;
void setup()
{
  //pinMode(buzzer,OUTPUT); //initialize the buzzer pin as an output
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(115200); // // Serial Communication
  Serial.println("Ultrasonic Sensor starting"); // print some text in Serial Monitor

}void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.0340 / 2; // Speed of sound wave divided by 2 (go and back)
  //Distance in meters
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Trigger alarm if distance is less than 3 meters
  if(10 < distance < 300){
    Serial.println("Alarm triggered!");
    //Call alarm function here
  }
  }
