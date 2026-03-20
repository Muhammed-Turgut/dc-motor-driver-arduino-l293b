const int EN1 = 9;   // PWM - hız kontrolü
const int IN1 = 8;   // Yön pini 1
const int IN2 = 7;   // Yön pini 2

void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Motor hazır!");
}

void motorIleri(int hiz) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, hiz);  // 0-255
}

void motorGeri(int hiz) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, hiz);  // 0-255
}

void motorDur() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 0);
}

void loop() {
  Serial.println("İleri - yavaş");
  motorIleri(100);    // %39 hız
  delay(2000);

  Serial.println("İleri - tam hız");
  motorIleri(255);    // %100 hız
  delay(2000);

  Serial.println("Dur");
  motorDur();
  delay(1000);

  Serial.println("Geri - orta hız");
  motorGeri(180);     // %70 hız
  delay(2000);

  Serial.println("Dur");
  motorDur();
  delay(1000);
}
