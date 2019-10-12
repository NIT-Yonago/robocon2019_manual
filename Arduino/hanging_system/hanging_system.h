#ifndef HANGING_SYSTEM_H
#define HANGING_SYSTEM_H

#include <Arduino.h>
#include <Servo.h>

class hanging_system
{
private:
    unsigned long supply_start_time, air_change_time;
    boolean is_supplying, now_air_pos, air_is_moving, has_requested_hanging;
    uint8_t air, servo_p, servo_m;
    Servo spp, spm;
    unsigned int t_1, t_2, t_c, deg_1, deg_2;
    void air_change();
    void servo_move(int deg);

public:
    hanging_system(uint8_t spp_pin, uint8_t spm_pin, uint8_t air_pin, unsigned int deg_pdef, unsigned int deg_mdef, unsigned int t1, unsigned int t2, unsigned int tc);
    void always_run_function();
    void hang(boolean hang_pos, unsigned int deg1, unsigned int deg2);
    void empty_hang(boolean hang_pos);
    void show_all_state();
};

#endif
