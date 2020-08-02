#include "Led.h"

LedLib::LedLib(int _pin, bool db){
  pin = _pin;
  _debug = db;
}

void LedLib::say(){
  LedLib::lkl();
  Serial.println("say");
}

void LedLib::lkl(){
  Serial.print("lkl ");
}

void LedLib::start_db(int baud){
  if( _debug){
    Serial.begin(baud);
    Serial.println("!Started!");
  }
}

void LedLib::on(int a){
  if( _debug){
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.print(" is at ");
    Serial.print(a);
    Serial.println(" brightness!");
  }
  analogWrite(pin, a);
}

void LedLib::off(){
  if( _debug){
    Serial.print("Pin");
    Serial.print(pin);
    Serial.println(" is low");
   }
  digitalWrite(pin, LOW);
}

void LedLib::fade(int am, int dl, bool tf){
  pinMode(pin, OUTPUT);
  int i = am -1;
  if(tf){
   for (i; i <= 255; i++){
    analogWrite(pin, i);
    delay(dl);
    if( _debug){
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.print(" is at ");
    Serial.print(i);
    Serial.println(" brightness!");
      }
    }
  }
  else{
    for (i; i >= 0; i--){
    analogWrite(pin, i);
    delay(dl);
    if( _debug){
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.print(" is at ");
    Serial.print(i);
    Serial.println(" brightness!");
      }
    }
  }
}

void LedLib::blk(int dlt) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  if( _debug){
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.println(" is high");
    }
  delay(dlt);
  digitalWrite(pin, LOW);
  if( _debug){
    Serial.print("Pin ");
    Serial.print(pin);
    Serial.println(" is low");
   }
  delay(dlt);
}
