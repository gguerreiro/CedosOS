#include "carcontrol.h"

#include "debug.h"

CarControl::CarControl() :
    left_motor_a_pin(22), left_motor_b_pin(23), left_motor_speed_pin(24),
    right_motor_a_pin(22), right_motor_b_pin(23), right_motor_speed_pin(24),
    movement(STOPPED), alignment(CENTER)
{}

bool CarControl::setup() {
    pinMode(this->left_motor_a_pin, OUTPUT);
    pinMode(this->left_motor_b_pin, OUTPUT);
    pinMode(this->left_motor_speed_pin, OUTPUT);
    pinMode(this->right_motor_a_pin, OUTPUT);
    pinMode(this->right_motor_b_pin, OUTPUT);
    pinMode(this->right_motor_speed_pin, OUTPUT);

    this->update_pins();

    return true;
}

void CarControl::go_forward() {
    DEBUGLN("Frente");

    this->movement = AHEAD;
    this->update_pins();
}

void CarControl::go_backwards() {
    DEBUGLN("Tras");

    this->movement = BEHIND;
    this->update_pins();
}

void CarControl::stop() {
    DEBUGLN("Parada");

    this->movement = STOPPED;
    this->update_pins();
}

void CarControl::point_left() {
    DEBUGLN("Esquerda");

    this->alignment = LEFT;
    this->update_pins();
}

void CarControl::point_ahead() {
    DEBUGLN("Centro");

    this->alignment = CENTER;
    this->update_pins();
}

void CarControl::point_right() {
    DEBUGLN("Direita");

    this->alignment = RIGHT;
    this->update_pins();
}

void CarControl::update_pins() {
    int l, r;

    switch(this->movement) {
        case STOPPED:
            switch(this->alignment) {
                case LEFT:
                    l = -255;
                    r = 255;
                    break;
                case CENTER:
                    l = 0;
                    r = 0;
                    break;
                case RIGHT:
                    l = 255;
                    r = -255;
                    break;
            }
            break;
        case AHEAD:
            l = 255;
            r = 255;
            switch(this->alignment) {
                case LEFT:
                    l = 128;
                    break;
                case RIGHT:
                    r = 128;
                    break;
            }
            break;
        case BEHIND:
            l = -255;
            r = -255;
            switch(this->alignment) {
                case LEFT:
                    l = -128;
                    break;
                case RIGHT:
                    r = -128;
                    break;
            }
    }
    digitalWrite(this->left_motor_a_pin, l > 0 ? HIGH : LOW);
    digitalWrite(this->left_motor_b_pin, l < 0 ? HIGH : LOW);
    analogWrite(this->left_motor_speed_pin, abs(l));
    digitalWrite(this->right_motor_a_pin, l < 0 ? HIGH : LOW);
    digitalWrite(this->right_motor_b_pin, l > 0 ? HIGH : LOW);
    analogWrite(this->right_motor_speed_pin, abs(r));
}
