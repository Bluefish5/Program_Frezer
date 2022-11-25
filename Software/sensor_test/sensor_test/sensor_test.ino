#define wenglor_prawy 11
#define wenglor_lewy 12
#define wenglor_przod_Cyfrowy 4
#define wenglor_przod_ADC 7
#define linia_przednia_prawa 2
#define linia_przednia_lewa 3
#define starter A1
#define plus A0
#define minus 7
#define led 13

void setup() {
    Serial.begin(9600);
}
void loop() {
  
     Serial.print("starter: ");
    Serial.print(analogRead(starter));
    Serial.print("   ");
    
     Serial.print("plus: ");
    Serial.print(analogRead(plus));
    Serial.print("   ");
    
     Serial.print("minus: ");
    Serial.print(analogRead(minus));
    Serial.print("   ");
    
     Serial.print("wenglor_przod_ADC: ");
    Serial.print(analogRead(wenglor_przod_ADC));
    Serial.print("   ");
    
    Serial.print("linia_przednia_prawa: ");
    Serial.print(analogRead(linia_przednia_prawa));
    Serial.print("   ");
    
    Serial.print("linia_przednia_lewa: ");
    Serial.print(analogRead(linia_przednia_lewa));
    Serial.print("   ");
    
    Serial.print("wenglor_prawy: ");
    Serial.print(analogRead(wenglor_prawy));
    Serial.print("   ");
    
    Serial.print("wenglor_lewy: ");
    Serial.print(analogRead(wenglor_lewy));
    Serial.print("   ");
    
    Serial.print("wenglor_przod_Cyfrowy: ");
    Serial.print(analogRead(wenglor_przod_Cyfrowy));
    Serial.println("   ");
}
