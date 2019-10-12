#include <Arduino.h>
#include "gyro_integral.h"

gyro_integral::gyro_integral(void)
{
}
void gyro_integral::init(int setup_count)
{
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
    for (int i = 0; i < setup_count; i++)
    {
        gyro.read();
        sum += gyro.g.z;
        delay(6);
    }
    gyro_offset = sum / setup_count;
    last_time = micros();
}
void gyro_integral::integral()
{
    gyro.read();
    unsigned long now = micros();
    int dt = now - last_time;
    last_time = now;
    gyro_val = gyro_val * 0.9 + ((int)gyro.g.z - gyro_offset) * 0.1;
    robot_angle += gyro_val * dt * 0.00875 / 1000000.0;
}
void gyro_integral::print_gyro_data()
{
    Serial.print((int)gyro.g.z * 0.00875);
    Serial.print(",");
    Serial.print(gyro_val * 0.00875);
    Serial.print(",");
    Serial.println(robot_angle);
}
