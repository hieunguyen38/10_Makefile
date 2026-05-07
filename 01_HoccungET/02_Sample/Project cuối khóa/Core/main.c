#include <stdint.h>
#include "GPIO.h"
#include "RCC.h"
void delay(uint32_t time){
	uint32_t tmp;
	for(tmp = 0 ; tmp < 1000;tmp++){
		while(time--);
	}
}
int main(){
	
	RCC_Enable_PortA();
	GPIO_Config(GPIOA, GPIO_PIN_0, GPIO_MODE_OUTPUT_PP);
	while(1){
		GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
		delay(1000);
		GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
		delay(1000);
	}

	return 0;
}