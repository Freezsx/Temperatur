#define BLYNK_TEMPLATE_ID "TMPL6LvpIq22v"
#define BLYNK_TEMPLATE_NAME "Monitoring Suhu LM35"
#define BLYNK_AUTH_TOKEN "1KefExUtDJ2Nfbg3Yu6Jzktz5eP1hB8h"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(8, 9); // RX, TX
ESP8266 wifi(&EspSerial);
#define ESP8266_BAUD 9600 

#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);


char auth[] = BLYNK_AUTH_TOKEN;
// Sesuaikan dengan ssid dan password hotspot anda
// Sesuaikan dengan ssid dan password hotspot anda
char ssid[] = "vivoY22";
char pass[] = "abid777s";
int adc;                                           
float mv;
int celcius;
//============================
void setup(){
  lcd.begin(16,2);
  lcd.print("Tes Koneksi WiFi");
  lcd.setCursor(0,1);
  lcd.print("Tunggu...");
  lcd.print(ssid);
  Serial.begin(9600);
  EspSerial.begin(9600);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
  lcd.print(" OK!");
  delay(2000);
  lcd.clear();
  lcd.print("Monitoring Suhu");
  lcd.setCursor(0,1);
  lcd.print("Suhu:");
}

void loop(){
  Blynk.run();
  sendData();
  delay(1000);
}

void sendData(){
  adc = analogRead(0);
  mv=(adc*4.88);
  celcius =mv/10;
  lcd.setCursor(5,1);
  lcd.print(celcius);
  lcd.print("C ");
  Serial.print("adc=");
  Serial.println(adc);
  Serial.print("mv=");
  Serial.println(mv);
  Serial.print("temp=");
  Serial.println(celcius);
  Serial.println();
  Blynk.virtualWrite(0, celcius);//virtual input V0 (suhu)
}