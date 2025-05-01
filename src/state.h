#include <optional>

#include "commandstream.h"
#include "carcontrol.h"

enum class State {
    IDLE,
    RECORDING,
    REPLICATING
};

State idle_loop(CommandStream &cmds, CarControl &ctrl);
State recording_loop(CommandStream &cmds, CarControl &ctrl);
State replicating_loop(CommandStream &cmds, CarControl &ctrl);
