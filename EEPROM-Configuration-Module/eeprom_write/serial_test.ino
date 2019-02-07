/*
  Данный код позволяет принять данные, идущие из порта, в строку (String) без "обрывов"
*/
String strData = "";
boolean recievedFlag;
void setup() {
  Serial.begin(9600);
}
void loop() {
  while (Serial.available() > 0) {         // ПОКА есть что то на вход    
    strData += (char)Serial.read();        // забиваем строку принятыми данными
    recievedFlag = true;                   // поднять флаг что получили данные
    delay(2);                              // ЗАДЕРЖКА. Без неё работает некорректно!
  }
  if (recievedFlag) {                      // если данные получены
    Serial.println(strData);               // вывести
    strData = "";                          // очистить
    recievedFlag = false;                  // опустить флаг
  }
}
