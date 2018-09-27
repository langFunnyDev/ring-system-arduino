#include <iarduino_RTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
iarduino_RTC time(RTC_DS3231);
LiquidCrystal_I2C lcd(0x27,20,4);

int min40Mode[20][3] = {
  {8, 0, 0},  {8, 40, 0},  {8, 50, 0},  {9, 30, 0},  {9, 45, 0},  {10, 25, 0},  {10, 40, 0},  {11, 20, 0},  {11, 35, 0},  {12, 15, 0},  {12, 25, 0},  {13, 5, 0},  {13, 15, 0},  {13, 55, 0},  {14, 5, 0},  {14, 45, 0},  {14, 55, 0},  {15, 35, 0},  {15, 45, 0},  {16, 25, 0}
};
int min30Mode[12][3] = {
  {8, 0, 0}, {8, 30, 0}, {8, 40, 0}, {9, 10, 0}, {9, 20, 0}, {9, 50, 0}, {10, 0, 0}, {10, 30, 0}, {10, 40, 0}, {11, 10, 0}, {11, 20, 0}, {11, 50, 0}
};
byte RELAY_PIN = 6;
byte BUTTON_40MIN = 2;
byte BUTTON_30MIN = 3;
byte BUTTON_ALARM = 4;
byte BUTTON_WARNING = 5;
byte MANUAL_BUTTON = 7;
byte state = 0;
byte state1 = 0;
byte stateWhithMode = 0;
byte default_delay = 4;
long last_seconds;

void setup(){
  
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Load...");
    delay(300);    
    pinMode(BUTTON_40MIN, INPUT_PULLUP);
    pinMode(BUTTON_30MIN, INPUT_PULLUP);
    pinMode(BUTTON_ALARM, INPUT_PULLUP);
    pinMode(BUTTON_WARNING, INPUT_PULLUP);
    pinMode(MANUAL_BUTTON, INPUT_PULLUP);    
    Serial.begin(9600);    
    time.begin();    
    lcd.clear();
    pinMode(RELAY_PIN, OUTPUT);
    TIME_MODE_WHITH_40_MIN();
    
}        
                                                  
void loop(){                                               
    if(state == 20){
      state = 0;
    }
    if(state1 == 12){
      state1 = 0;
    }
    time.gettime();
    BUTTON_MODE_SWITCH();
    LCD_MODE_OUT();
    LCD_TIME_PRINT();       
    LCD_LESSON_TIME_COUNTER();
    MANUAL_MODE();
    if(time.weekday != 0){
      switch(stateWhithMode){ // if weekday sunday a program ignore all instruction`s    
        
        case 0: // 40 minutes lesson          
            if(time.Hours == min40Mode[state][0] && time.minutes == min40Mode[state][1] && time.seconds == min40Mode[state][2]){
              RELAY_ON_OFF();
              state++;
            }          
        break;

        case 1: // 30 minutes lesson
            if(time.Hours == min30Mode[state1][0] && time.minutes == min30Mode[state1][1] && time.seconds == min30Mode[state1][2]){
              RELAY_ON_OFF();
              state1++;
            }
        break;
        
        case 2: // Warning All Mode 
          RELAY_ON_OFF();
          RELAY_ON_OFF();
          RELAY_ON_OFF();
          stateWhithMode = 0;
        break;

        case 3: // Alarm (FIRE) Mode 
          digitalWrite(RELAY_PIN, HIGH);
        break;

      }
    }
    last_seconds = time.seconds;
}

void RELAY_ON_OFF(){
  digitalWrite(RELAY_PIN, HIGH);
  delay(default_delay * 1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(default_delay * 1000);
}
void LCD_MODE_OUT(){
  lcd.setCursor(0,0);
    lcd.print("Mode: ");
    switch(stateWhithMode){
      case 0:
        lcd.print("40 MIN");
        lcd.print("     ");
      break;
      case 1:  
        lcd.print("30 MIN");
        lcd.print("     ");
      break;
      case 2:
        lcd.print("All Warning");
      break;
      case 3:
        lcd.print("FIRE");
        lcd.print("       ");
      break;
    }
}
void LCD_LESSON_TIME_COUNTER(){
  lcd.setCursor(0, 2);
  int temp1;
  int temp2;
  int temp3;
  if(stateWhithMode == 0){
    temp1 = min40Mode[state][0] - time.Hours ;
    temp2 = min40Mode[state][1] - time.minutes;
    temp3 = min40Mode[state][2] - time.seconds;
  }
  if(stateWhithMode == 1){
    temp1 = min30Mode[state][0] - time.Hours ;
    temp2 = min30Mode[state][1] - time.minutes;
    temp3 = min30Mode[state][2] - time.seconds;
  }
  if(temp3 < 0){
    temp3 = temp3 + 60;
    temp2 = temp2 - 1;
  }
  if(temp2 < 0){
    temp2 = temp2 + 60;
    temp1 = temp1 - 1;
  }
  if(temp1 < 0){
    temp1 = temp1 + 24;
  }
  if(stateWhithMode == 0 || stateWhithMode == 1){
    lcd.print("To next lesson:");
    lcd.setCursor(0, 3);        
    LCD_TIME_OUT(temp1);
    lcd.print(":");
    LCD_TIME_OUT(temp2);
    lcd.print(":");
    LCD_TIME_OUT(temp3);
  } else {
    lcd.print("                    ");
    lcd.setCursor(0, 3);
    lcd.print("                    ");
  }
}
void LCD_TIME_PRINT(){
    lcd.setCursor(0, 1);    
    LCD_TIME_OUT(time.Hours);
    lcd.print(":");
    LCD_TIME_OUT(time.minutes);
    lcd.print(":");
    LCD_TIME_OUT(time.seconds);
}
void BUTTON_MODE_SWITCH(){
  if(digitalRead(BUTTON_40MIN) != 1){
    stateWhithMode = 0;
    TIME_MODE_WHITH_40_MIN();
  }
  if(digitalRead(BUTTON_30MIN) != 1){
    stateWhithMode = 1;
    TIME_MODE_WHITH_30_MIN();
  }
  if(digitalRead(BUTTON_ALARM) != 1){
    stateWhithMode = 3;
  }
  if(digitalRead(BUTTON_WARNING) != 1){
    stateWhithMode = 2;
  }
}
void MANUAL_MODE(){
  if(digitalRead(MANUAL_BUTTON) != 1){
    RELAY_ON_OFF();
  }
}

void TIME_MODE_WHITH_40_MIN(){
  time.begin();
  Serial.print(time.Hours);
  Serial.print(":");
  Serial.print(time.minutes);
  Serial.print(":");
  Serial.print(time.seconds);
  long realtime = TIME_CONVERTER(time.Hours, time.minutes, time.seconds);
  long temptime;
  Serial.print(realtime);
  Serial.println(" - realtime");
  for(byte i = 19;i >= 0; i--){
    temptime = TIME_CONVERTER(min40Mode[i][0], min40Mode[i][1], min40Mode[i][2]);
    Serial.print(realtime);
    Serial.println(" - realtime");
    Serial.print(temptime);
    Serial.println(" - temptime");
    if(temptime > realtime){
      Serial.println("TRUE");
    } else {
     Serial.println("FALSE");
     state = i + 1; 
     break;
    }    
  }
}
void TIME_MODE_WHITH_30_MIN(){
  time.begin();
  Serial.print(time.Hours);
  Serial.print(":");
  Serial.print(time.minutes);
  Serial.print(":");
  Serial.print(time.seconds);
  long realtime = TIME_CONVERTER(time.Hours, time.minutes, time.seconds);
  long temptime;
  Serial.print(realtime);
  Serial.println(" - realtime");
  for(byte i = 11;i >= 0; i--){
    temptime = TIME_CONVERTER(min30Mode[i][0], min30Mode[i][1], min30Mode[i][2]);
    Serial.print(realtime);
    Serial.println(" - realtime");
    Serial.print(temptime);
    Serial.println(" - temptime");
    if(temptime > realtime){
      Serial.println("TRUE");
    } else {
     Serial.println("FALSE");
     state1 = i + 1; 
     break;
    }    
  }
}
long TIME_CONVERTER(int val1, int val2, int val3){
  long result;
  long temp_val1 = (long)val1;
  long temp_val2 = (long)val2;
  long temp_val3 = (long)val3;  
  result = temp_val1 * 3600;
  result = result + temp_val2 * 60;
  result = result + temp_val3;
  return result;
}
void LCD_TIME_OUT(int time_val){
  switch(time_val){
    case 0:
      lcd.print("00");
    break;
    case 1:
      lcd.print("01");
    break;
    case 2:
      lcd.print("02");
    break;
    case 3:
      lcd.print("03");
    break;
    case 4:
      lcd.print("04");
    break;
    case 5:
      lcd.print("05");
    break;
    case 6:
      lcd.print("06");
    break;
    case 7:
      lcd.print("07");
    break;
    case 8:
      lcd.print("08");
    break;
    case 9:
      lcd.print("09");
    break;
    default:
      lcd.print(time_val);
  }
}

