String help_s = "help";
String setWorkMode = "set";
String showAlWorkMode = "show";
String correctWorkMode = "correct";

void help() {
  Serial.println(F("***********************************************************************"));
  Serial.println(F("You can use serial commands:"));
  Serial.println(F("    set     - set new work mode "));
  Serial.println(F("    show    - show all work mode"));
  Serial.println(F("    correct - edit simple work mode"));
  Serial.println(F("    help    - print this instruction again"));
  Serial.println(F("***********************************************************************"));
}
// опросчик и парсер сериал
void serialTick() {
  if (Serial.available() > 0) {           // проверка данных на вход
    String buf = Serial.readString();     // читаем как string
    // механизм такой: командой startsWith сравниваем начало строки
    // если совпадает - делаем какие то действия
    // для приёма значений используется такой механизм:
    // строка обрезается командой substring до длины команды .substring(команда.length())
    // оставшееся число преобразуется в число командой .toInt()
    if (buf.startsWith(help_s)) {
      help();
    }
    else if (buf.startsWith(setWorkMode)) {
      Serial.println("Hello!");
    }
    else if (buf.startsWith(showAlWorkMode)) {
      Serial.print("Value is ");
      Serial.println();
    }
    else if (buf.startsWith(correctWorkMode)) {
      value = buf.substring(correctWorkMode.length()).toInt();
      Serial.print("Value set to ");
      Serial.println();
    }
  }
}
