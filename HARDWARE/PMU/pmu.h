#ifndef __PMU_H
#define __PMU_H	
#include "sys.h"
  /**************************************************************************
���ߣ�ƽ��С��֮��
�ҵ��Ա�С�꣺http://shop114407458.taobao.com/
**************************************************************************/
#define Battery_Ch 9

typedef struct {
	int Voltage_Temp;
	uint8_t Voltage_Count;
	int Voltage_All;
	int Voltage_Sum;
	int Voltage;
}PMU;

void PMU_Init(PMU * pmu);
int PMU_batteryVolt(void);   
uint16_t PMU_getAdc(u8 ch);
void PMU_Loop(PMU * pmu);
#endif 
