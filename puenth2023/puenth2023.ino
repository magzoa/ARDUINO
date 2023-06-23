
int in1 = 8;  // Pin que controla el sentido de giro Motor A
int in2 = 9;  // Pin que controla el sentido de giro Motor A
int EnA = 10; // Pin que controla la velocidad del  Motor A

int in3 = 7;  // Pin que controla el sentido de giro Motor B
int in4 = 6;  // Pin que controla el sentido de giro Motor B
int EnB = 5; // Pin que controla la velocidad del  Motor B

void setup (){
  // Controla motores de la izquierda
  pinMode(in1, OUTPUT); // frente 
  pinMode(in2, OUTPUT); // atras
  pinMode(EnA, OUTPUT);
  // controla los motores de la derecha
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  pinMode(EnB, OUTPUT);
}
void loop(){
  
  delay(2000);
  analogWrite(EnA,200);      //Velocidad del  Motor A
  digitalWrite(in1, LOW);  // IR ADELANTE
  digitalWrite(in2, LOW);

  analogWrite(EnB,200);      //Velocidad del  Motor B
  digitalWrite(in3, HIGH);  // IR ADELANTE
  digitalWrite(in4, HIGH);
  
  delay(2000);
  analogWrite(EnA, 200);      //Velocidad del  Motor A
  digitalWrite(in1, HIGH);  // IR atras
  digitalWrite(in2, HIGH);

  analogWrite(EnB,200);      //Velocidad del  Motor B
  digitalWrite(in3, LOW);  // IR Atras
  digitalWrite(in4, LOW);

}