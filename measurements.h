void takeMeasurements(){

File file = SD.open("/data.csv", FILE_APPEND);

for(int i=0;i<10;i++){

float data[18];

data[0] = sensor.getCalibratedA();
data[1] = sensor.getCalibratedB();
data[2] = sensor.getCalibratedC();
data[3] = sensor.getCalibratedD();
data[4] = sensor.getCalibratedE();
data[5] = sensor.getCalibratedF();
data[6] = sensor.getCalibratedG();
data[7] = sensor.getCalibratedH();
data[8] = sensor.getCalibratedR();
data[9] = sensor.getCalibratedI();
data[10] = sensor.getCalibratedS();
data[11] = sensor.getCalibratedJ();
data[12] = sensor.getCalibratedT();
data[13] = sensor.getCalibratedU();
data[14] = sensor.getCalibratedV();
data[15] = sensor.getCalibratedW();
data[16] = sensor.getCalibratedK();
data[17] = sensor.getCalibratedL();

for(int j=0;j<18;j++){

file.print(data[j]);
file.print(",");

}

file.println();

delay(1000);

}

file.close();

}
