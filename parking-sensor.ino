// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzPin = 3;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(buzzPin, OUTPUT); // Sets the trigPin as an Output

Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);

delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);

delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

  if(distance <= 50)
  {
    if(distance <= 20)
    {
      digitalWrite(buzzPin, HIGH);
    }
    else
    {
      float t = (distance-20.0)/30.0;
  
      digitalWrite(buzzPin, HIGH);
      delay(t*1000);
      digitalWrite(buzzPin, LOW);
      delay(t*1000);
    }
  }
  else digitalWrite(buzzPin, LOW);
}
