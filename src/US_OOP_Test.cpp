#include <Arduino.h>
#include <UofM_Ultrasonic.h>

UofM_Ultrasonic test_us( 30 , 31 );

void setup () {
    Serial.begin( 9600 );
}

void loop () {
    Serial.println( test_us.measure() );
    delay(1000);
}