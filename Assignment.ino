//LM35 temperature sensor with an Arduino Uno.
#include <TimerOne.h>

#define LM35_pin A0 //LM35 connected on Analog A0 pin
#define ledPin 13 // Onboard LED pin

float temperature;
int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //set the ledPin as output for onboard led
  Timer1.initialize(1000); // Set the timer period in microseconds (1000 microseconds = 1 millisecond)
  Timer1.attachInterrupt(callback); // Attach the callback function to the timer interrupt
}


void loop() {
  //Read the Value from LM35 Sensor.
  int Readvalue = analogRead(LM35_pin);

  //convert the Read value from sensor to Temp value
  float TempValue = Readvalue * (5.0 / 1024.0);

  temperature = TempValue * 100;

  if (temperature < 30.0) {
    Timer1.setPeriod(250000); // Set Timer1 interval to 250 milliseconds (250,000 microseconds)
  } else {
    Timer1.setPeriod(500000); // Set Timer1 interval to 500 milliseconds (500,000 microseconds)
  }
}

void callback() {
  if (ledState == LOW) {
    ledState = HIGH;  //if previously led is low then make it high.
  } else {
    ledState = LOW;   //eithrt if led previously high make it low.
  }
  digitalWrite(ledPin, ledState);
}

