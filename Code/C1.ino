const int sensor = 2;
const int led = 13;
int langkah = 0;
bool lastState = LOW;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  Serial.println("Sistem Penghitung Langkah");
}

void loop() {
  bool now = digitalRead(sensor);
  if (now == HIGH && lastState == LOW) {
    delay(20);
  
    if (digitalRead(sensor) == HIGH) {
      langkah++;
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);

      float jarak = langkah * 0.75;
      Serial.print("Langkah: ");
      Serial.print(langkah);
      Serial.print(" | Jarak: ");
      Serial.println(jarak);
    }
  }
  lastState = now;
  delay(40);
}
