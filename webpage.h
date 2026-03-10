const char index_html[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html>

<head>
<title>Spectrometer</title>
</head>

<body>

<h2>Configuracion WiFi</h2>

<form action="/setwifi" method="POST">

SSID:<br>
<input type="text" name="ssid"><br>

Password:<br>
<input type="text" name="password"><br>

<input type="submit" value="Guardar">

</form>

<hr>

<h2>Configuracion Sensor</h2>

<form action="/setsensor" method="POST">

Numero de muestras:<br>
<input type="number" name="samples"><br>

Integracion:<br>
<input type="number" name="integration"><br>

Ganancia:<br>
<input type="number" name="gain"><br>

<input type="submit" value="Guardar">

</form>

<hr>

<h2>Control</h2>

<a href="/start">Iniciar mediciones</a>

<br><br>

<a href="/download">Descargar datos CSV</a>

</body>

</html>

)rawliteral";
