int buttonPin = 34;
int buttonStatus = 0;

int analogPin = 4;
int analogValue = 0;

void setup(){
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(analogPin, INPUT);
}

void loop(){
  // Re-Assigment memberi nilai baru pada variabel
  // buttonStatus = digitalRead(buttonPin);
  // Serial.println(buttonStatus);

  analogValue = analogRead(analogPin);
  Serial.print("Nilai Awal: ");
  Serial.println(analogValue);

  // map melakukan perubahan nilai
  Serial.print("Nilai Map: ");
  int mapValue = map(analogValue, 0, 4905, 0, 100);
  Serial.println(mapValue);

  delay(1000);
}