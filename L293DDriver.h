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
#define MOT1_CTRL1  8
#define MOT1_CTRL2  7
#define MOT2_CTRL1  4
#define MOT2_CTRL2  3

/** Motor directrions */
#define DIR_FWD     1
#define DIR_BWD     0

/** Indecies of motors */
#define MOT_1       0
#define MOT_2       1
#define MOT_ALL     2

/* struct motor - Values assosiated with a motor
 *  @ctrl1: Control pin 1
 *  @ctrl2: Control pin 2
 *  @ep:    PWM pin
 *  @spd:   Current speed of motor
 *  @dir:   Current directon of motor
 */
typedef struct motor {
    uint8_t ctrl1;
    uint8_t ctrl2;
    uint8_t ep;
    uint8_t spd;
    uint8_t dir;
} Motor;

class L293DDriver {
    public:
        L293DDriver(int mot1_ctrl1, int mot1_ctrl2, int mot2_ctrl1, int mot2_ctrl2, int mot1_ep, int mot2_ep);
        L293DDriver(int mot1Ctrl1, int mot1int ep1, int ep2);
        int init(void);
        void setSpeed(int motor, uint8_t speed);
        void setDirection(int motor, int direction);
        void drive(int motor);
        void stop(int motor);

    private:
        Motor motor[MOT_ALL];
};

#endif
