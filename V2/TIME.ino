void DETECT_LESSON_COUNT() {
  long realtime = TIME_CONVERTER(time.Hours, time.minutes, time.seconds);
  long temptime;
  if (selected_mode == 0) {
    for (int i = 23; i >= 0; i--) {
      temptime = TIME_CONVERTER(min40_shedule[i].hours, min40_shedule[i].minutes, min40_shedule[i].seconds);
      if (temptime < realtime) {
        state = i;
        if (state >= 24) {
          state = 0;
        }
        break;
      }
    }
  }
  if (selected_mode == 1) {
    for (int i = 23; i >= 0; i--) {
      temptime = TIME_CONVERTER(min30_shedule[i].hours, min30_shedule[i].minutes, min30_shedule[i].seconds);
      if (temptime < realtime) {
        state = i;        
        if (state >= 24) {
          state = 0;
        }
        break;
      }
    }
  }
}

long TIME_CONVERTER(int val1, int val2, int val3) {
  long result;
  long temp_val1 = (long)val1;
  long temp_val2 = (long)val2;
  long temp_val3 = (long)val3;
  result = temp_val1 * 3600;
  result = result + temp_val2 * 60;
  result = result + temp_val3;
  return result;
}
