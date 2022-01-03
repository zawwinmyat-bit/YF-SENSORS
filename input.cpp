#include "pxt.h"

enum class TouchPin {
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2,
};

//% color="#45b787" weight=10 icon="\uf12e"
namespace YFSENSORS {

     /**
     * Do something when a pin is touched and released again (while also touching the GND pin).
     * @param name the pin that needs to be pressed, eg: TouchPin.P0
     * @param body the code to run when the pin is pressed
     */
    //% weight=83 blockGap=32
    //% blockId=YFSENSORS_device_pin_event block="on pin %name|pressed"
    void yf_onPinPressed(number x, TouchPin name, Action body) {
        auto pin = getPin((int)name);
        if (!pin) return;

        // Forces the PIN to switch to makey-makey style detection.
        pin->isTouched();
        registerWithDal((int)name, MICROBIT_BUTTON_EVT_CLICK, body);
    }

    /**
     * Do something when a pin is released.
     * @param name the pin that needs to be released, eg: TouchPin.P0
     * @param body the code to run when the pin is released
     */
    //% weight=6 blockGap=16
    //% blockId=YFSENSORS_device_pin_released block="on pin %NAME|released"
    //% advanced=true
    void yf_onPinReleased(number x, TouchPin name, Action body) {
        auto pin = getPin((int)name);
        if (!pin) return;

        // Forces the PIN to switch to makey-makey style detection.
        pin->isTouched();
        registerWithDal((int)name, MICROBIT_BUTTON_EVT_UP, body);
    }
}
