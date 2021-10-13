
// THESE VALUES' TAKEN FROM Blynk
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""
// THESE VALUES' TAKEN FROM Blynk

#define MY_WIFI_NAME "YourWiFiName"
#define MY_WIFI_PASS "YourWiFiPass"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

const char* auth = BLYNK_AUTH_TOKEN;
const char* ssid = MY_WIFI_NAME;
const char* pass = MY_WIFI_PASS;

int pindht11 = D4;
SimpleDHT11 dht11;

void setup() 
{
  Serial.begin(115200);

  // connect ESP8266 to Blynk with your TOKEN
  Blynk.begin(auth, ssid, pass);

}

void loop() 
{
  Blynk.run();

  byte temperature = 0;
  byte humidty = 0;
  int err = SimpleDHTErrSuccess;
  if(( err = dht11.read(pindht11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print(" Read DHT11 failed, err = ");
    Serial.println(err);
    delay(1000);
    return;
  }

  // Send the temperature and humidity from DHT11 to Blynk template display via virtual pin
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

}
