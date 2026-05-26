#include <Wire.h>

const int LEFT_MOTOR_DIR = 7;
const int RIGHT_MOTOR_DIR = 8;
const int LEFT_MOTOR_PWM = 9;
const int RIGHT_MOTOR_PWM = 10;

const int COMPASS_ADDRESS = 0x60;
const int COMPASS_BEARING_REGISTER = 0x01;

const int TURN_SPEED = 95;
const int HEADING_TOLERANCE = 3;

int targetHeading = 0;

void setup() {
    Serial.begin(9600);
    Wire.begin();

    pinMode(LEFT_MOTOR_DIR, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR, OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);

    stopMotors();

    Serial.println("Embedded Sensor Control System");
    Serial.println("Compass-based turning initialized");
}

void loop() {
    turnToHeading(90);
    delay(2000);

    turnToHeading(180);
    delay(2000);

    turnToHeading(270);
    delay(2000);

    turnToHeading(0);
    delay(5000);
}

int readCompassHeading() {
    Wire.beginTransmission(COMPASS_ADDRESS);
    Wire.write(COMPASS_BEARING_REGISTER);
    Wire.endTransmission();

    Wire.requestFrom(COMPASS_ADDRESS, 1);

    if (Wire.available()) {
        int heading = Wire.read();
        return map(heading, 0, 255, 0, 359);
    }

    return -1;
}

int calculateHeadingError(int currentHeading, int targetHeading) {
    int error = targetHeading - currentHeading;

    if (error > 180) {
        error -= 360;
    }

    if (error < -180) {
        error += 360;
    }

    return error;
}

void turnToHeading(int targetHeading) {
    Serial.print("Target heading: ");
    Serial.println(targetHeading);

    while (true) {
        int currentHeading = readCompassHeading();

        if (currentHeading < 0) {
            Serial.println("Compass read error");
            stopMotors();
            delay(100);
            continue;
        }

        int headingError = calculateHeadingError(currentHeading, targetHeading);

        Serial.print("Current heading: ");
        Serial.print(currentHeading);
        Serial.print(" | Target: ");
        Serial.print(targetHeading);
        Serial.print(" | Error: ");
        Serial.println(headingError);

        if (abs(headingError) <= HEADING_TOLERANCE) {
            stopMotors();
            Serial.println("Target heading reached");
            break;
        }

        if (headingError > 0) {
            turnRight();
        } else {
            turnLeft();
        }

        delay(50);
    }
}

void turnLeft() {
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);

    analogWrite(LEFT_MOTOR_PWM, TURN_SPEED);
    analogWrite(RIGHT_MOTOR_PWM, TURN_SPEED);

    Serial.println("Turning left");
}

void turnRight() {
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    digitalWrite(RIGHT_MOTOR_DIR, LOW);

    analogWrite(LEFT_MOTOR_PWM, TURN_SPEED);
    analogWrite(RIGHT_MOTOR_PWM, TURN_SPEED);

    Serial.println("Turning right");
}

void stopMotors() {
    analogWrite(LEFT_MOTOR_PWM, 0);
    analogWrite(RIGHT_MOTOR_PWM, 0);

    Serial.println("Motors stopped");
}
