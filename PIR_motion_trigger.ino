int sensor = 21;              // sensor pin
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status

void setup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200);       
  Serial.println("Reading sensor value...");
  delay(30000); // Let the PIR sensor warm up for 30 seconds
}

void loop(){
  val = digitalRead(sensor);   // read sensor value 
    if (val == HIGH) {
      Serial.println("Motion detected!"); 
      // Call alarm function here
    } 
}
