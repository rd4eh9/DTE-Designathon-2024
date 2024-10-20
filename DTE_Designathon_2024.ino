#include <LiquidCrystal.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <ezButton.h>

const int BUTTON_A = 7;  // the number of the pushbutton pin
const int BUTTON_B = 6;
const int BUTTON_C = 9;
const int BUTTON_D = 8;

const int LED_BLUE =  13;
const int LED_GREEN =  0;
const int LED_YELLOW =  1;
const int LED_RED =  10;

ezButton buttonA(BUTTON_A);
ezButton buttonB(BUTTON_B); 
ezButton buttonC(BUTTON_C); 
ezButton buttonD(BUTTON_D);  // create ezButton object that attach to pin 7;

int ledState = LOW;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600); // lcd.init(); //initialize the lcd
  //lcd.backlight(); //To Power ON the backlight
  // put your setup code here, to run once:
  buttonA.setDebounceTime(250); // set debounce time to 75 milliseconds
  buttonB.setDebounceTime(75);
  buttonC.setDebounceTime(75);
  buttonD.setDebounceTime(75);
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  // set up the LCD's number of columns and rows:
 lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonA.loop();
  buttonB.loop();
  buttonC.loop();
  buttonD.loop();

  lcd.setCursor(0,0);
  lcd.println("A - Patient     ");
  lcd.setCursor(0,1);
  lcd.println("B - Student     ");
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);

  if(buttonA.isPressed())
  {
    Serial.println("button a 1");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.println("Family history  ");
    lcd.setCursor(0,1);
    lcd.println("of CHF?          ");
    delay(5000);

    if(buttonA.isPressed()){
  
      Serial.println("button a 2");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.clear();
      delay(500);

      lcd.setCursor(0,0);
      lcd.println("Have diabetes?  ");
      delay(5000);

      if(buttonA.isPressed()){
  
      Serial.println("button a 3");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.clear();
      delay(500);

      lcd.setCursor(0,0);
      lcd.println("Stage A: Pre-CHF");
      digitalWrite(LED_BLUE, HIGH);
      delay(5000);
      }
      else{
      Serial.println("button b 3");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.clear();
      delay(500);

      lcd.setCursor(0,0);
      lcd.println("Smoker?         ");
      delay(5000);

        if(buttonA.isPressed()){
  
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.clear();
        delay(500);

        lcd.setCursor(0,0);
        lcd.println("Stop smoking to ");
        lcd.setCursor(0,1);
        lcd.println("prevent CHF     ");
        digitalWrite(LED_GREEN, HIGH);
        delay(5000);
        }
        else{
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.clear();
        delay(500);

        lcd.setCursor(0,0);
        lcd.println("Healthy heart!  ");
        digitalWrite(LED_BLUE, HIGH);
        delay(5000);
      } 
      }
    }
  }
   if(buttonB.isPressed()){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.println("Stage treated w ");
    lcd.setCursor(0,1);
    lcd.println("inotropic drugs?");
    delay(5000);

    if(buttonA.isPressed() || buttonB.isPressed() || buttonC.isPressed() )
    {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.println("Incorrect!      ");
    lcd.setCursor(0,1);
    lcd.println("Answer: Stage D ");
    digitalWrite(LED_RED, HIGH);
    delay(5000);
    }
    else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.println("Correct!        ");
    lcd.setCursor(0,1);
    lcd.println("Answer: Stage D ");
    digitalWrite(LED_RED, HIGH);
    delay(10000);
    }

  }
}
