void LCD_TICK() {
  if (selected_mode == 0 || selected_mode == 1) {
    LCD_MODE_PRINT(0);
    LCD_SHEDULE_STATE(1);
    LCD_TIME_PRINT(2);
    LCD_TO_RING(3);
  } else {
    LCD_MODE_PRINT(0);
    LCD_TIME_PRINT(1);
  }
  LCD_BACKLIGHT_CONTROL();
}

void LCD_BACKLIGHT_ON() {
  long realtime = TIME_CONVERTER(time.Hours, time.minutes, time.seconds);
  last_seconds = realtime + 30;
}

void LCD_BACKLIGHT_CONTROL() {
  long realtime = TIME_CONVERTER(time.Hours, time.minutes, time.seconds);
  if (last_seconds > realtime) {
    lcd.backlight();
  } else {
    lcd.noBacklight();
  }
}

void LCD_TO_RING(int y) {
  int temp1, temp2, temp3;
  if (selected_mode == 0) {
    temp1 = min40_shedule[state].hours - time.Hours ;
    temp2 = min40_shedule[state].minutes - time.minutes;
    temp3 = min40_shedule[state].seconds - time.seconds;
  }
  if (selected_mode == 1) {
    temp1 = min30_shedule[state].hours - time.Hours ;
    temp2 = min30_shedule[state].minutes - time.minutes;
    temp3 = min30_shedule[state].seconds - time.seconds;
  }
  if (temp3 < 0) {
    temp3 = temp3 + 60;
    temp2 = temp2 - 1;
  }
  if (temp2 < 0) {
    temp2 = temp2 + 60;
    temp1 = temp1 - 1;
  }
  if (temp1 < 0) {
    temp1 = temp1 + 24;
  }
  lcd.setCursor(0, y);
  lcd.print("To ring: ");
  LCD_TIME_OUT(temp1);
  lcd.print(":");
  LCD_TIME_OUT(temp2);
  lcd.print(":");
  LCD_TIME_OUT(temp3);
}

void LCD_CLEAR() {
  lcd.setCursor(16, 0);
  lcd.print("    ");
}

void LCD_MODE_PRINT(int y) {
  lcd.setCursor(0, y);
  lcd.print("Mode: ");
  if (selected_mode == viewed_mode) {
    lcd.print(modes[selected_mode].mode_name);
  } else {
    lcd.setCursor(6, y);
    lcd.print(modes[viewed_mode].mode_name);
    if (viewed_mode == 2) {
      lcd.print("#");
    } else {
      lcd.print(" #");
    }

  }
}

void LCD_SHEDULE_STATE(int y) {
  lcd.setCursor(0, y);
  lcd.print("In time: ");
  if (min40_shedule[state].is_break) {
    lcd.print("Break");
  } else {
    lcd.print("Lesson");
  }
}

void LCD_TIME_PRINT(int y) {
  lcd.setCursor(0, y);
  lcd.print("Time is: ");
  LCD_TIME_OUT(time.Hours);
  lcd.print(":");
  LCD_TIME_OUT(time.minutes);
  lcd.print(":");
  LCD_TIME_OUT(time.seconds);
}

void LCD_TIME_OUT(int time_val) {
  switch (time_val) {
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
