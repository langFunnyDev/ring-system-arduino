#define NMODE_BUTTON 2
#define SMODE_BUTTON 3
#define FIRE_ALARM 4
#define WARNING_ALL 5
#define MANUAL_BUTTON 6
#define RELAY_PIN 7
#define L_X 20
#define L_Y 4

byte one_column[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};

byte two_column[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

byte three_column[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};

byte four_column[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};

byte five_column[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>

LiquidCrystal_I2C lcd(0x27,20,4);
iarduino_RTC time(RTC_DS1307);

void setup() {
  Serial.begin(9600);             // Initialisation
  lcd.init();                 // Module 
  time.begin();               // Serial, LCD, RTC

  lcd.backlight();            // Backlight On
  
  lcd.setCursor(0, 0);
  lcd.write("Please select mode");
  lcd.setCursor(0, 1);
  lcd.write("Default mode: 40 min");
  lcd.setCursor(0, 2);
  lcd.write("Wait:");
  progres_bar(20, 5, 5, 3);
}

void loop() {
  

}

// _p_length - длина орисовываемого прогресс бара (в символах) 
// _p_time - время на его отрисовку (в секундах)
// _p_scX - начальная кордината по X
// _p_scY - начальная кордината по Y

void progres_bar(int _p_length, int _p_time, int _p_scX, int _p_scY){ 
  lcd_create_char();
  int ii = 0; // иттератор состояний отрисовки столбцов
  lcd.setCursor(_p_scX, _p_scY);
  for(int i = _p_length * 5;i != 0;i--){
    lcd.setCursor(_p_scX, _p_scY);
    lcd.printByte(ii);
    if(ii == 4){
      ii = 0;
      _p_scX++;
      if(_p_scX == 20){
        _p_scY++;
      }
      if(_p_scY == 4){
        Serial.print("Error: exit over allowable limit");
      }
    }
  }
}

void lcd_create_char(){
  lcd.createChar(0, one_column);
  lcd.createChar(1, two_column);
  lcd.createChar(2, three_column);
  lcd.createChar(3, four_column);
  lcd.createChar(4, five_column);
}
