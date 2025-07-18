/* Example program for using TCS3200 color sensor
 * author: Panjkrc
 * date: 12/14/2019
 * url: https://github.com/Panjkrc/TCS3200_library
 */


#include <tcs3200.h>

int red, green, blue, white;

tcs3200 tcs(30, 31, 32, 33, 34); // (S0, S1, S2, S3, output pin)  //

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  //red = tcs.colorRead('r', 0);    //scaling can also be put to 0%, 20%, and 100% (default scaling is 20%)   ---    read more at: https://www.mouser.com/catalog/specsheets/TCS3200-E11.pdf
  //red = tcs.colorRead('r', 20);
  //red = tcs.colorRead('r', 100);

  red = tcs.colorRead('r');   //reads color value for red
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("    ");
  
  green = tcs.colorRead('g');   //reads color value for green
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("    ");

  blue = tcs.colorRead('b');    //reads color value for blue
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("    ");

  white = tcs.colorRead('c');    //reads color value for white(clear)
  Serial.print("W(clear)= ");
  Serial.print(white);
  Serial.print("    ");

  Serial.println();

  delay(200);

  if(red > 30 && green > 30 && blue > 30){
  // digitalWrite(13, HIGH);
  Serial.println("White");
  }
  else if(red > 5 && red < 15 && green > 8 && green < 15 && blue > 13 && blue < 25){
    // digitalWrite(13, HIGH);
    // delay(100);
    // digitalWrite(13, LOW);
    // delay(100);
    Serial.println("Blue");
  }
  else if(red > 15 && red < 45 && green > 8 && green < 20 && blue > 5 && blue < 17){
    // digitalWrite(13, HIGH);
    // delay(1000);
    // digitalWrite(13, LOW);
    // delay(1000);
    Serial.println("Orange");
  }
  else{
    // digitalWrite(13, LOW);
    Serial.println("Floating");
  }
}

void White(){
  if(red > 30 && green > 30 && blue > 30){
    digitalWrite(13, HIGH);
  }
}
