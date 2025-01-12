/*
  Author: Crawford Lieu
  Learning Intention:
  The students will learn to use the I2C communication protocol to send and receive
  data with 2IC sensors and actuators

  Success Criteria:
    1.  I understand that I2C is a communication protocol
    2.  I understand that each I2C needs it's own I2C Channel
    3.  I understand that communicating to I2C modules is similar to the serial monitor
    4.  I understand I need to include the `wire-h` library
    5.  I understand that I need to look at the documentation and example code for each I2C module
    6.  I can sucessfully send data to the I2C OLED display
    7.  I can successfully receive data from either Temperature & Humidity Sensor, Air pressure Sensor or Acceleration Sensor in the sensor kit.

  Student Notes:
    
  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/communication/wire/


  Examples:
    OLED: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/0.96_OLED_Display/0.96_OLED_Display.ino
    3 Axis: Acceleromter: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/3_Axis_Accel_Sensor/3_Axis_Accel_Sensor.ino
    Temperature & Humidity: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/Temp_and_Humid_Sensor/Temp_and_Humid_Sensor.ino
      DOWNLOAD .cpp AND .ino DHT FILES!

    Air Pressure Sensor: https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/TempeHS_Sensor_Catalogue/Sensor%20Kit/Air_Pressure_Sensor/Air_Pressure_Sensor.ino
*/

// Include I2C
#include <Arduino.h>
#include <Wire.h>

// OLED Display
#include <U8g2lib.h>

// Air Pressure
#include "Seeed_BMP280.h"

// String myMessage = "";
// String myMessage2 = "";

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA, /* reset=*/U8X8_PIN_NONE);  // High speed I2C

BMP280 bmp280;

void setup() {
  // Setup serial monitor and debug.
  Serial.begin(9600);
  Serial.println("");
  Serial.println("SM working & configured @9600.");
  Serial.println("-------------------------------------------");

  // Set up OLED screen
  u8g2.begin();

  // Begin comms with pressure sensor.
  if (!bmp280.init()) {
    Serial.println("Device error!");
  }
}

void loop() {
  // Measure Air.
  /*
  float myTemp = bmp280.getTemperature();
  float myPressure = bmp280.getPressure();
  float myAltitude = bmp280.calcAltitude(myPressure);
  */

  // Delcare variables.\njm
  // String myMessage = "Good Morning!";
  // String myMessage2 = "Today's temperature: " + String(myTemp) + "°C";

  // measureAir();
  printToOLED(myTemp(), myPressure());  // Call function.
}