#include "tm4c123gh6pm.h"
#define SYSTEM_CLOCK     48000000UL   // 16 MHz
#define CYCLES_PER_MS    (SYSTEM_CLOCK   / 1000 )
#define CYCLES_PER_US    (SYSTEM_CLOCK  / 1000000 )
#define RELOAD_MAX_VALUE 0x00FFFFFF
//CTRL_REG PINS



void Systick_voidInit(void);
void Systick_voidWait(int count);
void Systick_voidDelayms(int time);
void Systick_voidDelayus(int time);

void Systick_voidInitISR(void);
void Systick_voidDisable(void);
void SysTick_Handler(void);
