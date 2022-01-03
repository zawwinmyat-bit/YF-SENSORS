// tests go here; this will not be compiled when this package is used as a library
basic.forever(function() {
    YFSENSORS.motorRun(YFSENSORS.Motors.MAll, YFSENSORS.Dir.CW, 120)
    basic.pause(500)
    YFSENSORS.motorStop(YFSENSORS.Motors.MAll)
    basic.pause(500)
    YFSENSORS.motorRun(YFSENSORS.Motors.MAll, YFSENSORS.Dir.CCW, 120)
    basic.pause(500)
    YFSENSORS.motorStop(YFSENSORS.Motors.MAll)
    basic.pause(500)
})