#include <Wire.h>
#include <L3G.h>

L3G gyro;

float gyro_val = 0.0;
float gyro_offset = 0.0;
float robot_angle = 0;
unsigned long last_time = 0;

void int_200Hz()
{
    gyro.read();
    unsigned long now = micros();
    int dt = now - last_time;
    last_time = now;
    gyro_val = gyro_val * 0.9 + ((int)gyro.g.z - gyro_offset) * 0.1;
    robot_angle += gyro_val * dt * 0.00875 / 1000000.0;
    Serial.print(now % 3);
    Serial.print(",");
    Serial.print((int)gyro.g.z * 0.00875);
    Serial.print(",");
    Serial.print(gyro_val * 0.00875);
    Serial.print(",");
    Serial.println(robot_angle);
}

void setup()
{
    Serial.begin(115200);
    Wire.begin();

    if (!gyro.init())
    {
        Serial.println("Failed to autodetect gyro type!");
        while (1)
            ;
    }

    gyro.enableDefault(); //250deg/s,190Hz DR,50Hz BW
    last_time = micros();
    long sum = 0;
    for (int i = 0; i < 500; i++)
    {
        gyro.read();
        sum += gyro.g.z;
        delay(6);
    }
    gyro_offset = sum / 500.0;
}

void loop()
{
    int_200Hz();
    delay(10);
}