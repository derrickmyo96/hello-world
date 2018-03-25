#include <VarSpeedServo.h>
#define echoPin 12 // Echo Pin (OUTPUT pin in RB URF02)
#define trigPin 13 // Trigger Pin (INPUT pin in RB URF02)

VarSpeedServo myservo;
long duration, distance;
int getDist();
int usbRead = 0;

// Setup Code
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
}

// Ultrasensor To Servomotor Code
void servo()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  getDist();
    if(distance <= 10)
    {
      Serial.println("Close");
      myservo.write(179,200,true);
    }

    else
    {
      Serial.println("Far");
      myservo.write(0,200,true);
    }
  delay(500);
}

// Get distance from ultrasensor Code
int getDist()
{
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  return distance;
}



// Main Code
void loop() {
  if (Serial.available()) 
  {
    usbRead = Serial.read() - '0';
    Serial.println(usbRead);
    if(usbRead == 1)
    {
      servo();
      usbRead = 0;
    }
  }
}



