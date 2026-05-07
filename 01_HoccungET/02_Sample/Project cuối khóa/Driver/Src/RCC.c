#include "RCC.h"

void RCC_Config_72Mhz(){
	// Enable HSE
	RCC->CR.BITS.HSEON = 1;
	while(!RCC->CR.BITS.HSERDY){}
	//Config Flash 
	ACR->BITS.LATENCY = 2;	
	// PLL x9
	RCC->CFGR.BITS.PLLSRC = 1;	
	RCC->CFGR.BITS.PLLMUL = 7;
	RCC->CR.BITS.PLLON = 1;
	while(!RCC->CR.BITS.PLLRDY);
		
	// Div clock
	RCC->CFGR.BITS.HPRE = 0;   // AHB prescaler = 1
	RCC->CFGR.BITS.PPRE1 = 4;  // APB1 = SYSCLK / 2 
	RCC->CFGR.BITS.PPRE2 = 0;  // APB2 = SYSCLK / 1 
	// PLL as SysClk
	
	RCC->CFGR.BITS.SW = 2;
	while(RCC->CFGR.BITS.SWS != 2){}
}

void RCC_Enable_PortA(){
	 RCC->APB2ENR.BITS.IOPAEN = 1;
}
void RCC_Enable_PortB(){
	 RCC->APB2ENR.BITS.IOPBEN = 1;
}
void RCC_Enable_PortC(){
	 RCC->APB2ENR.BITS.IOPCEN = 1;
}