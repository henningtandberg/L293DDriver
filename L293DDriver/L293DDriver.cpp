#include "L293DDriver.h"

/*
*   Public
*/

L293DDriver::L293DDriver(int ep1, int ep2) {
    _spd1 = _spd2 = 0;
    _ep1 = ep1;
    _ep2 = ep2;
}

int L293DDriver::init(void) {
    if(_ep1 == _ep2)
        return -1;

    //Add later?
    /*if(!isPWM(_ep1) || !isPWM(_ep2))
        return -1;*/

    pinMode(_ep1, OUTPUT);
    pinMode(_ep2, OUTPUT);

    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);

    return 0;
}

void L293DDriver::speed(int motor, uint8_t speed) {

    switch (motor) {
        case M1:
            _spd1 = speed;
            break;
        case M2:
            _spd2 = speed;
            break;
        case MALL:
            _spd1 = _spd2 = speed;
            break;
        default:
            break;
    }

}

void L293DDriver::direction(int motor, int dir) {
    /*if(dir) {

    } else {

    }*/
}

void L293DDriver::drive(int motor) {

    switch (motor) {
        case M1:
            analogWrite(_ep1, _spd1);
            break;

        case M2:
            analogWrite(_ep2, _spd2);
            break;

        case MALL:
            analogWrite(_ep1, _spd1);
            analogWrite(_ep2, _spd2);
            break;

        default:
            break;
    }

}

void L293DDriver::stop(int motor) {

    switch (motor) {
        case M1:
            analogWrite(_ep1, _spd1);
            break;

        case M2:
            digitalWrite(_ep2, LOW);
            break;

        case MALL:
            digitalWrite(_ep1, LOW);
            digitalWrite(_ep2, LOW);
            break;

        default:
            break;
    }

}

/*
*   Private
*/
