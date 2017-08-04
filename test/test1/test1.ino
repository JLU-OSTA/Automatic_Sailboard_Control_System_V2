#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"



void setup()
{
    Serial.begin(9600);
    Wire.begin();
    accelgyro.initialize();
    
}

void loop()
{
    t2=millis();
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    s=(gz+271.4)/131;
    ang+=s;
    //*(t2-t1)+0.433;
    delay(100);
    Serial.println(ang);
    t1=t2;
}

