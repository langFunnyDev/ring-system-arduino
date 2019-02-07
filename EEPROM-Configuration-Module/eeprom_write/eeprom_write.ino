#include <EEPROM.h>
#define PARSE_AMOUNT 2         // число значений в массиве, который хотим получить
#define 
int intData[PARSE_AMOUNT];     // массив численных значений после парсинга
int list[]
boolean recievedFlag;
boolean getStarted;
byte index;
byte i = 1; // номер урока 
String string_convert = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to configuration mode of Arduino Ring System ");
  Serial.println("Configuration of normal mode:");
  Serial.println("Input format: #XX:YY;, when XX - Hours, YY - minutes");
  while (true){
    parsing();    
  }
}

void loop() {

}

void parsing() {
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();        // обязательно ЧИТАЕМ входящий символ
    if (getStarted) {                         // если приняли начальный символ (парсинг разрешён)
      if (incomingByte != ':' && incomingByte != ';') {   // если это не пробел И не конец
        string_convert += incomingByte;       // складываем в строку
      } else {                                // если это пробел или ; конец пакета
        intData[index] = string_convert.toInt();  // преобразуем строку в int и кладём в массив
        string_convert = "";                  // очищаем строку
        index++;                              // переходим к парсингу следующего элемента массива
      }
    }
    if (incomingByte == '#') {                // если это $
      getStarted = true;                      // поднимаем флаг, что можно парсить
      index = 0;                              // сбрасываем индекс
      string_convert = "";                    // очищаем строку
    }
    if (incomingByte == ';') {                // если таки приняли ; - конец парсинга
      getStarted = false;                     // сброс
      recievedFlag = true;                    // флаг на принятие
      i++;
    }
  }
}

void out_result_parsing(){
  Serial.println("Number of lesson: ");
  Serial.print(i);
  Serial.print("  time: ")
}
