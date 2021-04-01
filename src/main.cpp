#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Button.h>

#define MSG_SIZE 5

SoftwareSerial radio(11, 10); // RX, TX

Button up_button(2);     // Boton Amarillo - A
Button down_button(4);   // Boton Amarillo - C
Button left_button(5);   // Boton Azul     - D
Button right_button(3);  // Boton Azul     - B
Button start_button(6);  // Boton F
Button option_button(7); // Boton E
Button analog_button(8); // Buton Analog

int x_axis = A0;
int y_axis = A1;
int xposg = 0;
int yposg = 0;

char newMsg[MSG_SIZE];

void sendRadio(char button, int xpos, int ypos)
{

  char xDir = 'N';
  char yDir = 'N';

  if (xpos <= 400)
    xDir = 'L';
  if (xpos >= 700)
    xDir = 'R';
  if (ypos <= 400)
    yDir = 'D';
  if (ypos >= 700)
    yDir = 'U';

  newMsg[0] = '<';
  newMsg[1] = xDir;
  newMsg[2] = yDir;
  newMsg[3] = button;
  newMsg[4] = '>';

  //Serial.println(newMsg);
  radio.print(newMsg);
}

void setup()
{

  radio.begin(9600);

  up_button.begin();
  down_button.begin();
  left_button.begin();
  right_button.begin();
  start_button.begin();
  option_button.begin();
  analog_button.begin();

  for (int j = 0; j < MSG_SIZE; j++)
    newMsg[j] = 'N';
}

void loop()
{
  char button = 'N';

  if (up_button.pressed())
    button = 'U';

  if (down_button.pressed())
    button = 'D';

  if (left_button.pressed())
    button = 'L';

  if (right_button.pressed())
    button = 'R';

  if (start_button.pressed())
    button = 'S';

  if (option_button.pressed())
    button = 'O';

  if (analog_button.pressed())
    button = 'A';

  sendRadio(button, analogRead(x_axis), analogRead(y_axis));

  //yposg = analogRead(y_axis);
  //xposg = analogRead(x_axis);

  //Serial.print(xposg);
  //Serial.print(", ");
  //Serial.print(yposg);
  //Serial.println();

  delay(200);
}