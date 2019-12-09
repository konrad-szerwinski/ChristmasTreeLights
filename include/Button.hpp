#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
  private:
  
  int pin;
  bool isPushing = 0;
  
  public:
  
  Button(int pin); 
  ~Button();
  bool listen();
};

#endif // BUTTON_HPP