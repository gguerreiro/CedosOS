#include "carcontrol.h"

#include "debug.h"

CarControl::CarControl() :
    motor_pin_a(22), motor_pin_b(23), motor_2_pin_a(24), motor_2_pin_b(25)
{}

bool CarControl::setup() {
    pinMode(this->motor_pin_a, OUTPUT);
    pinMode(this->motor_pin_b, OUTPUT);
    pinMode(this->motor_2_pin_a, OUTPUT);
    pinMode(this->motor_2_pin_b, OUTPUT);

    return true;
}

void CarControl::go_forward() {
    DEBUGLN("Frente");

    digitalWrite(this->motor_pin_a, HIGH);
    digitalWrite(this->motor_pin_b, LOW);
    digitalWrite(this->motor_2_pin_a, LOW);
    digitalWrite(this->motor_2_pin_b, HIGH);
}

void CarControl::go_backwards() {
    DEBUGLN("Tras");

    digitalWrite(this->motor_pin_a, LOW);
    digitalWrite(this->motor_pin_b, HIGH);
    digitalWrite(this->motor_2_pin_a, HIGH);
    digitalWrite(this->motor_2_pin_b, LOW);
}

void CarControl::stop() {
    DEBUGLN("Parada");

    digitalWrite(this->motor_pin_a, LOW);
    digitalWrite(this->motor_pin_b, LOW);
    digitalWrite(this->motor_2_pin_a, LOW);
    digitalWrite(this->motor_2_pin_b, LOW);
    
}

void CarControl::point_left() {
    DEBUGLN("Esquerda");
    digitalWrite(this->motor_pin_a, HIGH);
    digitalWrite(this->motor_pin_b, LOW);
    digitalWrite(this->motor_2_pin_a, LOW);
    digitalWrite(this->motor_2_pin_b, LOW);
    
}

void CarControl::point_ahead() {
    DEBUGLN("Centro");
}

void CarControl::point_right() {
    DEBUGLN("Direita");
    digitalWrite(this->motor_pin_a, LOW);
    digitalWrite(this->motor_pin_b, LOW);
    digitalWrite(this->motor_2_pin_a, LOW);
    digitalWrite(this->motor_2_pin_b, HIGH);

}
