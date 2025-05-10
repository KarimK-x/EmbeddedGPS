#include "systick.h"

void SysTick_Handler(void) {
    // Code
}

void Systick_voidInit(){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = RELOAD_MAX_VALUE;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;

}



void Systick_voidInitISR(){
    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = RELOAD_MAX_VALUE;
    NVIC_ST_CURRENT_R = 0;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_INTEN;

}



void Systick_voidWait(int count){
    NVIC_ST_RELOAD_R = count-1;
    NVIC_ST_CURRENT_R = 0;
    while(!(NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT)){}
}



void Systick_voidDelayms(int time){
    for(int i=0; i<time; ++i){
        Systick_voidWait(CYCLES_PER_MS);
    }
}
void Systick_voidDelayus(int time){
	for(int i=0; i<time; ++i){
			Systick_voidWait(CYCLES_PER_US);
	}
}

void Systick_voidDisable(void) {
    NVIC_ST_CTRL_R = 0;
}


    
