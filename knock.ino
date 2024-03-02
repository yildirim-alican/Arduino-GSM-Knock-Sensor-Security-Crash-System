#include <RobonioGSM.h>

RobonioGSM Robonio;
String smsText, smsNumber;
#define PhoneNumber  "+90xxxxxxxxxx"

const int knockSensorPin = A1;   
const int threshold = 300;       
bool knockDetected = false;       
const int ledPin = 13;           

void setup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(7, LOW);
  
  Robonio.start();
  delay(2000);
  Serial.begin(9600);
  delay(2000);
  Robonio.allSmsDelete();
  delay(2000);
  Serial.println("Sistem çalisiyor.");
  Robonio.smsSend(PhoneNumber, "Sistem acildi.");
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  int sensorValue = analogRead(knockSensorPin);

  if (sensorValue > threshold && !knockDetected) {
    Serial.println("Darbe Algilandi!");

    if (checkConsecutiveReadings(3)) {
      Robonio.smsSend(PhoneNumber, "Darbe Algilandi!");
      Robonio.numberCall(PhoneNumber);
      
      digitalWrite(ledPin, HIGH);
      
      knockDetected = true;
      delay(5000);
    }
  }

  delay(100);

  if (knockDetected && millis() > 10000) { 
    // LED'i söndür
    digitalWrite(ledPin, LOW);
    knockDetected = false;
  }
}

bool checkConsecutiveReadings(int consecutiveCount) {
  int validKnockCount = 0;

  for (int i = 0; i < consecutiveCount; ++i) {
    int currentReading = analogRead(knockSensorPin);
    if (currentReading > threshold) {
      validKnockCount++;
    }
    delay(50);
  }

  return validKnockCount == consecutiveCount;
}
