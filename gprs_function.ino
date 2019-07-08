void gprs_reset()
{
  Serial.println();
  Serial.println("[RESET GPRS]");
  pinMode(GPRS_RST_PIN, OUTPUT);
  gprs_response(500);
  digitalWrite(GPRS_RST_PIN, HIGH);
  gprs_response(10);
  digitalWrite(GPRS_RST_PIN, LOW);
  gprs_response(100);
  digitalWrite(GPRS_RST_PIN, HIGH);
  gprs_response(10000);
  Serial.println("[RESET DONE]");
  Serial.println();
}

void gprs_begin()
{
  gprs_reset();
  serial_purge();

  Serial.println();
  Serial.println("[INIT GPRS]");
  Serial.println(F("ATE0"));
  Serial2.println(F("ATE0"));
  gprs_response(2000);
  Serial.println(F("AT+CFUN=1")); // perintah penuh
  Serial2.println(F("AT+CFUN=1"));
  gprs_response(2000);
  Serial.println(F("AT+CREG?")); // on/off sih sim900l
  Serial2.println(F("AT+CREG?"));
  gprs_response(3000);
  Serial.println(F("AT+SAPBR=3,1,\"Contype\",\"GPRS\"")); // mengatur jenis 
  Serial2.println(F("AT+SAPBR=3,1,\"Contype\",\"GPRS\""));
  gprs_response(3000);
  Serial.println(F("AT+SAPBR=3,1,\"APN\",\"internet\"")); // atur menuju internet
  Serial2.println(F("AT+SAPBR=3,1,\"APN\",\"internet\""));
  gprs_response(3000);
    //Serial.println(F("AT+SAPBR=0,1"));  // aktifkan gprs
  //Serial2.println(F("AT+SAPBR=0,1"));
  gprs_response(5000);
  Serial.println(F("AT+SAPBR=1,1"));  // aktifkan gprs
  Serial2.println(F("AT+SAPBR=1,1"));
  gprs_response(5000);
  Serial.println(F("AT+SAPBR=2,1")); // jika koneksi sudah diatur dengan benar, jika kita mendapatkan kembali alamat IP maka kita dapat melanjutkan
  Serial2.println(F("AT+SAPBR=2,1"));
  gprs_response(5000);
  Serial.println("[INIT DONE]");
  Serial.println();
}

void gprs_response(int Time)
{
  for (int i = 0; i < Time; i++)
  {
    while (Serial2.available() > 0)
    {
      Serial.write(Serial2.read());
    }
    delay(1);
  }
}

void serial_purge()
{
  while (Serial.available())
  {
    Serial.read();
  }
  while (Serial2.available())
  {
    Serial2.read();
  }
}
