
#include <WiFi.h>

#include <Espalexa.h>

int Foco = 5;
int Puerta = 24;
int Senal = 4;
int servo=18;
int servo2=19;
float Estado;


const char* nameRed = "juRedmi Note 9S";
const char* contraRed = "Juanes453";

Espalexa alexam;

void FuncionFoco(uint8_t brightness);
void FuncionPuerta(uint8_t brightness);
void FuncionMatriz(uint8_t brightness);


void setup() {
  Serial.begin(115200);
  pinMode(Foco, OUTPUT);
  pinMode(Puerta,OUTPUT);
  pinMode(Senal, OUTPUT);
  pinMode(servo, OUTPUT);
  pinMode(servo2, OUTPUT);

  ConectarWifi();
  alexam.addDevice("Foco", FuncionFoco);
  alexam.addDevice("Puerta", FuncionPuerta);
  alexam.addDevice("Matriz",FuncionMatriz);
  alexam.begin();
   
 }

void loop() {
  ConectarWifi();
  alexam.loop();
  delay(1);
  
}

void ConectarWifi() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(nameRed, contraRed);
    Serial.println('C');
    Serial.println("");
    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
      
      delay(500);
      Serial.print(".");
    }
    Serial.print("Connected to ");
    Serial.println(nameRed);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void FuncionFoco(uint8_t brightness) {
  Serial.print("Funcion Foco - ");

  if (brightness) {
    digitalWrite(Foco, 0);
    Serial.println(" Encender ");
    digitalWrite(Senal, HIGH);
    
  }
  else {
    digitalWrite(Foco, 1);
    Serial.println(" Apagar ");
    digitalWrite(Senal, LOW);
  }
}

void FuncionPuerta(uint8_t brightness) {
  Serial.print("Funcion Puerta -");

  if (brightness) {
    Serial.println(" Gira ");
    digitalWrite(Senal, HIGH);
  giro(0);
  giro2(110);
  delay (500);
  giro(10);
  giro2(100);
  delay (500);
  giro(20);
  giro2(90);
  delay (500);
  giro(30);
  giro2(80);
  delay (500);
  giro(40);
  giro2(70);
  delay (500);
  giro(50);
  giro2(60);
  delay (500);
  giro(60);
  giro2(50);
  delay (500);
  giro(70);
  giro2(40);
  delay (500);
  giro(80);
  giro2(30);
  delay (500);
  giro(90);
  giro2(20);
  delay (500);
  giro(100);
  giro2(10);
  delay (500);
  giro(110);
  giro2(0);
  }
  else {
    Serial.println(" Cierra ");
    digitalWrite(Senal, LOW);
  giro(110);
  giro2(0);
  delay (500);
  giro(100);
  giro2(10);
  delay (500);
  giro(90);
  giro2(20);
  delay (500);
  giro(80);
  giro2(30);
  delay (500);
  giro(70);
  giro2(40);
  delay (500);
  giro(60);
  giro2(50);
  delay (500);
  giro(50);
  giro2(60);
  delay (500);
  giro(40);
  giro2(70);
  delay (500);
  giro(30);
  giro2(80);
  delay (500);
  giro(20);
  giro2(90);
  delay (500);
  giro(10);
  giro2(100);
  delay (500);
  giro(0);
  giro2(110);
  }

}
void FuncionMatriz(uint8_t brightness) {
  Serial.print("Funcion Matriz -");

  if (brightness) {
    Serial.println("Enciende ");
    digitalWrite(Senal, HIGH);
    delay(2000);
  }
  else {
    Serial.println("Apaga");
    digitalWrite(Senal, LOW);
    delay(2000);
  }
}
void giro(int x){
  for(int hz=1; hz<=50;hz++)
  {
    Estado=(x*2000.0/200.0)+500;
    digitalWrite (servo,HIGH);
    delayMicroseconds(Estado);              
    digitalWrite (servo,LOW);
    delayMicroseconds(2300-Estado);  
  }
}
void giro2(int x){
  for(int hz=1; hz<=50;hz++)
  {
   Estado=(x*2000.0/200.0)+500;
    digitalWrite (servo2,HIGH);
    delayMicroseconds(Estado);              
    digitalWrite (servo2,LOW);
    delayMicroseconds(2300-Estado);  
}
}
