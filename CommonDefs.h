// CommonDefs.h
#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#define SENSOR_AMOUNT 5
#define SENSOR_BUFFER 10
#define SENSOR_POLL_FREQ 10000 // Hz
#define BLE_BYTE_LENGTH 16     //Bytes being sent to the HM10 (4-byte int, 4-byte PID KP, 4-byte PID KI, 4-byte PID KD)
#define BLE_POLL_RATE 20      // Hz
#define TVG 1.5f
#define TVE 2.8f

#define GAIN_PROPORTIONAL 5.0f //scale in the single digits now
#define GAIN_INTEGRAL 0.0f
#define GAIN_DERIVATIVE 0.0f
#define GAIN_AGGRESSIVE 1.2
#define GAIN_SCALE_DOWN 200.0f //used to scale down gain values to realisitc speeds

#define BASE_SPEED 0.3f

#define EASING_FACTOR 2.5           // For initial PWM ease between PID output and internal PWM output
#define S_EASING_FACTOR 0.05         // For secondary correction between internal PWM (takes into account wheel speed)
#define PWM_DIFFERENTIAL_FACTOR 0.05 // difference between the two PWM duty cycles (used for determining condition to enforce straight line logic)
#define BRAKING_FACTOR 0.035

#define PWM_FREQUENCY 20000 // Hz
#define SYS_OUTPUT_RATE 1000  // Hz
#define SYS_LCD_STEPDOWN 100  //Step down multiplier for LCD output

#define WHEEL_DIAMETER 0.083     // meters
#define GEAR_RATIO (1.0 / 15.0) // Gear ratio (GB1)
#define PI 3.1415
#define CPR 512          // Counts per revolution for the encoder
#define TCRT_MAX_VDD 5.0 // Max voltage for TCRT sensors
#define DEFAULT_PWM 0.5f // Default PWM duty cycle

#define Kp 0.01
#define Ki 0.001
#define Kd 0.01


typedef enum
{
    turnAround,
    init,
    RCforward,
    RCbackwards,
    RCturnleft,
    RCturnright,
    RCstop,
    RCturbo
} pstate;
extern pstate ProgramState;

#endif // COMMON_DEFS_H
