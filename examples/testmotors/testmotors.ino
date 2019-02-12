#include <L293DDriver.h>



void setup() {
    uint8_t testspeeds[] = {0, 32, 64, 128, 255};

    L293DDriver driver(8, 7, 4, 3, 11, 10);
    driver.begin();

    L293DDCMotor *m1 = driver.getDCMotor(M1);
    L293DDCMotor *m2 = driver.getDCMotor(M2); 
 
    Serial.begin(9600);

    /*
     *  Speed test for motor 1.
     */ 
    
    Serial.println("\nMotor 1 Speed Test: ");

    for(int i = 0; i < sizeof(testspeeds); i++) { 
        Serial.println("- Speed set to: " + (String)testspeeds[i]);
        m1->setSpeed(testspeeds[i]);

        Serial.println("- - Drive FORWARDS for 2 seconds.");
        m1->drive(DIR_FWD);
        delay(2000);

        Serial.println("- - Drive BACKWARDS for 2 seconds.");
        m1->drive(DIR_BWD);
        delay(2000);

        Serial.println("- - - Stop for 1 second.");
        m1->drive(DIR_STOP);
        delay(1000);
    }

    /*
     *  Speed test for motor 2.
     */ 
    
    Serial.println("\nMotor 2 Speed Test: ");

    for(int i = 0; i < sizeof(testspeeds); i++) { 
        Serial.println("- Speed set to: " + (String)testspeeds[i]);
        m2->setSpeed(testspeeds[i]);

        Serial.println("- - Drive FORWARDS for 2 seconds.");
        m2->drive(DIR_FWD);
        delay(2000);

        Serial.println("- - Drive BACKWARDS for 2 seconds.");
        m2->drive(DIR_BWD);
        delay(2000);

        Serial.println("- - - Stop for 1 second.");
        m2->drive(DIR_STOP);
        delay(1000);
    }
}

void loop() {}
