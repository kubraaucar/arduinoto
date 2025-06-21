#define MLF 5  // SOL ILERI
#define MRF 10 //SAG ILERI
#define MRB 6 //SAG GERI
#define MLB 9 //SOL GERI
#define ENA 11 // SAG HIZ  11 eski pin
#define ENB 3 // SOL HIZ    3 eski pin

  char state; //Bluetooth cihazından gelecek sinyalin char değişkeni
  int vSpeedR=150;     // Standart Hız, 0-255 arası bir değer alabilir
  int vSpeedL=180;

void setup() {

    pinMode(MLF, OUTPUT);
    pinMode(MRF, OUTPUT);
    pinMode(MRB, OUTPUT);
    pinMode(MLB, OUTPUT);  

    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    Serial.begin(9600);


  
}

void loop() {

   if (Serial.available() > 0) {
    state = Serial.read();
    Serial.println(state);
   }


  if (state == 'I') {
      ileri();
    }

    else if (state == 'G') {
      geri();
    }
    
  
    else if (state == 'L') {
     sol();
    }
     
  
    else if (state == 'R') {
     sag();
    }

    else if (state == 'D'){ 
      dur();
      }

}

void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 1);  
  digitalWrite(MRB, 0);  
  analogWrite(ENA, 200);   
  digitalWrite(MLF, 1); 
  digitalWrite(MLB, 0);   
  analogWrite(ENB, 240);  
} 

void geri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 0);
  digitalWrite(MRB, 1);   
  analogWrite(ENA, 70);    // Sağ motorun hızı 150 
  digitalWrite(MLF, 0);
  digitalWrite(MLB, 1);     
  analogWrite(ENB, 70);    // Sol motorun hızı 180
}

void sag(){  // Robotun sag yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 1);
  digitalWrite(MRB, 0);    
  analogWrite(ENA, 20);    // Sağ motorun hızı 0
  digitalWrite(MLF, 1);
  digitalWrite(MLB, 0);     
  analogWrite(ENB, 170);    // Sol motorun hızı 180
}

void sol(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 1);
  digitalWrite(MRB, 0);    
  analogWrite(ENA, 150);    // Sağ motorun hızı 150
  digitalWrite(MLF, 1);
  digitalWrite(MLB, 0);     
  analogWrite(ENB,20);    // Sol motorun hızı 0
}

void dur() { // Robotun durması için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 0);   // Sağ motoru durdur
  digitalWrite(MRB, 0);   // Sağ motoru durdur
  analogWrite(ENA, 0);      // Sağ motor hızı 0
  digitalWrite(MLF, 0);   // Sol motoru durdur
  digitalWrite(MLB, 0);   // Sol motoru durdur
  analogWrite(ENB, 0);      // Sol motor hızı 0
}