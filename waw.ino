#include "./indolyzer_iot.h"
unsigned long durationInMili;
float temperatureCheck = 0;

bool initPrediction = true;
bool hasNotUpdate = true;

float startTemperature = 0, lastTemperature = 0;

void setup()
{
    Serial.begin(9600);
    Serial2.begin(9600);
    sensorSuhu.begin();
    gprs_begin();
}

void loop()
{
   temperatureCheck = ambilSuhu();
  
   //Update Temperature
   Temperature = temperatureCheck;
   updateTemperatureData();

   if(initPrediction){
      startTemperature = temperatureCheck;
      initPrediction = false;
   }

   if(temperatureCheck > 29.5){
      durationInMili = millis();
   }else if(temperatureCheck >= 13.5 && temperatureCheck <= 29.5){
      if(hasNotUpdate){
        prediction = (durationInMili / 1000) / 60;
        start_temperature = startTemperature;
        updatePredictionData(); 
      }

     if(statusMessage.equals("PREDICTION UPDATE")){
       Serial.println("RESET DURASI & STATUS");
       durationInMili = 0;
       statusMessage = "";
       hasNotUpdate = false;
     }

     if(!hasNotUpdate && ambilSuhu() > 29.5){
        initPrediction = true;
        hasNotUpdate = true;
     }
   }else{
     Serial.println("Temperature under threshold");  
   }

   delay(1000);   
}

float ambilSuhu()
{
  sensorSuhu.requestTemperatures();
  float suhu = sensorSuhu.getTempCByIndex(0);
  return suhu;   
}


//void loop()
//{
//    int d = DHT.read11(DHT11_PIN);
//    Temperature = String(DHT.temperature);
//    Humidity = String(DHT.humidity);
//    update_data();
//}
