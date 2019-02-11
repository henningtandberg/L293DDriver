#include "L293DDriver.h"
#include "Arduino.h"

/**
 *  L293DDriver
 */

/** L293DDRiver() - Contructor 1.
 *  @m1_inPin1:
 *  @m1_inPin2:
 *  @m2_inPin1:
 *  @m2_inPin2:
 *  @m1_pwmPin:
 *  @m2_pwmPin:
 *
 */        
L293DDriver(uint8_t m1_inPin1, uint8_t m1_inPin2, uint8_t m2_inPin1, uint8_t m2_inPin2, uint8_t m1_pwmPin, uint8_t m2_pwmPin) {
    dcmotors[M1] = L293DDCMotor(m1_pwnPin, m1_inPin1, m1_inPin2);
    dcmotors[M2] = L293DDCMotor(m2_pwnPin, m2_inPin1, m2_inPin2); 
}

/** L293DDriver() - Contructor 2.
 *  @m1_pwm:
 *  @m2_pwm:
 *
 */
L293DDriver(uint8_t m1_pwmPin, uint8_t m2_pwmPin);
    this->L293Driver(M1_IN_PIN1, M1_IN_PIN2, M2_IN_PIN1, M2_IN_PIN2, M1_PWM_PIN, M2_PWM_PIN);
}

/** init() - Initializes the driver.
 *
 */
void L293DDriver::begin(void) {
    if(dcmotors[M1].pwmPin == dcmotors[M2].pwmPin)
        while(1);

    // TODO: isPWM
    
    for (int i = 0; i < MALL; i++) {
        pinMode(dcmotors[i].pwmPin, OUTPUT);
        pinMode(dcmotors[i].inPin1, OUTPUT);
        pinMode(dcmotors[i].inPin2, OUTPUT);

        digitalWrite(dcmotors[i].pwmPin, LOW);
        digitalWrite(dcmotors[i].inPin1, LOW);
        digitalWrite(dcmotors[i].inPin2, LOW);
    }
}


L293DDCMotor * L293DDriver::getDCMotor(uint8_t motor) {
    if (motor < M1 || motor > M2) {
        return NULL;
    }

    return &dcmotors[motor];
} 
/**
 *  L293DDCMotor
 */

/**
 *
 */
L293DDCMotor::L293DDCMotor(uint8_t pwmPin, uint8_t inPin1, uint8_t inPin2) {
    this->pwmPin = pwmPin;
    this->inPin1 = inPin1;
    this->inPin2 = inPin2;
    this->speed = 0;
    this->direction = DIR_STOP;
}

/**
 *
 */
L293DDCMotor::L293DDCMotor(void) {
    this->pwmPin = 0;
    this->inPin1 = 0;
    this->inPin2 = 0;
    this->speed = 0;
    this->direction = DIR_STOP;
}

/** setSpeed() - Sets the speed of the specified motor.
 *  @speed:
 *
 */
void L293DDCMotor::setSpeed(uint8_t speed) {
    this->speed = speed;
    analogWrite(this->pwmPin, this->speed);
}

/** setDirection() - Sets the direction of the specified motor.
 *  @direction:
 *
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
