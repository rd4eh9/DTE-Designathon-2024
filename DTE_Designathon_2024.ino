#include <LiquidCrystal.h>
#include <ezButton.h>

// declare button pins
const int BUTTON_A = 7;  
const int BUTTON_B = 6;
const int BUTTON_C = 9;
const int BUTTON_D = 8;

// declare LED pins
const int LED_BLUE =  13;
const int LED_GREEN =  0;
const int LED_YELLOW =  1;
const int LED_RED =  10;

// create button debouncing objects
ezButton buttonA(BUTTON_A);
ezButton buttonB(BUTTON_B); 
ezButton buttonC(BUTTON_C); 
ezButton buttonD(BUTTON_D);  

int ledState = LOW;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  // set debounce time to 250 milliseconds
  buttonA.setDebounceTime(250); 
  buttonB.setDebounceTime(250);
  buttonC.setDebounceTime(250);
  buttonD.setDebounceTime(250);

  // set buttons to output
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  
  //reset LEDs
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  // set up the LCD's number of columns and rows:
 lcd.begin(16, 2);
}

void loop() {
  // button debouncing
  buttonA.loop();
  buttonB.loop();
  buttonC.loop();
  buttonD.loop();

  // print questions to LCD screen
  lcd.setCursor(0,0);
  lcd.println("A - Patient     ");
  lcd.setCursor(0,1);
  lcd.println("B - Student     ");

  // reset LEDs
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);

  // Patient Case question flow
  if(buttonA.isPressed()){

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

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.clear();
      delay(500);

      lcd.setCursor(0,0);
      lcd.println("Have diabetes?  ");
      delay(5000);

      if(buttonA.isPressed()){
        
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
  // Medical Student Case question flow
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

    if(buttonA.isPressed() || buttonB.isPressed() || buttonC.isPressed()) {

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.clear();
    delay(500);
    
    lcd.setCursor(0,0);
    lcd.println("Incorrect!      ");
    lcd.setCursor(0,1);
    lcd.println("Answer: Stage D ");
    digitalWrite(LED_RED, HIGH);
    delay(10000);
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
