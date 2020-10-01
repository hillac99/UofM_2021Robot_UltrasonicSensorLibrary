// Make sure code is imported only once
#ifndef UOFM_ULTRASONIC
#define UOFM_ULTRASONIC

#include <Arduino.h>

class UofM_Ultrasonic {

    // Declare attributes
    private:
        byte trig_pin;
        byte echo_pin;
    
    // Declare Methods
    public:
        // Constructors
        UofM_Ultrasonic();
        UofM_Ultrasonic( byte _trig_pin, byte _echo_pin );
        
        // Getters
        byte get_trig_pin();
        byte get_echo_pin();

        // Setters
        void set_trig_pin( byte new_trig_pin );
        void set_echo_pin( byte new_echo_pin);

        // Behaviors
        float measure();
};

#endif