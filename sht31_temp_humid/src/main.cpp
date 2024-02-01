#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "Adafruit_SHT31.h"  // sht31 lib 
// put function declarations here:

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = sht31.readTemperature();
  float hum = sht31.readHumidity();

  if (! isnan(temp)) { 
    Serial.print("Temperature(°C): "); 
    Serial.print(temp); 
    Serial.print("\t\t");
  } else { 
    Serial.println("Failed to read temperature!");
  }
  
  if (! isnan(hum)) {  
    Serial.print("Humidity(%): "); 
    Serial.println(hum);
  } else { 
    Serial.println("Failed to read humidity!");
  }

  delay(1000);
}

