#ifndef __BEEP_H__
#define __BEEP_H__
#include "sys.h"

#define ON  0   //宏定义
#define OFF 1
#define BEEP(a) if(a) \
											GPIO_SetBits(GPIOA,GPIO_Pin_8); \
								else \
											GPIO_ResetBits(GPIOA,GPIO_Pin_8)
								
#define	Beep PAout(8)  //选中FLASH					

void Beep_Init(void);
void Beep_Test(void);
#endif
