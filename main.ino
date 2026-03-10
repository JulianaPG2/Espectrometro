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

void setup(){

Serial.begin(115200);

WiFi.softAP("Spectrometer-ESP32","12345678");

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
