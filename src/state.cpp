#include "state.h"
#include "debug.h"

#include <list>

typedef struct {
    unsigned long time;
    Command command;
} TimedCommand;

static std::list<TimedCommand> command_list;

State idle_loop(CommandStream &cmds, CarControl &ctrl) {
    while(true) {
        while(cmds.has_commands()) {
            switch(cmds.next_command()) {
                case Command::GO_FORWARD:
                    ctrl.go_forward();
                    break;
                case Command::GO_BACKWARDS:
                    ctrl.go_backwards();
                    break;
                case Command::STOP:
                    ctrl.stop();
                    break;
                case Command::POINT_LEFT:
                    ctrl.point_left();
                    break;
                case Command::POINT_AHEAD:
                    ctrl.point_ahead();
                    break;
                case Command::POINT_RIGHT:
                    ctrl.point_right();
                    break;
                case Command::BEGIN_RECORDING:
                    return State::RECORDING;
                case Command::PLAY_RECORDING:
                    return State::REPLICATING;
            }
        }

        delay(1);
    }
}

State recording_loop(CommandStream &cmds, CarControl &ctrl) {
    command_list.clear();

    DEBUGLN("Started recording commands");

    auto begin = millis();

    while(true) {
        while(cmds.has_commands()) {
            auto cmd = cmds.next_command();
            switch(cmd) {
                case Command::GO_FORWARD:
                    ctrl.go_forward();
                    break;
                case Command::GO_BACKWARDS:
                    ctrl.go_backwards();
                    break;
                case Command::STOP:
                    ctrl.stop();
                    break;
                case Command::POINT_LEFT:
                    ctrl.point_left();
                    break;
                case Command::POINT_AHEAD:
                    ctrl.point_ahead();
                    break;
                case Command::POINT_RIGHT:
                    ctrl.point_right();
                    break;
                case Command::STOP_RECORDING:
                    DEBUGLN("Finished recording commands");
                    return State::IDLE;
            }

            command_list.emplace_back(TimedCommand { millis() - begin, cmd });
        }

        delay(1);
    }
}

State replicating_loop(CommandStream &cmds, CarControl &ctrl) {
    DEBUGLN("Starting to replicate saved path");

    auto begin = millis();

    for(TimedCommand tc : command_list) {
        auto next_command_time = begin + tc.time;

        while(millis() < next_command_time) {
            while(cmds.has_commands()) {
                auto command = cmds.next_command();
                if(command == Command::ABORT)
                    return State::IDLE;
            }
            delay(1);
        }

        switch(tc.command) {
            case Command::GO_FORWARD:
                ctrl.go_forward();
                break;
            case Command::GO_BACKWARDS:
                ctrl.go_backwards();
                break;
            case Command::STOP:
                ctrl.stop();
                break;
            case Command::POINT_LEFT:
                ctrl.point_left();
                break;
            case Command::POINT_AHEAD:
                ctrl.point_ahead();
                break;
            case Command::POINT_RIGHT:
                ctrl.point_right();
                break;
        }
    }

    DEBUGLN("Finished replicating");

    return State::IDLE;
}
