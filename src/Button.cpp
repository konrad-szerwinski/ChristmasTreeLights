#include <Arduino.h>
#include "../include/Button.hpp"

Button::Button(int pin){
    this->pin = pin;

    pinMode(this->pin, INPUT_PULLUP);
};

Button::~Button()
{
    delete this;
}

bool Button::listen()
{
    if(isPushing)
    {
        if(digitalRead(pin) == LOW)
        {
            isPushing = false;
        }
        else 
        {
            return false;
        }
    }
    else{
        if(digitalRead(pin) == HIGH)
        {
            isPushing = true;
            return true;
        }
    }
    return false;
}