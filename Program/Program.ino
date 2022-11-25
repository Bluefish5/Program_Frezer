#define wenglor_prawy 11
#define wenglor_lewy 12
#define wenglor_przod_Cyfrowy 4
#define wenglor_przod_ADC 7
#define linia_przednia_prawa 2
#define linia_przednia_lewa 3
#define starter A1

#define P_P 5    
#define P_T 10
#define L_P 6
#define L_T 9  

#define plus A0
#define minus 7
#define led 13


void motors_stop()                      
{
    analogWrite(P_P, LOW);
    analogWrite(P_T, LOW);
    analogWrite(L_P, LOW);
    analogWrite(L_T, LOW);
}

void rotation(int speed) //obrut zgodnie z ruchem wskazuwek zegara
{
    motors_stop();
    digitalWrite(P_P, LOW);
    analogWrite(P_T, speed);
    analogWrite(L_P, speed);
    digitalWrite(L_T, LOW);
    delay(10);
}

void forward(int speed) 
{ 
    motors_stop();
    digitalWrite(P_T,LOW);
    digitalWrite(L_T,LOW);
    analogWrite(P_P, speed);
    analogWrite(L_P, speed);
    delay(10);
}

void revers(int speed) 
{
    motors_stop();
    analogWrite(P_P, LOW);
    analogWrite(P_T, speed);
    analogWrite(L_P, LOW);
    analogWrite(L_T, speed);
}

void led_on()
{
   digitalWrite(13,HIGH);
}

void led_off()
{
   digitalWrite(13,LOW);
}

void setup() {
  pinMode(plus, INPUT_PULLUP);
  pinMode(minus, INPUT_PULLUP);

  pinMode(linia_przednia_prawa, INPUT);
  pinMode(linia_przednia_lewa, INPUT);
  pinMode(starter, INPUT);
  
  pinMode(P_P, OUTPUT);
  pinMode(P_P, OUTPUT);
  pinMode(P_P, OUTPUT);
  pinMode(P_P, OUTPUT);
  pinMode(led, OUTPUT);
}

int taktyka = 1;

void loop() {
   while(digitalRead(starter) == LOW)  // Menu wyboru taktyk.
    {
        motors_stop();
        if(digitalRead(plus) == LOW)             
        {      
            taktyka += 1;
            delay(100);
        }
        if(taktyka == 3)taktyka = 1;
        else if(taktyka == 0)taktyka = 2;      
        if(taktyka == 1) led_off();
        else led_on();    
    }
    if(digitalRead(starter) == HIGH) // Jeżeli Robot został wystartowany pilotem.
    {
      switch(taktyka)
      {
        case 1: 
          while(digitalRead(starter) == HIGH)// 1# TAKTYKA TORNADO
          {
             if((wenglor_przod_ADC <400) && (wenglor_przod_ADC >200))forward(255);
             else rotation();
          }
          break;
        case 2:
          while(digitalRead(starter) == HIGH)// 2# TAKTYKA ZMIOTA
          {
            if((wenglor_przod_ADC <400) && (wenglor_przod_ADC >200))forward(255);
            else{
              forward(180);
              if(digitalRead(linia_przednia_prawa)==HIGH)
              {
                rotation()
                delay(60);
              }
              if(digitalRead(linia_przednia_lewa)==HIGH)
              {
                rotation()
                delay(60);
              }
            }
          }
          break;    
      }
    }  
  }
