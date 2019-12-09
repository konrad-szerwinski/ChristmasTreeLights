#include <Arduino.h>

#include "../include/Button.hpp"
#include "../include/Led.hpp"
#include "../constants/Mode.cpp"

// Pins defined for AtTiny85 
#define Led1Pin 0 
#define Led2Pin 1
#define ModeChangeButtonPin 3

Mode mode;
Button *btnModeChanger;
Led *led1;
Led *led2;

unsigned long currentMillis;
float led1BrightnessDivider;
float led2BrightnessDivider;

void play();
void changeMode();
void fade(Led *led);

void setup() {
  mode = Off;
  
  btnModeChanger = new Button(ModeChangeButtonPin);
  led1 = new Led(Led1Pin);
  led2 = new Led(Led2Pin);
  
  led1->setBrightLimit(255);
  led2->setBrightLimit(255);
  
  currentMillis = millis();
}

void loop() {
  if (btnModeChanger->listen())
  {
    changeMode();
  }
  play();
}

void play() {

  currentMillis = millis();
  
  switch (mode)
  {
  case Off:
    led1->set(0, currentMillis);
    led2->set(0, currentMillis);
    break;

  case OnOnly:
    led1->set(1, currentMillis);
    led2->set(1, currentMillis);
    break;

  case Fade:
  case FadeAdvanced:
  case FadeNegative:
    fade(led1);
    fade(led2);
    break;
  }
}

void changeMode()
{
  if (mode == Off)
  {
    mode = OnOnly;
  }
  else if (mode == OnOnly)
  {
    mode = Fade;
    led1->setBrightnessDivinerStepper(0.02);
    led2->setBrightnessDivinerStepper(0.02);
    led1->setBrightnessDiviner(1);
    led2->setBrightnessDiviner(1);
  }
  else if (mode == Fade)
  {
    mode = FadeAdvanced;
    led1->setBrightnessDivinerStepper(0.016);
    led2->setBrightnessDivinerStepper(0.021);
    led1->setBrightnessDiviner(1);
    led2->setBrightnessDiviner(1);
  }
  else if (mode == FadeAdvanced)
  {
    mode = FadeNegative;
    led1->setBrightnessDivinerStepper(0.02);
    led2->setBrightnessDivinerStepper(0.02);
    led1->setBrightnessDiviner(1);
    led2->setBrightnessDiviner(0);
  }

  else 
  {
    mode = Off;
  }
}

void fade(Led *led){
  if ((unsigned long) currentMillis - led->getLastChange() > led->getDelay())
  {
    if (led->getBrightnessDiviner() + led->getBrightnessDivinerStepper() >= 1 )
    {
      led->setBrightnessDivinerStepper(led->getBrightnessDivinerStepper() * (-1));
      led->setBrightnessDiviner(1);
    }
    else if (led->getBrightnessDiviner() + led->getBrightnessDivinerStepper() <= 0)
    {
      led->setBrightnessDivinerStepper(led->getBrightnessDivinerStepper() * (-1));
      led->setBrightnessDiviner(0);
    }
    else {
      led->setBrightnessDiviner(led->getBrightnessDiviner() + led->getBrightnessDivinerStepper());
    }
      led->set(led->getBrightnessDiviner(), currentMillis);
  }
}
