#include <math.h>
//ponte h portas
#define IN1   7 
#define IN2   5 
#define VEL_A 6 
#define IN3   4
#define IN4   2 
#define VEL_B 3
//botoes
#define BUTTON_1 11
#define BUTTON_2 10 
//VARIAVEIS
int velocidade = 0;

void setup() {
  // Iniciando a serial do arduino
  Serial.begin(9600);
  // iniciando os pinos do motor
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(VEL_A,OUTPUT);
  pinMode(VEL_B,OUTPUT);
  //iniciar os botoes
  pinMode(BUTTON_1,INPUT);
  pinMode(BUTTON_2,INPUT);
}

void loop() {
  // verifica se o botão 1 foi pressionado
  if(digitalRead(BUTTON_1) == HIGH && velocidade < 250){
    // aumentar a velocidade e colocar um delay
    velocicade += 10;
    delay(80);
  }
  // verifica se o botão 2 foi pressionado
  if(digitalRead(BUTTON_2) == HIGH && velocidade > -250){
    // aumentar a velocidade e colocar um delay
    velocicade -= 10;
    delay(80);
  }//Se a velocidade for maior que 0 girar pra frente
  if(velocidade >0){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }// se a velocidade for igual a 0 carrinho parado
  else if(velocidade == 0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }//se a velocidade for menor que 0 carrinho pra tras
  else if(velocidade < 0){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }//controle de velocidade
  analogWrite(VEL_A,abs(velocidade));
  analogWrite(VEL_B,abs(velocidade));
  delay(80);
}
