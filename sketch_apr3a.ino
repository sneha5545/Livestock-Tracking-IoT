//Prateek
//www.justdoelectronics.com

#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial Gsm(7, 8);
char phone_no[] = "+917975071403";  //For SMS
TinyGPS gps;
int state;
String textMessage;

void setup() {
  Serial.begin(9600);
  Gsm.begin(9600);
  delay(2000);

  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop() {

  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (Serial.available()) {
      char c = Serial.read();
      Serial.print(c);
      if (gps.encode(c))
        newData = true;
    }
  }
  if (Gsm.available() > 0) {
    textMessage = Gsm.readString();
    textMessage.toUpperCase();
    delay(10);
  }

  state = digitalRead(4);
  if (state == 1)  //When Button is Press
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    Gsm.print("AT+CMGF=1\r");
    delay(400);
    Gsm.print("AT+CMGS=\"");
    Gsm.print(phone_no);
    Gsm.println("\"");
    Gsm.println("Alert I need help.............");
    Gsm.print("http://maps.google.com/maps?q=loc:");
    Gsm.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Gsm.print(",");
    Gsm.print(flon == TinyGPS ::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    delay(200);
    Gsm.println((char)26);
    delay(200);
    Gsm.println();
    delay(10000);
  } else {
    delay(10);
  }

  state = digitalRead(5);
  if (state == 1)  //When Button is Press
  {

    Serial.println("OK");
    delay(20000);
    Gsm.println("ATD+917975071403;");  //For Call
    delay(150000);
    Gsm.println("ATH");
    delay(1000);

  } else {
    delay(10);
  }
  Serial.println(failed);
}
