// by @vla-vi21 (inst)
#include <LiquidCrystal_I2C.h> //Библиотеки для дисплея/шины
#include <Wire.h>


LiquidCrystal_I2C LCD(0x27, 16, 2); //указываем параметры дисплея



const int ledPin1 = 2;       //подключаем 1 светодиод (зелёный)
const int ledPin2 = 3;       //подключаем 2 светодиод (жёлтый)
const int ledPin3 = 4;       //подключаем 3 светодиод (красный)
void setup() {


  digitalWrite(8, HIGH); //указываем пин кнопки и её состояние
 
  pinMode(ledPin1, OUTPUT); //инициализируем светодиоды (OUTPUT -выход,выдаёт 0 или 5 вольт)
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  LCD.init();            //инициализируем дисплей и подсветку
  LCD.backlight();  
}

int t = 0; //переменная таймера
int b = 0; //переменная счётчика

void loop() {
  
  if (digitalRead(8) == LOW)  //указываем пин кнопки и её состояние
  {
    b++; //счётчик нажатий кнопки
    if (b == 4) { //если кнопка нажата 4 раза - счётчик b будет равен 1
      b = 1;
    }
  }

  if (b == 1) { //если кнопка нажата 1 раз - таймер  начинает работу
    t++; //счётчик таймера

    LCD.setCursor(0, 0);
    LCD.print(t);
    digitalWrite(ledPin3, 0);
    digitalWrite(ledPin1, 1);
    delay(50);

  }
  else if (b == 2) { //если кнопка нажата 2 раз - таймер стоит на паузе
    t = t;
   
    LCD.setCursor(0, 0);
    LCD.print(t);
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 1);
    delay(100);
    digitalWrite(ledPin2, 0);
    delay(50);
  }
  else if (b == 3) { //если кнопка нажата 3 раз - таймер сбрасывается 
    t = 0;

    LCD.setCursor(0, 0);
    LCD.print(t);
    digitalWrite(ledPin3, 1);
    delay(500);
    digitalWrite(ledPin3, 1);
    delay(50);
  }

  delay(1000);
}
