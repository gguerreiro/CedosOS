#include <cstddef>

#include <ESP32Servo.h>

enum CarLongitudinalMovement { AHEAD, STOPPED, BEHIND };
enum CarHorizontalAlignment { LEFT, CENTER, RIGHT };

class CarControl {
    public:
        CarControl();

        bool setup();

        /**
         * Instructs the car to go ahead. It will keep going forward until `go_backwards`or `stop` is called.
         */
        void go_forward();

        /**
         * Instructs the car to go backwards. It will keep going backwards until `go_forward` or `stop` is called.
         */
        void go_backwards();

        /**
         * Turn off tyre traction.
         */
        void stop();

        /**
         * Make the front wheels turn left
         */
        void point_left();

        /**
         * Make the front wheels straight
         */
        void point_ahead();

        /**
         * Make the front wheels turn right
         */
        void point_right();

        // TODO Funções para controlar os LEDs
    
    private:
        uint8_t left_motor_a_pin, left_motor_b_pin, left_motor_speed_pin;
        uint8_t right_motor_a_pin, right_motor_b_pin, right_motor_speed_pin;
        CarLongitudinalMovement movement;
        CarHorizontalAlignment alignment;

        void update_pins();
};
