#include <L293DDriver.h>

L293DDriver driver(5,6);
uint8_t testspeeds[] = {0, 32, 64, 128, 255};

void drive_test(int motor) {
    for(int i = 0; i < sizeof(testspeeds); i++) {
        Serial.println("- Set speed: " + (String)testspeeds[i]);
        driver.speed(motor, testspeeds[i]);
        delay(500);

        Serial.println("- - Drive for 2 seconds.");
        driver.drive(motor);
        delay(2000);

        Serial.println("- - - Stop.");
        driver.stop(motor);
        delay(500);
    }
}

void setup() {
    Serial.begin(9600);

    /*
    *   Init
    */

    Serial.print("Test driver.init(): ");
    if( driver.init() == -1 ) {
        Serial.println("FAIL!");
    } Serial.println("OK!");

    /*
    *   Single motor test: M2
    */

    Serial.println("\n\n### Single motor test: M1 ###\n");

    Serial.println("- Set direction: FWD");
    driver.direction(M1, FWD);
    delay(1000);

    drive_test(M1);

    Serial.println("Set direction: BWD");
    driver.direction(M1, BWD);
    delay(1000);

    drive_test(M1);

    Serial.println("\n### Single motor test complete ###");

    /*
    *   Single motor test: M2
    */

    Serial.println("\n\n### Single motor test: M2 ###\n");

    Serial.println("Set direction: FWD");
    driver.direction(M2, FWD);
    delay(1000);

    drive_test(M2);

    Serial.println("Set direction: BWD");
    driver.direction(M2, BWD);
    delay(1000);

    drive_test(M2);

    Serial.println("\n### Single motor test complete ###");

    /*
    *   Multi motor test: MALL
    */

    Serial.println("\n\n### Multi motor test: MALL ###\n");

    Serial.println("Set direction: FWD");
    driver.direction(MALL, FWD);
    delay(1000);

    drive_test(MALL);

    Serial.println("Set direction: BWD");
    driver.direction(MALL, BWD);
    delay(1000);

    drive_test(MALL);

    Serial.println("Set direction M1: FWD & M2: BWD");
    driver.direction(M1, FWD);
    driver.direction(M2, BWD);
    delay(1000);

    drive_test(MALL);

    Serial.println("Set direction M1: BWD & M2: FWD");
    driver.direction(M1, BWD);
    driver.direction(M2, FWD);
    delay(1000);

    drive_test(MALL);

    Serial.println("\n### Multi motor test complete!");

}

void loop() {}
