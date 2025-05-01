#include "carcontrol.h"

#include "debug.h"

CarControl::CarControl() :
    motor_pin_a(26), motor_pin_b(27), front_wheels_servo()
{}

bool CarControl::setup() {
    pinMode(this->motor_pin_a, OUTPUT);
    pinMode(this->motor_pin_b, OUTPUT);

    this->front_wheels_servo.attach(13);
    return true;
}

void CarControl::go_forward() {
    DEBUGLN("Frente");

    digitalWrite(this->motor_pin_a, LOW);
    digitalWrite(this->motor_pin_b, HIGH);
}

void CarControl::go_backwards() {
    DEBUGLN("Tras");

    digitalWrite(this->motor_pin_a, HIGH);
    digitalWrite(this->motor_pin_b, LOW);
}

void CarControl::stop() {
    DEBUGLN("Parada");

    digitalWrite(this->motor_pin_a, LOW);
    digitalWrite(this->motor_pin_b, LOW);
}

void CarControl::point_left() {
    DEBUGLN("Esquerda");

    this->front_wheels_servo.write(0);
}

void CarControl::point_ahead() {
    DEBUGLN("Centro");

    this->front_wheels_servo.write(90);
}

void CarControl::point_right() {
    DEBUGLN("Direita");

    this->front_wheels_servo.write(180);
}
