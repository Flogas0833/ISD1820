#include <Arduino.h>

const int REC_PIN = 13;   
const int PLAYE_PIN = 12; 
const int PLAYL_PIN = 14; 

void setup() {
  Serial.begin(115200);

  // Chuyển sang OUTPUT để điều khiển module
  pinMode(REC_PIN, OUTPUT);
  pinMode(PLAYE_PIN, OUTPUT);
  pinMode(PLAYL_PIN, OUTPUT);

  digitalWrite(REC_PIN, LOW);
  digitalWrite(PLAYE_PIN, LOW);
  digitalWrite(PLAYL_PIN, LOW);

  Serial.println("Nhap lenh:");
  Serial.println(" 'REC'   - Bat dau ghi am");
  Serial.println(" 'STOP'  - Dung ghi am / Dung phat PLAYL");
  Serial.println(" 'PLAYE' - Phat lai toan bo (Edge)");
  Serial.println(" 'PLAYL' - Phat am thanh (Level)");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim(); 

    if (cmd == "REC") {
      digitalWrite(PLAYE_PIN, LOW);
      digitalWrite(PLAYL_PIN, LOW);
      digitalWrite(REC_PIN, HIGH);
      Serial.println("Dang ghi am");
    } 
    else if (cmd == "STOP") {
      digitalWrite(REC_PIN, LOW);
      digitalWrite(PLAYL_PIN, LOW);
      digitalWrite(PLAYE_PIN, LOW);
      Serial.println("Tam dung");
    } 
    else if (cmd == "PLAYE") {
      digitalWrite(PLAYE_PIN, HIGH);
      delay(200); 
      digitalWrite(PLAYE_PIN, LOW);
      Serial.println("Phat lai toan bo am thanh.");
    } 
    else if (cmd == "PLAYL") {
      digitalWrite(PLAYL_PIN, HIGH);
      Serial.println("Dang phat am thanh (Nhan giu)");
    }
    else {
      Serial.println("(!) Lenh khong hop le.");
    }
  }
}