#include "config.h"
#include "debug.h"

#include "state.h"

static CommandStream commands;
static CarControl ctrl;

void setup() {
    SETUP_DEBUG();

    DEBUGLN("Cedos OS " VERSION);

    commands.setup();
    ctrl.setup();
}

void loop() {
    auto state = State::IDLE;

    while(true) {
        switch(state) {
            case State::IDLE:
                state = idle_loop(commands, ctrl);
                break;
            case State::RECORDING:
                state = recording_loop(commands, ctrl);
                break;
            case State::REPLICATING:
                state = replicating_loop(commands, ctrl);
                break;
        }
    }
}
