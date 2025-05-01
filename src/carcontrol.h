#include <cstddef>

class CarControl {
    public:
        CarControl();

        bool setup();

        void go_forward();
        void go_backwards();
        void stop();
        void point_left();
        void point_ahead();
        void point_right();

        // TODO Funções para controlar os LEDs
};
