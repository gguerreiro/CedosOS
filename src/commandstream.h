#pragma once

#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

enum class Command {
    NONE = 0,

    GO_FORWARD,
    GO_BACKWARDS,
    STOP,

    POINT_LEFT,
    POINT_RIGHT,
    POINT_AHEAD,

    ABORT,
    BEGIN_RECORDING,
    STOP_RECORDING,
    PLAY_RECORDING,
};

class CommandStream final {
    public:
        CommandStream();

        bool setup();

        Command next_command();
        bool has_commands();
    
    private:
        BluetoothSerial bt_serial;
};
