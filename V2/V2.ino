#define FORWARD_SWITCH 2
#define BACKWARD_SWITCH 3
#define OK 4
#define CANCEL 5
#define MANUAL_BUTTON 6
#define RELAY_PIN 7
#define DELAY 4

#include <iarduino_RTC.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <SPI.h>

iarduino_RTC time(RTC_DS3231);
LiquidCrystal_I2C lcd(0x27, 20, 4);

int state = 0;

byte selected_mode = 0;
int8_t viewed_mode = 0;

byte default_delay = 5;
long last_seconds = 0;

void setup() {
  Serial.begin(9600);
  time.begin();
  lcd.init();

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Load...");
  lcd.setCursor(0, 1);
  lcd.print("Startup whith 40min mode");
  DETECT_LESSON_COUNT();
  LCD_BACKLIGHT_ON();
  delay(300);

  pinMode(FORWARD_SWITCH, INPUT_PULLUP);
  pinMode(BACKWARD_SWITCH, INPUT_PULLUP);
  pinMode(OK, INPUT_PULLUP);
  pinMode(CANCEL, INPUT_PULLUP);
  pinMode(MANUAL_BUTTON, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  lcd.clear();
}

void loop() {
  time.gettime();
  TICK();
  BUTTONS_TICK();
  LCD_TICK();
  if (TIME_CONVERTER(time.Hours, time.minutes, time.seconds) == 0) {
    CHECK();
  }
  if (state >= 24) {
    state = 0;
  }
}
