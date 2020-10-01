#include <Arduino.h>
#include "UofM_Ultrasonic.h"

// Constructors
UofM_Ultrasonic::UofM_Ultrasonic() {
    UofM_Ultrasonic( 30, 31 );
}

UofM_Ultrasonic::UofM_Ultrasonic( byte _trig_pin, byte _echo_pin ) {
    trig_pin = _trig_pin;
    echo_pin = _echo_pin;

    pinMode( trig_pin , OUTPUT );
    pinMode( echo_pin , INPUT );
}

// Getters
byte UofM_Ultrasonic::get_trig_pin() {
    return trig_pin;
}

byte UofM_Ultrasonic::get_echo_pin() {
    return echo_pin;
}

// Setters
void UofM_Ultrasonic::set_trig_pin( byte new_trig_pin ) {
    trig_pin = new_trig_pin;
}

void UofM_Ultrasonic::set_echo_pin( byte new_echo_pin ) {
    echo_pin = new_echo_pin;
}

// Behaviors
float UofM_Ultrasonic::measure() {
    // Declare method variables
    long duration;
    float inches;

    // Pulse trig pin for 10 microseconds
    digitalWrite( trig_pin , LOW );
    delayMicroseconds( 5 );
    digitalWrite( trig_pin , HIGH );
    delayMicroseconds( 10 );
    digitalWrite( trig_pin , LOW );

    // Measure duration of echo pulse
    duration = pulseIn( echo_pin , HIGH );

    // Calculate distance from time 
    inches = ( duration / 2.0 ) / 74.0;

    // Return result
    return inches;
}