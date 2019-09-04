void TICK() {  
  switch (selected_mode) {
    case 0:
      if (time.Hours == min40_shedule[state].hours && time.minutes == min40_shedule[state].minutes && time.seconds == min40_shedule[state].seconds) {
        RELAY_ON_OFF();
        state++;
      } 
      break;
    case 1:
      if (time.Hours == min30_shedule[state].hours && time.minutes == min30_shedule[state].minutes && time.seconds == min30_shedule[state].seconds) {
        RELAY_ON_OFF();
        state++;
      } 
      break;
    case 2:
      RELAY_ON_OFF();
      RELAY_ON_OFF();
      RELAY_ON_OFF();
      selected_mode = 4;
      viewed_mode = 4;
      break;
    case 3:
      digitalWrite(RELAY_PIN, HIGH);
      delay(60000);
      selected_mode = 4;
      viewed_mode = 4;
      break;
    default:

      break;
  }
}

void RELAY_ON_OFF() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(DELAY * 1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(DELAY * 1000);
}

void CHECK(){
  if (time.weekday == 0) {
    selected_mode = 4;
    viewed_mode = 4;
  } else {
    selected_mode = 0;
    viewed_mode = 0;
  }
  if (time.month == 6 || time.month == 7 || time.month == 8) {
    selected_mode = 4;
    viewed_mode = 4;
  } else {
    selected_mode = 0;
    viewed_mode = 0;
  }
}
