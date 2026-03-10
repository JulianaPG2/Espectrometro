void initWebServer(){

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){

request->send(200,"text/html",index_html);

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
