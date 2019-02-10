#include "L293DDriver.h"
#include "Arduino.h"

/** L293DDRiver() - Contructor 1.
 *  @mot1_ctrl1:
 *  @mot1_ctrl2:
 *  @mot2_ctrl1:
 *  @mot2_ctrl2:
 *  @mot1_ep:
 *  @mot2_ep:
 *
 */
L293DDriver::L293DDriver(int mot1_ctrl1, int mot1_ctrl2, int mot2_ctrl1, int mot2_ctrl2, int mot1_ep, int mot2_ep) {
   motors[MOT_1] = {
        .ctrl1 = mot1_ctrl1,
        .ctrl2 = mot1_ctrl2,
        .ep = mot1_ep,
        .spd = 0,
        .dir = DIR_FWD
    };    
    motors[MOT_2] = {
        .ctrl1 = mot2_ctrl1,
        .ctrl2 = mot2_ctrl2,
        .ep = mot2_ep,
        .spd = 0,
        .dir = DIR_FWD
    };
}

/** L293DDriver() - Contructor 2.
 *  @mot1_ep:
 *  @mot2_ep:
 *
 */
L293DDriver::L293DDriver(int mot1_ep, int mot2_ep) {
    this->L293Driver(
        MOT1_CTRL1,
        MOT1_CTRL2,
        MOT2_CTRL1,
        MOT2_CTRL2,
        mot1_ep,
        mot2_ep
    );
}

/** init() - Initializes the driver.
 *
 */
void L293DDriver::init(void) {
    if(motors[MOT_1].ep == motors[MOT_2].ep)
        while(1);

    // TODO: isPWM
    
    for (int i = 0; i < MOT_ALL; i++) {
        pinMode(motors[i].ep, OUTPUT);
        pinMode(motors[i].ctrl1, OUTPUT);
        pinMode(motors[i].ctrl2, OUTPUT);
    }
}

/** setSpeed() - Sets the speed of the specified motor.
 *  @motor:
 *  @speed:
 *
 */
void L293DDriver::setSpeed(int motor, uint8_t speed) {

    if (motor > MOT_ALL || motor < MOT_1)
        return;

    if (motor == MOT_ALL)
        for (int i = 0; i < MOT_ALL; i++)
            motors[i].spd = speed;
    else
        motors[motor].spd = speed;

}

/** setDirection() - Sets the direction of the specified motor.
 *  @motor:
 *  @direction:
 *
 */
void L293DDriver::direction(int motor, int dir) {
    /*if(dir) {

    } else {

    }*/
}

/** drive() - Activates the specified motor.
 *  @motor:
 *
 */
void L293DDriver::drive(int motor) {

    if (motor > MOT_ALL || motor < MOT_1)
        return;

    if (motor == MOT_ALL)
        for (int i = 0; i < MOT_ALL; i++)
            analogWrite(motors[i].ep, motors[i].spd);
    else
        analogWrite(motors[motor].ep, motors[i].spd);

}

/** stop() - Deactivates the specified motor.
 *  @motor:
 *
 */
void L293DDriver::stop(int motor) {

    if (motor > MOT_ALL || motor < MOT_1)
        return;

    if (motor == MOT_ALL)
        for (int i = 0; i < MOT_ALL; i++)
            analogWrite(motors[i].ep, LOW);
    else
        analogWrite(motors[motor].ep, LOW);

}
