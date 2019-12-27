String setSeconds = "sec";
String setMinutes = "min";
String setHours = "hour";
String setDay = "day";
String setMonth = "month";
String setYear = "year";
String setWeekday = "weekday";

int value = 0;

void SERIAL_TICK() {
  if (Serial.available() > 0) {
    String buf = Serial.readString();
    if (buf.startsWith(setSeconds)) {
      value = buf.substring(setSeconds.length()).toInt();
      time.settime(value);
    }
    else if (buf.startsWith(setMinutes)) {
      value = buf.substring(setMinutes.length()).toInt();
      time.settime(-1, value);
    }
    else if (buf.startsWith(setHours)) {
      value = buf.substring(setHours.length()).toInt();
      time.settime(-1, -1, value);
    }
    else if (buf.startsWith(setDay)) {
      value = buf.substring(setDay.length()).toInt();
      time.settime(-1, -1, -1, value);
    }
    else if (buf.startsWith(setMonth)) {
      value = buf.substring(setMonth.length()).toInt();
      time.settime(-1, -1, -1, -1, value);
    }
    else if (buf.startsWith(setYear)) {
      value = buf.substring(setYear.length()).toInt();
      time.settime(-1, -1, -1, -1, -1, value);
    }
    else if (buf.startsWith(setWeekday)) {
      value = buf.substring(setWeekday.length()).toInt();
      time.settime(-1, -1, -1, -1, -1, -1, value);
    }
  }
}
