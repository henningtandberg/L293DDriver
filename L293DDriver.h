/**
*   Author: Henning P. Tandberg
*   File:   L293DDriver.h
*
*   Pinout:
*   ---------------------------------------------
*   |   L293D   |   Arduino                     |
*   ---------------------------------------------
*   |   1       |   A PWM pin | 1,2EN           |
*   |   2       |   Control pin 1 motor 1       |
*   |   3       |   One terminal on motor 1     |
*   |   4       |   UNUSED                      |
*   |   5       |   UNUSED                      |
*   |   6       |   Other terminal on motor 1   |
*   |   7       |   Control pin 2 motor 1       |
*   |   8       |   +ve of battery              |
*   |   9       |   A PWM pin | 3,4EN           |
*   |   10      |   Control pin 1 motor 2       |
*   |   11      |   One terminal on motor 2     |
*   |   12      |   UNUSED                      |
*   |   13      |   GND (battery and arduino)   |   
*   |   14      |   Other terminal on motor 2   |
*   |   15      |   Control pin 2 motor 2       |
*   |   16      |   VCC (5V)                    |
*   ---------------------------------------------
*/

#ifndef _L293DDRIVER_H
#define _L293DDRIVER_H

/** Default pins if not specified */
#define M1_IN_PIN1  8
#define M1_IN_PIN2  7
#define M2_IN_PIN1  4
#define M2_IN_PIN2  3
#define M1_PWM_PIN  11
#define M2_PWM_PIN  10

/** Motor directrions */
#define DIR_FWD     0
#define DIR_BWD     1
#define DIR_STOP    2

/** Indecies of motors */
#define M1          0
#define M2          1
#define MALL        2

class L293DDCMotor {
    public:
        L293DMotor(uint8_t pwmPin, uint8_t inPin1, uint8_t inPin2);
        L293DMotor(void);

        void setSpeed(uint8_t speed);
        void drive(uint8_t direction);

    private:
        uint8_t pwmPin;
        uint8_t inPin1;
        uint8_t inPin2;
        uint8_t speed;
        uint8_t direction;
};

class L293DDriver {
    public:
        L293DDriver(uint8_t m1_inPin1, uint8_t m1_inPin2, uint8_t m2_inPin1, uint8_t m2_inPin2, uint8_t m1_pwmPin, uint8_t m2_pwmPin);
        L293DDriver(uint8_t m1_pwmPin, uint8_t m2_pwmPin);
        void begin(void);
        L293DDCMotor * getDCMotor(uint8_t motor);

    private:
        L293DDCMotor dcmotors[MALL];
};

#endif
