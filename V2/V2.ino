#define FORWARD_SWITCH 2
#define BACKWARD_SWITCH 3
#define IDLE_MODE 4
#define REBOOT 5
#define MANUAL_BUTTON 6
#define RELAY_PIN 7
#define L_X 20
#define L_Y 4

byte one_column[8] = {  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,};
byte two_column[8] = {  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,};
byte three_column[8] = {  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,  B11100,};
byte four_column[8] = {  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,  B11110,};
byte five_column[8] = {  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,};
bool configurationFlag = false;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
iarduino_RTC time(RTC_DS3231);

void setup() {
  Serial.begin(9600);                             // Initialisation
  lcd.init();                                     // Module
  time.begin();                                   // Serial, LCD, RTC
  Serial.setTimeout(100);                         // установка таймаута для readString (мс) (по умолчанию слишком длинный)

  pinMode(FORWARD_SWITCH, INPUT_PULLUP);          // Init
  pinMode(BACKWARD_SWITCH, INPUT_PULLUP);         // All
  pinMode(IDLE_MODE, INPUT_PULLUP);               // Button
  pinMode(REBOOT, INPUT_PULLUP);                  // Pins
  pinMode(MANUAL_BUTTON, INPUT_PULLUP);           // Work
  pinMode(RELAY_PIN, OUTPUT);                     // Mode

  if (digitalRead(FORWARD_SWITCH) == 0 && digitalRead(BACKWARD_SWITCH) == 0) {
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Configuration mode :");
    lcd.setCursor(5, 1);
    lcd.print("Enable");
    delay(250);
    configurationFlag = true;
  } else {
    lcd.backlight();                                // Backlight On
    lcd_startup();                                  // Show startup message
    lcd_progres_bar(20, 5, 5, 3);                   // Draw progress bar
  }
}

void loop() {
  if (configurationFlag == true) {
    serialTick();
  } else {
    time.gettime();
  }
}
