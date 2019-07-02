#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
void USART1_Init(u32 bound);
void myprintfUSART1( const char* fmt, ... );
void mySerialWriteUSART1( const uint8_t* sendBuff, int sendLen );
#endif


