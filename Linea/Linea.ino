const int sensorPin=4;

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


  if(digitalRead(sensorPin)==HIGH){

    Serial.println("detecto Blanco");


  }else{
    Serial.println("Detecto Negro");
  }

}
