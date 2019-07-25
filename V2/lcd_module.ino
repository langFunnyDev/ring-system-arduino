// _p_length - длина орисовываемого прогресс бара (в символах)
// _p_time - время на его отрисовку (в секундах)
// _p_scX - начальная кордината по X
// _p_scY - начальная кордината по Y

void lcd_progres_bar(int _p_length, int _p_time, int _p_scX, int _p_scY) {
  lcd_create_char();
  int cycle_time = _p_length * 5 / _p_time * 1000;
  int state = 0;
  int switching_block_state = 0;
  int state_end = _p_length * 5;
  while (state < state_end) {
    lcd.setCursor(_p_scX, _p_scY);
    lcd.printByte(switching_block_state);
    state++;
    switching_block_state++;
    if (switching_block_state == 5) {
      switching_block_state = 0;
      _p_scX++;
    }
    if(_p_scX == L_X){
      Serial.println("Error: max length");
      break;
    }
  }
}

void lcd_create_char() {
  lcd.createChar(0, one_column);
  lcd.createChar(1, two_column);
  lcd.createChar(2, three_column);
  lcd.createChar(3, four_column);
  lcd.createChar(4, five_column);
}

void lcd_startup() {  
  lcd.setCursor(0, 0);
  lcd.write("Please select mode");
  lcd.setCursor(0, 1);
  lcd.write("Default mode: 40 min");
  lcd.setCursor(0, 2);
  lcd.write("Wait:");                                                                                                                                                                                            
}
