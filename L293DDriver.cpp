/** Author: Henning P. Tandberg
 *  File:   L293DDriver.cpp
 */

#include "L293DDriver.h"
#include "Arduino.h"

/**
 *  L293DDriver
 */

/** L293DDRiver() - Contructor 1.
 *  @m1_inPin1: Input pin 1 for motor 1
 *  @m1_inPin2: Input pin 2 for motor 1
 *  @m2_inPin1: Input pin 1 for motor 2
 *  @m2_inPin2: Input pin 2 for motor 2
 *  @m1_pwmPin: PWM pin for motor 1
 *  @m2_pwmPin: PWM pin for motor 2
 *
 */        
L293DDriver::L293DDriver(uint8_t m1_inPin1, uint8_t m1_inPin2, uint8_t m2_inPin1, uint8_t m2_inPin2, uint8_t m1_pwmPin, uint8_t m2_pwmPin) {
    dcmotors[M1] = L293DDCMotor(m1_pwmPin, m1_inPin1, m1_inPin2);
    dcmotors[M2] = L293DDCMotor(m2_pwmPin, m2_inPin1, m2_inPin2); 
}

/** L293DDriver() - Contructor 2.
 *  @m1_pwm: PWM pin for motor 1
 *  @m2_pwm: PWM pin for motor 2
 *
 */
L293DDriver::L293DDriver(uint8_t m1_pwmPin, uint8_t m2_pwmPin) :
    L293DDriver(M1_IN_PIN1, M1_IN_PIN2, M2_IN_PIN1, M2_IN_PIN2, m1_pwmPin, m2_pwmPin) {}

/** init() - Initializes the driver.
 *
 */
void L293DDriver::begin(void) {
    for (int i = 0; i < MALL; i++) {
        this->dcmotors[i].init();
    }
}

/** getDCMotor() - Returns a motor object.
 *  @motor: Index of motor (M1 or M2)
 *
 */
L293DDCMotor * L293DDriver::getDCMotor(uint8_t motor) {
    if (motor < M1 || motor > M2) {
        return NULL;
    }

    return &dcmotors[motor];
}

/**
 *  L293DDCMotor
 */

/** L293DDCMotor() - Constructor 1.
 *  @pwmPin: PWM pin for motor speed control
 *  @inPin1: Input pin 1
 *  @inPin2: Input pin 2
 *
 */
L293DDCMotor::L293DDCMotor(uint8_t pwmPin, uint8_t inPin1, uint8_t inPin2) {
    this->pwmPin = pwmPin;
    this->inPin1 = inPin1;
    this->inPin2 = inPin2;
    this->speed = 0;
    this->direction = DIR_STOP;
}

/** L293DDCMotor() - Constructor 2.
 *
 */
L293DDCMotor::L293DDCMotor(void) {
    this->pwmPin = 0;
    this->inPin1 = 0;
    this->inPin2 = 0;
    this->speed = 0;
    this->direction = DIR_STOP;
}

/** init() - Initializes the motor (pins, speed and direction)
 *
 */
void L293DDCMotor::init(void) {
    pinMode(this->pwmPin, OUTPUT);
    pinMode(this->inPin1, OUTPUT);
    pinMode(this->inPin2, OUTPUT);

    digitalWrite(this->pwmPin, LOW);
    digitalWrite(this->inPin1, LOW);
    digitalWrite(this->inPin2, LOW);
}

/** setSpeed() - Sets the speed of the specified motor.
 *  @speed: New Speed of motor.
 *
 */
void L293DDCMotor::setSpeed(uint8_t speed) {
    this->speed = speed;
    analogWrite(this->pwmPin, this->speed);
}

/** setDirection() - Sets the direction of the specified motor.
 *  @direction: New direction of motor.
 *
 *  Direction options:
 *      - DIR_FWD   (Clockwise)
 *      - DIR_BWD   (Anti clockwise)
 *      - DIR_STOP  (Stop the motor)
 */
void L293DDCMotor::drive(uint8_t direction) {
    switch (direction) {
        case DIR_FWD:
            digitalWrite(this->inPin1, LOW);
            digitalWrite(this->inPin2, HIGH);
            break;
        case DIR_BWD:
            digitalWrite(this->inPin2, LOW);
            digitalWrite(this->inPin1, HIGH);
            break;
        case DIR_STOP:
            digitalWrite(this->inPin1, LOW);
            digitalWrite(this->inPin2, LOW);
            break;
    }
}
