#ifndef LED_HPP
#define LED_HPP

class Led
{
  private:
  
  int pin; // Declare pin 
  unsigned long delay; // Delay in running functions
  unsigned long lastChangedTime; // Time when last change was made
  float brightDivinerStepper;
  float brightDiviner;
  int brightLimit; // Brightness limit for 
  
  public:
  
  Led();
  
  Led(int pin, unsigned long delay = 100);
  
  ~Led();

  void setPin(int value);
  
  int getPin();
  
  void setDelay(int delay);
  
  void setDelay(unsigned long delay);
  
  unsigned long getDelay();
  
  unsigned long getLastChange();

  void setLastChangedTime(unsigned long lastChangedTime);

  int getBrightLimit();

  void setBrightLimit(int newLimit);

  void set(float brightLevel, unsigned long currentMillis);

  float getBrightnessDiviner();

  void setBrightnessDiviner(float newDiviner);

  float getBrightnessDivinerStepper();

  void setBrightnessDivinerStepper(float newDivinerStepper);

};

#endif //LED_HPP