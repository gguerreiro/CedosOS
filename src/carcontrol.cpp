#include "carcontrol.h"

#include "debug.h"

CarControl::CarControl() {}

bool CarControl::setup() {
    return true;
}

void CarControl::go_forward() {
    DEBUGLN("Frente");

    // TODO Ir para frente
}

void CarControl::go_backwards() {
    DEBUGLN("Tras");

    // TODO Ir para trás
}

void CarControl::stop() {
    DEBUGLN("Parada");

    // TODO Parar
}

void CarControl::point_left() {
    DEBUGLN("Esquerda");

    // TODO Apontar para a esquerda
}

void CarControl::point_ahead() {
    DEBUGLN("Centro");

    // TODO Apontar para frente
}

void CarControl::point_right() {
    DEBUGLN("Direita");

    // TODO Apontar para a direita
}
