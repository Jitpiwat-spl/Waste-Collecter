#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL65suP-UJ-"
#define BLYNK_TEMPLATE_NAME "Protject4"
#define BLYNK_AUTH_TOKEN "lv4hd8Hz5O34MpWaYm6FM9_QYtWdo0jk"

#include <SPI.h>
#include <WiFiS3.h>
#include <BlynkSimpleWifi.h>



// กำหนดพินสำหรับ L298N ตัวแรก
const int motorLeft1 = 0;  // IN1
const int motorLeft2 = 1;  // IN2
const int motorRight1 = 2; // IN3
const int motorRight2 = 3; // IN4
const int enableA = 9;     // ENA (PWM)
const int enableB = 10;    // ENB (PWM)

// กำหนดพินสำหรับ L298N ตัวสอง
const int motor2Left1 = 4;  // IN1
const int motor2Left2 = 5;  // IN2
const int motor2Right1 = 8; // IN3
const int motor2Right2 = 7; // IN4
const int enable2A = 12;     // ENA (PWM)
const int enable2B = 13;    // ENB (PWM)

Servo servo1;  // สร้างวัตถุ Servo สำหรับ Servo ตัวที่ 1
Servo servo2;  // สร้างวัตถุ Servo สำหรับ Servo ตัวที่ 2

// WiFi credentials
char ssid[] = "Nathan_Ip";
char pass[] = "aabbccdd12";



// ฟังก์ชันควบคุมมอเตอร์จาก Blynk
BLYNK_WRITE(V0) {
  int val = param.asInt();
  if (val == 1) {
    // เดินหน้ามอเตอร์ทั้งสอง
    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, HIGH);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, HIGH);
    digitalWrite(motor2Right2, LOW);
  } else {
    // หยุดมอเตอร์ทั้งสอง
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorRight1, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Right1, LOW);
  }
}

BLYNK_WRITE(V1) {
  int val = param.asInt();
  if (val == 1) {
    // หมุนซ้าย
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorLeft2, HIGH);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Left2, HIGH);
    digitalWrite(motor2Right1, HIGH);
    digitalWrite(motor2Right2, LOW);
  } else {
    // หยุดมอเตอร์
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, LOW);
  }
}

BLYNK_WRITE(V2) {
  int val = param.asInt();
  if (val == 1) {
    // หมุนขวา
    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motorRight2, HIGH);

    digitalWrite(motor2Left1, HIGH);
    digitalWrite(motor2Left2, LOW);
    digitalWrite(motor2Right1, LOW);
    digitalWrite(motor2Right2, HIGH);
  } else {
    // หยุดมอเตอร์
    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorRight2, LOW);

    digitalWrite(motor2Left1, LOW);
    digitalWrite(motor2Right2, LOW);
  }
}

void setup() {
  // ตั้งค่าพินของมอเตอร์เป็น OUTPUT
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);

  pinMode(motor2Left1, OUTPUT);
  pinMode(motor2Left2, OUTPUT);
  pinMode(motor2Right1, OUTPUT);
  pinMode(motor2Right2, OUTPUT);
  pinMode(enable2A, OUTPUT);
  pinMode(enable2B, OUTPUT);
  // ตั้งค่าความเร็วให้มอเตอร์ (ค่าระหว่าง 0-255)
  analogWrite(enableA, 200);  // ความเร็วสำหรับมอเตอร์ซ้าย
  analogWrite(enableB, 200);  // ความเร็วสำหรับมอเตอร์ขวา

  analogWrite(enable2A, 200);  // ความเร็วสำหรับมอเตอร์ซ้าย
  analogWrite(enable2B, 200);  // ความเร็วสำหรับมอเตอร์ขวา
  

  // Debug console
  Serial.begin(9600);

  // เชื่อมต่อกับ Blynk ผ่าน WiFi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();  // รันการทำงานของ Blynk
}
