/**
*   Author: Henning P. Tandberg
*   File:   L293DDriver.h
*
*   Pinout:
*   L293D   -   Arduino |
*   1       -   a PWM pin | 1,2EN
*   2       -   8       | A1
*   3       -   One terminal on motor 1
*   4       -   UNUSED
*   5       -   UNUSED
*   6       -   Other terminal on motor 1
*   7       -   7       | A2
*   8       -   +ve of battery
*   9       -   a PWM pin | 3,4EN
*   10      -   4       | A3
*   11      -   One terminal on motor 2
*   12      -   UNUSED
*   13      -   GND (battery and arduino)
*   14      -   Other terminal on motor 2
*   15      -   3       | A4
*   16      -   VCC (5V)
*/
#ifndef _L293DDRIVER_H
#define _L293DDRIVER_H

#include "Arduino.h"

#define I1  8   //Control pin 1 motor 1
#define I2  7   //Control pin 2 motor 1
#define I3  4   //Control pin 1 motor 2
#define I4  3   //Control pin 2 motor 2

#define M1     0
#define M2     1
#define MALL   2
#define FWD    1
#define BWD    0

class L293DDriver
{
    public:
        L293DDriver(int ep1, int ep2);
        int init(void);
        void speed(int motor, uint8_t speed);
        void direction(int motor, int dir);
        void drive(int motor);
        void stop(int motor);

    private:
        int _ep1, _ep2;
        uint8_t _spd1, _spd2;
};

#endif
