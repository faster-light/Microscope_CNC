char incomingBytes[7];  //Входной пакет
int LED = 13;           //для отладки
bool con = true;        //наличие данных
int error;


int en = 2;       //enable для всех драйверов
int cw_x = 4;     //направление для x
int clk_x = 3;    //счетчик для драйвера x

int cw_y = 4;     //направление для y
int clk_y = 9;    //счетчик для драйвера y

int cw_z = 6;     //направление для z
int clk_z = 10;    //счетчик для драйвера z

int light = 11;    //шим для светодиода

int konc = 8;     //концевик

int sh = 5;       //скорость
int buttonState = 0;    //состояние концевика

int vol = 0;      //яркость светодиода

void setup()    //инициализация
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(cw_x, OUTPUT);
  pinMode(clk_x, OUTPUT);
  pinMode(cw_y, OUTPUT);
  pinMode(clk_y, OUTPUT);
  pinMode(cw_z, OUTPUT);
  pinMode(clk_z, OUTPUT);
  
  pinMode(konc, INPUT);
    
  digitalWrite(LED, HIGH);
  digitalWrite(en, LOW);
  digitalWrite(cw_x, LOW);
  digitalWrite(clk_x, LOW); 
  digitalWrite(cw_y, LOW);
  digitalWrite(clk_y, LOW);
  digitalWrite(cw_z, LOW);
  digitalWrite(clk_z, LOW);
  
}
void loop()
{
  error = 10;
  
  if (Serial.available())   //если что-то пришло
  {
    Serial.readBytes(incomingBytes, 6);   //читаем 6 байт
  
    int a = incomingBytes[0] - '0';       //форматирование данных
    int b = incomingBytes[1] - '0';
    int c = a*10 + b;

    int a1 = incomingBytes[2] - '0';
    int a2 = incomingBytes[3] - '0';
    int a3 = incomingBytes[4] - '0';
    int a4 = incomingBytes[5] - '0';
    int n = a1*1000 + a2*100 + a3*10 + a4;

//      Serial.println(c);              для отладки
//      Serial.println(n);



      if (c == 11)                      //отработка запроса
        {
        digitalWrite(cw_x, HIGH);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_x, HIGH);
              delay(sh);
              digitalWrite(clk_x, LOW);
              delay(sh);             
              }
          }
        }
      if (c == 12)
        {
        digitalWrite(cw_x, LOW);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_x, HIGH);
              delay(sh);
              digitalWrite(clk_x, LOW);
              delay(sh);             
              }
          }
        }
      if (c == 13)
        {
        digitalWrite(cw_y, HIGH);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_y, HIGH);
              delay(sh);
              digitalWrite(clk_y, LOW);
              delay(sh);             
              }
          }
        }
      if (c == 14)
        {
        digitalWrite(cw_y, LOW);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_z, HIGH);
              delay(sh);
              digitalWrite(clk_z, LOW);
              delay(sh);             
              }
          }
        }
      if (c == 15)
        {
        digitalWrite(cw_z, HIGH);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_x, HIGH);
              delay(sh);
              digitalWrite(clk_x, LOW);
              delay(sh);             
              }
          }
        }
      if (c == 16)
        {
        digitalWrite(cw_z, LOW);
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
              digitalWrite(clk_x, HIGH);
              delay(sh);
              digitalWrite(clk_x, LOW);
              delay(sh);             
              }
          }
        }         

        if (c == 17)
             Serial.println("it's good"); 


        if (c == 18)
        {
        digitalWrite(cw_z, LOW);
        vol = 0;
          for (int i=0; i <= n; i++)
          {
             buttonState = digitalRead(konc);
              if (buttonState == HIGH)
              {
                error = 99;
                i = n-1;
              } else
              {
                vol++;         
              }
          }
        }   

      if (c == 19)
        {
          sh = n;
        } 
      
    Serial.print(error);             //печать о завершении и наличии ошибок

  }
}
