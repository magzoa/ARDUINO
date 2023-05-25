#include <infrarrojo.h>

#define PIN_TRIG 7
#define PIN_ECO 6
const int motor2=2;
const int motor3=3;//PWM
const int motor4=4;
const int motor5=5;//PWM

const int velA=10;//PWM
const int velB=11;//PWM

const int limitePin=9;
const int limitePin2=12;
const int limitePin3=13;

infrarrojo estado(8);
int VALOR;
int estado_infrarrojo;
String direccion;

long duracion, distancia;
  int limite;
  int limite2;
  int limite3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  
  
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECO, INPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(velA,OUTPUT);
  pinMode(velB,OUTPUT);  


}

void loop() {
  limite=digitalRead(limitePin);
  limite2=digitalRead(limitePin2); 
  limite3=digitalRead(limitePin3);  
    //SI ESTA EN EL ESPACIO NEGRO
  if(limite==1&&limite2==1){
    Serial.print("NEGRO");
    Serial.println(limite);
    
   //LEYENDO SI ULTRASONIDO ENCONTRO ALGO ENFRENTE
    digitalWrite (PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite (PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite (PIN_TRIG, LOW);
  duracion = pulseIn(PIN_ECO, HIGH);
  distancia = (duracion/2)/29; 
    
    //LEYENDO SI INFRARROJO ENCONTRO ALGO ENFRENTE
    estado_infrarrojo=estado.lectura(VALOR);
    if ((distancia>0 & distancia<50)|estado_infrarrojo==0){
    
    adelante();
    direccion="adelante"; 
    Serial.print(estado_infrarrojo);
    Serial.println("Encontrado infrarrojo");
     Serial.print(distancia);
     Serial.println(" cm");
    }else{
      derecha();
      
       Serial.print(estado_infrarrojo);
       Serial.println("No Encontrado infrarrojo");
       
               // Hacer algoritmo para el limite3
               if(limite3==0&&direccion="derecha"){
               adelante();
                }else{
              izquierda();
                }
  
       
       
      
    //  delay(2000);
    }
    
    
   
    //EN CASO DE ESTAR SOBRE EL LIMITE
  }else{
    
    
  reversa();
  delay(200);
  Serial.print("BLANCO");
    Serial.println(limite);
  derecha();
  //delay(2000);
  
 
  
    
      
}
 //imprimir();
//delay(500);
}


//dirigirse hacia adelante
void reversa(){

  digitalWrite(motor2,HIGH);
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);
  digitalWrite(motor5,LOW);
  analogWrite(velA,150);
  analogWrite(velB,150);

}
//dirigirse hacia atraz
void adelante(){
 analogWrite(velA,250);
  analogWrite(velB,250);
 digitalWrite(motor2, LOW);
 digitalWrite(motor3, HIGH);
 digitalWrite(motor4, LOW);
 digitalWrite(motor5, HIGH);
 

}

void derecha(){
  analogWrite(velA,150);
  analogWrite(velB,150);
  digitalWrite(motor2,HIGH);
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,LOW);
  digitalWrite(motor5,HIGH);
 

}

void izquierda(){

  digitalWrite(motor2,LOW);
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,LOW);
  digitalWrite(motor5,HIGH);
   analogWrite(velA,150);
  analogWrite(velB,150);

}


