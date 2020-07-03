
#include <Keyboard.h>
#include <Esplora.h>
#include <Mouse.h>

void setup() {
  Serial.begin(9600);       // initialize serial communication with your computer
  Mouse.begin();
}

void loop() {   
  int W = Esplora.readButton(SWITCH_UP);
  int S = Esplora.readButton(SWITCH_DOWN);
  int A = Esplora.readButton(SWITCH_LEFT);
  int D = Esplora.readButton(SWITCH_RIGHT);               
  Esplora.writeRGB(0, 255, 0);  // make the LED green
  delay(0);
  //LOW when pressed, HIGH when not pressed.                   
  if(W == LOW){
    Keyboard.press('w');
    Keyboard.releaseAll();
    }
  if(A == LOW){
    Keyboard.press('a');
    Keyboard.releaseAll();
    }
  if(S == LOW){
    Keyboard.press('s');
    Keyboard.releaseAll();
    }
  if(D == LOW){
    Keyboard.press('d');
    Keyboard.releaseAll();
    }    
  int xValue = Esplora.readJoystickX();        // read the joystick's X position
  int yValue = Esplora.readJoystickY();        // read the joystick's Y position
  int button = Esplora.readJoystickSwitch();   // read the joystick pushbutton
  Serial.print("Joystick X: ");                // print a label for the X value
  Serial.print(xValue);                        // print the X value
  Serial.print("\tY: ");                       // print a tab character and a label for the Y value
  Serial.print(yValue);                        // print the Y value
  Serial.print("\tButton: ");                  // print a tab character and a label for the button
  Serial.print(button);                        // print the button value

  int mouseX = map(xValue, -512, 512, 10, -10);  // map the X value to a range of movement for the mouse X
  int mouseY = map(yValue, -512, 512, -10, 10);  // map the Y value to a range of movement for the mouse Y
  Mouse.move(mouseX, mouseY, 0);                 // move the mouse

  if (button == 0) {                           // if the joystick button is pressed
    Mouse.press();                             // send a mouse click
  } else {
    Mouse.release();                           // if it's not pressed, release the mouse button
  }

  delay(10);            
 
 
}
