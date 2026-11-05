#include <CapacitiveSensor.h>


CapacitiveSensor sensor = CapacitiveSensor(4, 2);  // 1MOHM connect between pin 2 and pin 4
const int buzzerPin = 10;      // Pin for the buzzer , negetive connect to ground
const int threshold = 200;  

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);  
}

void playMelody(int speakerPin) {
  //tone(speakerPin, <<frequency>>); delay(<<delay>>);
  noTone(speakerPin);
}

void loop() {
  long measurement = sensor.capacitiveSensor(30);  // Take 30 samples for accuracy
  Serial.print("Measurement: ");
  Serial.println(measurement);

  if (measurement > threshold){
    playMelody(buzzerPin);
    Serial.println("Playing");
  }  

  delay(10); 
}
