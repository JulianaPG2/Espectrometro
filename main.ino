#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPI.h>
#include <SD.h>
#include "SparkFun_AS7265X.h"

#include "webserver.h"
#include "measurements.h"
#include "webpage.h"

AS7265X sensor;
AsyncWebServer server(80);

// CONFIGURACION
struct SensorConfig {
  int samples = 10;
  int integration = 50;
  int gain = 1;
};

SensorConfig config;

String ssid="";
String password="";

const char* APssid = "Spectrometer-ESP32";
const char* APpass = "12345678";

File dataFile;

void setup(){

Serial.begin(115200);

WiFi.softAP(APssid, APpass);

Serial.println("Access Point iniciado");
Serial.println(WiFi.softAPIP());

if(!SD.begin()){
Serial.println("Error SD");
}

initWebServer();

while(!sensor.begin()){
Serial.println("Sensor no detectado");
delay(1000);
}

Serial.println("Sensor listo");

}

void loop(){}
