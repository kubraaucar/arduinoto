#define MLF 5  // SOL ILERI
#define MRF 10 //SAG ILERI
#define MRB 6 //SAG GERI
#define MLB 9 //SOL GERI
#define ENA 11 // SAG HIZ  
#define ENB 3 // SOL HIZ   

#define MS1_TRIG 2 
#define MS1_ECHO 7
#define MS2_TRIG 8
#define MS2_ECHO 4
#define MS3_TRIG 12
#define MS3_ECHO 13

#define LIGHT_SENSOR_PIN A3 // Işık sensörü analog pini

const int LIGHT_THRESHOLD = 300; // Karanlık algılama eşiği
const int distanceThreshold = 27;

bool isDark = false; // Karanlık algılama durumu

void setup() {
  // Motor pinlerini çıkış olarak tanımlıyoruz
  pinMode(MRB, OUTPUT);
  pinMode(MRF, OUTPUT);
  pinMode(MLB, OUTPUT);
  pinMode(MLF, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(MS1_TRIG, OUTPUT);
  pinMode(MS2_TRIG, OUTPUT);
  pinMode(MS3_TRIG, OUTPUT);


  pinMode(MS1_ECHO, INPUT);
  pinMode(MS2_ECHO, INPUT);
  pinMode(MS3_ECHO, INPUT);


  Serial.begin(9600);
}

void loop() {

  
   
    kontrolMesafe();
    
    kontrolLDR();

}

void kontrolLDR() {
    int lightLevel = analogRead(LIGHT_SENSOR_PIN);
   
    if (lightLevel < LIGHT_THRESHOLD) {
        if (!isDark) {
            dur();
            delay(4000); // 5 saniye bekle
            ileri();
            delay(3000);
            isDark = true; // Karanlık algılandığını işaretle
        }
    } else {
        isDark = false; // Karanlık algılaması sıfırla
    }
    
}

void kontrolMesafe() {

    if (isDark) {
        return; // Karanlık algılandığında mesafe kontrolünü atla
    }

    int distance1 = measureDistance_MS1(MS1_TRIG, MS1_ECHO);
    int distance2 = measureDistance_MS2(MS2_TRIG, MS2_ECHO);
    int distance3 = measureDistance_MS3(MS3_TRIG, MS3_ECHO);
    
        Serial.println(distance3);

        

    if (distance1 > 0 && distance1 < 100 && distance3 > 0 && distance3 < 100) {

   
        if (distance2 <= distanceThreshold) {
            dur();
            delay(500);
            geri();
            delay(600);

            if (distance3 > 45 || distance3 > distance1) {
                sag();
                delay(810);
            } else if (distance1 > 45 || distance1 > distance3) {
                sol();
                delay(820);
            }
        } else {
            ileri();
            
            if (distance1 < 10) {
                sag();
                delay(30);
            } else if (distance3 < 10) {
                sol();
                delay(30);
            }
             if (distance1 >= 50 && distance3 >= 50 && distance2 <= distanceThreshold) {
            dur();
            while (true); }// Sonsuz döngü ile programı durdur

        }
    }
    
}

int measureDistance_MS1(int trig1, int echo1) {
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  
  long duration = pulseIn(echo1, HIGH);
  int distance1 = duration / 29.1 / 2;
  
  return distance1;
}

int measureDistance_MS2(int trig2, int echo2) {
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  
  long duration = pulseIn(echo2, HIGH);
  int distance2 = duration / 29.1 / 2;
  
  return distance2;
}

int measureDistance_MS3(int trig3, int echo3) {
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  
  long duration = pulseIn(echo3, HIGH);
  int distance3 = duration / 29.1 / 2;
  
  return distance3;
}
void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 1);  
  digitalWrite(MRB, 0);  
  analogWrite(ENA, 100);   
  digitalWrite(MLF, 1); 
  digitalWrite(MLB, 0);   
  analogWrite(ENB, 120);  
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
  analogWrite(ENA, 10);    // Sağ motorun hızı 0
  digitalWrite(MLF, 1);
  digitalWrite(MLB, 0);     
  analogWrite(ENB, 95);    // Sol motorun hızı 180
}

void sol(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz
  digitalWrite(MRF, 1);
  digitalWrite(MRB, 0);    
  analogWrite(ENA, 80);    // Sağ motorun hızı 150
  digitalWrite(MLF, 1);
  digitalWrite(MLB, 0);     
  analogWrite(ENB,10);    // Sol motorun hızı 0
}

void dur() { // Robotun durması için fonksiyon tanımlıyoruz
  digitalWrite(MRF, LOW);   // Sağ motoru durdur
  digitalWrite(MRB, LOW);   // Sağ motoru durdur
  analogWrite(ENA, 0);      // Sağ motor hızı 0
  digitalWrite(MLF, LOW);   // Sol motoru durdur
  digitalWrite(MLB, LOW);   // Sol motoru durdur
  analogWrite(ENB, 0);      // Sol motor hızı 0
}