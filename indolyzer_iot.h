#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

SoftwareSerial Serial2(10, 11); //GPRS
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensorSuhu(&oneWire);
 
//float suhuSekarang;

String Temperature = "", Humidity = "", prediction = "", start_temperature = "";
String statusMessage = "";

int DEVICEID = 4;
#define GPRS_RST_PIN 14
#define DHT11_PIN 4
