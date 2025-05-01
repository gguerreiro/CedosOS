#include <cstddef>

#include <ESP32Servo.h>

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
        uint8_t motor_pin_a, motor_pin_b;
        Servo front_wheels_servo;
};
