#pragma once

#include "CharPointer.hpp"
#include "ByteArray.hpp"

template<class T>
void ArduinoLog(int a_status, const pankey::Utility::Test::CharPointer& a_class, const pankey::Utility::Test::CharPointer& a_method, T a_value){
  Serial.print("Status: ");
  Serial.print(a_status);
  Serial.print(", Class: ");
  Serial.print(a_class.get());
  Serial.print(", Method: ");
  Serial.print(a_method.get());
  Serial.print(", Value: ");
  Serial.println(a_value);
}

template<>
void ArduinoLog<pankey::Type::Array::ByteArray>(int a_status, const pankey::Utility::Test::CharPointer& a_class, const pankey::Utility::Test::CharPointer& a_method, pankey::Type::Array::ByteArray a_value){
  Serial.print("Status: ");
  Serial.print(a_status);
  Serial.print(", Class: ");
  Serial.print(a_class.get());
  Serial.print(", Method: ");
  Serial.print(a_method.get());
  Serial.print(", Value: ");
  for(int x = 0; x < a_value.length(); x++){
    Serial.print((char)a_value.get(x));
  }
  Serial.println();
}

template<>
void ArduinoLog<pankey::Utility::Test::CharPointer>(int a_status, const pankey::Utility::Test::CharPointer& a_class, const pankey::Utility::Test::CharPointer& a_method, pankey::Utility::Test::CharPointer a_value){
  Serial.print("Status: ");
  Serial.print(a_status);
  Serial.print(", Class: ");
  Serial.print(a_class.get());
  Serial.print(", Method: ");
  Serial.print(a_method.get());
  Serial.print(", Value: ");
  Serial.println(a_value.get());
}

#ifndef pankey_Log
  #define pankey_Log(status,name,method,mns) ArduinoLog(status,name,method,mns)
#endif 