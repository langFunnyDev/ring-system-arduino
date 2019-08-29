void BUTTONS_TICK(){
  if(digitalRead(FORWARD_SWITCH) != 1){
    viewed_mode++;
    if(viewed_mode == 5){
      viewed_mode = 0;
    }
    LCD_CLEAR();
    LCD_BACKLIGHT_ON();
    delay(200);
  }
  if(digitalRead(BACKWARD_SWITCH) != 1){
    viewed_mode--;
    if(viewed_mode == -1){
      viewed_mode = 4;
    }
    LCD_CLEAR();
    LCD_BACKLIGHT_ON();
    delay(200);
  }
  if(digitalRead(OK) != 1){
    selected_mode = viewed_mode;
    if(selected_mode == 0 || selected_mode == 1){
      DETECT_LESSON_COUNT();
    } else {
      lcd.clear();
    }
    LCD_CLEAR();
    LCD_BACKLIGHT_ON();
    delay(200);
  }
  if(digitalRead(CANCEL) != 1){
    viewed_mode = selected_mode;
    LCD_CLEAR();
    LCD_BACKLIGHT_ON();
    delay(200);
  }
  if(digitalRead(MANUAL_BUTTON) != 1){
    digitalWrite(RELAY_PIN, HIGH);
    LCD_BACKLIGHT_ON();
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }
}
