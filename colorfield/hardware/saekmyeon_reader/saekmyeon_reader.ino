// 색면화 좌대 NFC 리더 (Arduino Uno + RC522)
// 상판 아래 RC522가 캔버스 틀 아랫면의 NFC 태그(Ø38, NTAG213 등 ISO14443A)를 읽어 USB 시리얼로 알림.
//
// 시리얼 115200bps, 한 줄에 하나씩:
//   TAG 04A1B2C3D4E5F6   태그가 올라옴 (같은 태그가 계속 있으면 1초마다 다시 보냄)
//   NONE                  태그가 내려감 (연속 4번, 약 0.4초 못 읽으면)
//   READY                 시작 · 리더 초기화 끝
//
// 배선 (RC522 → Uno): SDA(SS)→10, SCK→13, MOSI→11, MISO→12, RST→9, 3.3V→3.3V, GND→GND
// RC522는 3.3V 전용. 5V에 연결하면 고장 날 수 있음.
// 라이브러리: Arduino IDE 라이브러리 관리자에서 "MFRC522" (miguelbalboa) 설치

#include <SPI.h>
#include <MFRC522.h>

const byte PIN_SS = 10, PIN_RST = 9;
const byte MISS_LIMIT = 4;          // 이만큼 연속으로 못 읽으면 내려간 것으로 봄
const unsigned long POLL_MS = 100, REPEAT_MS = 1000;

MFRC522 rfid(PIN_SS, PIN_RST);
String current = "";
byte misses = 0;
unsigned long lastSent = 0;

// 잠든(HALT) 태그까지 깨워서 읽음. 태그가 계속 올려져 있는지 확인하는 데 씀
bool readTag(String &uid) {
  byte atqa[2]; byte size = sizeof(atqa);
  MFRC522::StatusCode st = rfid.PICC_WakeupA(atqa, &size);
  if (st != MFRC522::STATUS_OK && st != MFRC522::STATUS_COLLISION) return false;
  if (!rfid.PICC_ReadCardSerial()) return false;
  uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
  }
  uid.toUpperCase();
  rfid.PICC_HaltA();
  return true;
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  rfid.PCD_SetAntennaGain(rfid.RxGain_max); // 상판(약 15mm)을 사이에 두고 읽으므로 수신 감도 최대
  delay(50);
  Serial.println("READY");
}

void loop() {
  String uid;
  if (readTag(uid)) {
    misses = 0;
    if (uid != current || millis() - lastSent > REPEAT_MS) {
      current = uid; lastSent = millis();
      Serial.print("TAG "); Serial.println(uid);
    }
  } else if (current.length() && ++misses >= MISS_LIMIT) {
    current = ""; misses = 0;
    Serial.println("NONE");
  }
  delay(POLL_MS);
}
