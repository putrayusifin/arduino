void updateTemperatureData()
{
  serial_purge();

  Serial.println();
  Serial.println("[UPDATE DATA]");
  Serial.println(F("AT+HTTPINIT")); // untuk mengaktifkan http
  Serial2.println(F("AT+HTTPINIT"));
  gprs_response(2000);
  
  Serial.println(F("AT+HTTPSSL=0")); // enable HTTPS
  Serial2.println(F("AT+HTTPSSL=0"));
  gprs_response(20000);
  Serial.println(F("AT+HTTPPARA=\"CID\",1")); //init https service angka 1 artinya oke  
  Serial2.println(F("AT+HTTPPARA=\"CID\",1"));
  gprs_response(2000);
  Serial.print("AT+HTTPPARA=\"URL\",\"http://safe-gorge-69158.herokuapp.com/sensor.php?deviceid=");
  Serial.print(DEVICEID);
  Serial.print("&temperature=");
  Serial.print(Temperature);
  Serial.print("&humidity=");
  Serial.print(Humidity);
  Serial.print("\"\r\n");
  Serial2.print("AT+HTTPPARA=\"URL\",\"http://safe-gorge-69158.herokuapp.com/sensor.php?deviceid=");
  Serial2.print(DEVICEID);
  Serial2.print("&temperature=");
  Serial2.print(Temperature);
  Serial2.print("&humidity=");
  Serial2.print(Humidity);
  Serial2.print("\"\r\n");
  delay(10000);
  serial_purge();
  Serial2.println(F("AT+HTTPACTION=1")); //metode pengambilan datanya POST
  delay(9000);
  serial_purge();
  Serial2.println(F("AT+HTTPREAD")); // Perintah AT digunakan untuk membaca respons server HTTP
  gprs_response(5000);
  Serial2.println(F("AT+HTTPTERM")); // mengakhiri sesi HTTP.
  gprs_response(2000);
  Serial.println("[UPDATE SELESAI]");
  Serial.println();
}

void updatePredictionData()
{
  serial_purge();

  Serial.println();
  Serial.println("[UPDATE DATA]");
  Serial.println(F("AT+HTTPINIT")); // untuk mengaktifkan http
  Serial2.println(F("AT+HTTPINIT"));
  gprs_response(2000);
  
  Serial.println(F("AT+HTTPSSL=0")); // enable HTTPS
  Serial2.println(F("AT+HTTPSSL=0"));
  gprs_response(20000);
  Serial.println(F("AT+HTTPPARA=\"CID\",1")); //init https service angka 1 artinya oke  
  Serial2.println(F("AT+HTTPPARA=\"CID\",1"));
  gprs_response(2000);
  Serial.print("AT+HTTPPARA=\"URL\",\"http://safe-gorge-69158.herokuapp.com/prediction.php?deviceid=");
  Serial.print(DEVICEID);
  Serial.print("&start_temperature=");
  Serial.print(start_temperature);
  Serial.print("&duration=");
  Serial.print(prediction);
  Serial.print("\"\r\n");
  Serial2.print("AT+HTTPPARA=\"URL\",\"http://safe-gorge-69158.herokuapp.com/prediction.php?deviceid=");
  Serial2.print(DEVICEID);
  Serial2.print("&start_temperature=");
  Serial2.print(start_temperature);
  Serial2.print("&duration=");
  Serial2.print(prediction);
  Serial2.print("\"\r\n");
  delay(10000);
  serial_purge();
  Serial2.println(F("AT+HTTPACTION=1")); //metode pengambilan datanya POST
  delay(9000);
  serial_purge();
  Serial2.println(F("AT+HTTPREAD")); // Perintah AT digunakan untuk membaca respons server HTTP
  statusMessage = "PREDICTION UPDATE"; //Memasukkan response ke variabel
  gprs_response(5000);
  Serial2.println(F("AT+HTTPTERM")); // mengakhiri sesi HTTP.
  gprs_response(2000);
  Serial.println("[UPDATE SELESAI]");
  Serial.println();
}
