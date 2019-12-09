#include <Arduino.h>
#include "../include/Led.hpp"

Led::Led(int pin, unsigned long delay)
{
  this->pin = pin;
  this->delay = delay;
  this->brightLimit = 255;
  this->brightDiviner = 1;
};

Led::Led()
{
  this->pin = 11;
  this->delay = 250;
  this-> brightLimit = 255;
  this->brightDiviner = 1;
}

Led::~Led()
{
  delete this;
}

//PIN
void Led::setPin(int value)
{
  this->pin = value;
};

int Led::getPin()
{
  return pin;
};

//DELAY
void Led::setDelay(int delay)
{
  this->delay = (unsigned long)delay;
};

void Led::setDelay(unsigned long delay)
{
  this->delay = delay;
};

unsigned long Led::getDelay()
{
  return delay;
};

unsigned long Led::getLastChange()
{
  return lastChangedTime;
};

void Led::setLastChangedTime(unsigned long lastChangedTime)
{
  this->lastChangedTime = lastChangedTime;
}

int Led::getBrightLimit()
{
  return this->brightLimit;
}

void Led::setBrightLimit(int newLimit)
{
  this->brightLimit = newLimit;
}

void Led::set(float brightLevel, unsigned long currentMillis)
{
  if(brightLevel >= 1)
  {
    analogWrite(pin, brightLimit);
  }
  else if (brightLimit <= 0)
  {
    analogWrite(pin, 0);
  }
  else 
  {
    analogWrite(pin,brightLimit * (brightLevel));
  }
  lastChangedTime = currentMillis;
}

float Led::getBrightnessDiviner()
{
  return this->brightDiviner;
}

void Led::setBrightnessDiviner(float newDiviner)
{
  this->brightDiviner = newDiviner;
}

float Led::getBrightnessDivinerStepper()
{
  return this->brightDivinerStepper;
}

void Led::setBrightnessDivinerStepper(float newDivinerStepper)
{
  this->brightDivinerStepper = newDivinerStepper;
}