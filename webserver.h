void initWebServer(){

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){

request->send(200,"text/html",index_html);

});

server.on("/setwifi", HTTP_POST, [](AsyncWebServerRequest *request){

ssid = request->getParam("ssid",true)->value();
password = request->getParam("password",true)->value();

Serial.println("WiFi guardado");

request->send(200,"text/plain","Guardado");

});

server.on("/setsensor", HTTP_POST, [](AsyncWebServerRequest *request){

config.samples = request->getParam("samples",true)->value().toInt();
config.integration = request->getParam("integration",true)->value().toInt();
config.gain = request->getParam("gain",true)->value().toInt();

request->send(200,"text/plain","Configuracion guardada");

});

server.on("/start", HTTP_GET, [](AsyncWebServerRequest *request){

takeMeasurements();

request->send(200,"text/plain","Mediciones iniciadas");

});

server.on("/download", HTTP_GET, [](AsyncWebServerRequest *request){

request->send(SD,"/data.csv","text/csv",true);

});

server.begin();

}
