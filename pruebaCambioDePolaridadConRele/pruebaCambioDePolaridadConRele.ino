//utilización de pines
int pin1 = 10; //Conectamos el pulsador en el pin 2
int pin2 = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1, 1);  
  digitalWrite(pin2, 0);
  delay(10000);
  digitalWrite(pin1, 0);  
  digitalWrite(pin2, 0);
  delay(2000); 
  digitalWrite(pin1, 0);
  digitalWrite(pin2, 1);
  delay(10000);
  digitalWrite(pin1, 0);  
  digitalWrite(pin2, 0);
  delay(2000);   

}
