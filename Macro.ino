#include <Keyboard.h>
  
  unsigned long debounceDelay = 300;
  unsigned long lastpress = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();
}


void loop() {
  // put your main code here, to run repeatedly:
  
 
  int buttonState = digitalRead(8);

  if (buttonState == LOW)
  {
   
    if ((millis() - lastpress) > debounceDelay)
      {
        Serial.print(lastpress);
        Serial.print("Pressed\n");
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press("1");
        delay(100);
        Keyboard.releaseAll();
        lastpress = millis();
      }
  }
}
 
