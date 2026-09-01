#pragma once

#include "Byte.hpp"
#include "MemorySize.hpp"
#include "strlen.hpp"
#include "Print_CharPointer.hpp"

namespace pankey{

	namespace Library{

		namespace Print{

			struct ArduinoPrinter{
				pankey::Memory::Allocator::memory_size write(pankey::Type::Array::Byte byte){
					Serial.print(static_cast<char>(byte));
					return 1;
				}

				pankey::Memory::Allocator::memory_size writeString(const char* str){
					if(str == nullptr){
						return 0;
					}
					Serial.print(str);
					return pankey::Utility::Test::strlen(str);
				}

				pankey::Memory::Allocator::memory_size newline(){
					Serial.println();
					return 1;
				}

				void flush(){
					Serial.flush();
				}
			};

			ArduinoPrinter g_printer;

			template<class T>
			void print(const T& a_value){
				pankey::Support::Print::template print<ArduinoPrinter>(g_printer, a_value);
			}

			template<class T>
			void println(const T& a_value){
				pankey::Support::Print::template print<ArduinoPrinter>(g_printer, a_value);
				g_printer.newline();
			}

			void println(){
				g_printer.newline();
			}

		}

	}

}