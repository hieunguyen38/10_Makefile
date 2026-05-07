#ifndef RCC_H
#define RCC_H
#include <stdint.h>

//-------------------------------------STRUCT----------------------------------------
typedef struct {
    union {
        uint32_t REG;
        struct {
            uint32_t HSION     : 1;
            uint32_t HSIRDY    : 1;
            uint32_t Reserved1 : 1;
            uint32_t HSITRIM   : 5;
            uint32_t HSICAL    : 8;
            uint32_t HSEON     : 1;
            uint32_t HSERDY    : 1;
            uint32_t HSEBYP    : 1;
            uint32_t CSSON     : 1;
            uint32_t Reserved2 : 4;
            uint32_t PLLON     : 1;
            uint32_t PLLRDY    : 1;
			uint32_t PLL2      : 1;
            uint32_t PLL2RDY   : 1;
			uint32_t PLL3      : 1;
            uint32_t PLL3RDY   : 1;
            uint32_t Reserved3 : 2;
        } BITS;
    } CR;
    
    union {
        uint32_t REG;
        struct {
            uint32_t SW        : 2;
            uint32_t SWS       : 2;
            uint32_t HPRE      : 4;
            uint32_t PPRE1     : 3;
            uint32_t PPRE2     : 3;
            uint32_t ADCPRE    : 2;
            uint32_t PLLSRC    : 1;
            uint32_t PLLXTPRE  : 1;
            uint32_t PLLMUL    : 4;
            uint32_t USBPRE    : 1;
            uint32_t Reserved1 : 1;
            uint32_t MCO       : 4;
            uint32_t Reserved2 : 4;
        } BITS;
    } CFGR;
    
    union {
        uint32_t REG;
        struct {
            uint32_t LSIRDYF   : 1;
            uint32_t LSERDYF   : 1;
            uint32_t HSIRDYF   : 1;
            uint32_t HSERDYF   : 1;
            uint32_t PLLRDYF   : 1;
			uint32_t PLL2RDYF	 : 1;
			uint32_t PLL3RDYF	 : 1;
            uint32_t CSSF      : 1;
            uint32_t LSIRDYIE  : 1;
            uint32_t LSERDYIE  : 1;
            uint32_t HSIRDYIE  : 1;
            uint32_t HSERDYIE  : 1;
            uint32_t PLLRDYIE  : 1;
			uint32_t PLL2RDYIE  : 1;
			uint32_t PLL3RDYIE  : 1;
            uint32_t Reserved2 : 1;
            uint32_t LSIRDYC   : 1;
            uint32_t LSERDYC   : 1;
            uint32_t HSIRDYC   : 1;
            uint32_t HSERDYC   : 1;
            uint32_t PLLRDYC   : 1;
			uint32_t PLL2RDYC   : 1;
			uint32_t PLL3RDYC   : 1;
            uint32_t CSSC      : 1;
            uint32_t Reserved4 : 8;
        } BITS;
    } CIR;
    
    union {
        uint32_t REG;
        struct {
            uint32_t AFIORST   : 1;
            uint32_t Reserved1 : 1;
            uint32_t IOPARST   : 1;
            uint32_t IOPBRST   : 1;
            uint32_t IOPCRST   : 1;
            uint32_t IOPDRST   : 1;
            uint32_t IOPERST   : 1;
            uint32_t Reserved2 : 2;
            uint32_t ADC1RST   : 1;
            uint32_t ADC2RST   : 1;
            uint32_t TIM1RST   : 1;
            uint32_t SPI1RST   : 1;
            uint32_t Reserved3 : 1;
            uint32_t USART1RST : 1;
            uint32_t Reserved4 : 17;
        } BITS;
    } APB2RSTR;
		
		union {
        uint32_t REG;
        struct {
            uint32_t TIM2RST  : 1;
            uint32_t TIM3RST  : 1;
            uint32_t TIM4RST  : 1;
            uint32_t TIM5RST  : 1;
            uint32_t TIM6RST  : 1;
            uint32_t TIM7RST  : 1;
            uint32_t Reserved1: 5;
            uint32_t WWDGRST  : 1;
            uint32_t Reserved2: 2;
            uint32_t SPI2RST  : 1;
            uint32_t SPI3RST  : 1;
            uint32_t Reserved3: 1;
            uint32_t USART2RST: 1;
            uint32_t USART3RST: 1;
            uint32_t UART4RST : 1;
            uint32_t UART5RST : 1;
            uint32_t I2C1RST  : 1;
            uint32_t I2C2RST  : 1;
            uint32_t Reserved4: 2;
            uint32_t CAN1RST  : 1;
            uint32_t CAN2RST  : 1;
            uint32_t BKPRST   : 1;
            uint32_t PWRRST   : 1;
            uint32_t DACRST   : 1;
            uint32_t Reserved5: 2;
        } BITS;
    } APB1RSTR;
    union {
			uint32_t REG;
			struct {
				uint32_t DMA1EN   : 1;
				uint32_t DMA2EN   : 1;
				uint32_t SRAMEN   : 1;
				uint32_t Reserved1: 1;
				uint32_t FLITFEN  : 1;
				uint32_t Reserved2: 1;
				uint32_t CRCEN    : 1;
				uint32_t Reserved3: 1;
				uint32_t FSMCEN   : 1;
				uint32_t Reserved4: 1;
				uint32_t SDIOEN   : 1;
				uint32_t Reserved5: 21;
			} BITS;
		} RCC_AHBENR;
		
	union {
        uint32_t REG;
        struct {
            uint32_t AFIOEN    : 1;
            uint32_t Reserved1 : 1;
            uint32_t IOPAEN    : 1;
            uint32_t IOPBEN    : 1;
            uint32_t IOPCEN    : 1;
            uint32_t IOPDEN    : 1;
            uint32_t IOPEEN    : 1;
			uint32_t IOPFEN    : 1;
            uint32_t IOPGEN    : 1;
            uint32_t ADC1EN    : 1;
            uint32_t ADC2EN    : 1;
            uint32_t TIM1EN    : 1;
            uint32_t SPI1EN    : 1;
            uint32_t TIM8EN    : 1;
            uint32_t USART1EN  : 1;
            uint32_t ADC3EN    : 1;
            uint32_t Reserved3 : 3;
			uint32_t TIM9EN    : 1;
			uint32_t TIM10EN   : 1;
			uint32_t TIM11EN   : 1;
			uint32_t Reserved4 : 10;
        } BITS;
    } APB2ENR;
		
    union {
        uint32_t REG;
        struct {
            uint32_t TIM2EN    : 1;
            uint32_t TIM3EN    : 1;
            uint32_t TIM4EN    : 1;
            uint32_t TIM5EN    : 1;
            uint32_t TIM6EN    : 1;
            uint32_t TIM7EN    : 1;
			uint32_t TIM12EN    : 1;
			uint32_t TIM13EN    : 1;
			uint32_t TIM14EN    : 1;
            uint32_t Reserved1 : 2;
            uint32_t WWDGEN    : 1;
            uint32_t Reserved2 : 2;
            uint32_t SPI2EN    : 1;
            uint32_t SPI3EN    : 1;
            uint32_t Reserved3 : 1;
            uint32_t USART2EN  : 1;
            uint32_t USART3EN  : 1;
            uint32_t UART4EN   : 1;
            uint32_t UART5EN   : 1;
            uint32_t I2C1EN    : 1;
            uint32_t I2C2EN    : 1;
            uint32_t USBEN     : 1;
            uint32_t Reserved4 : 1;
			uint32_t CANEN : 1;
			uint32_t Reserved5 : 1;
			uint32_t BKPEN : 1;
			uint32_t PWREN : 1;
			uint32_t DACEN : 1;
			uint32_t Reserved6 : 2;
        } BITS;
    } APB1ENR;
		
    union {
    uint32_t REG;
    struct {
    		uint32_t LSEON     : 1;
    		uint32_t LSERDY    : 1;
    		uint32_t LSEBYP    : 1;
    		uint32_t Reserved1 : 5;
    		uint32_t RTCSEL    : 2;
    		uint32_t Reserved2 : 5;
    		uint32_t RTCEN     : 1;
    		uint32_t BDRST     : 1;
    		uint32_t Reserved3 : 15;
    } BITS;
    } RCC_BDCR;
    
		union {
			uint32_t REG;
			struct {
				uint32_t LSION     : 1;
				uint32_t LSIRDY    : 1;
				uint32_t Reserved1 : 22;
				uint32_t RMVF      : 1;
				uint32_t Reserved2 : 1;
				uint32_t PINRSTF   : 1;
				uint32_t PORRSTF   : 1;
				uint32_t SFTRSTF   : 1;
				uint32_t IWDGRSTF  : 1;
				uint32_t WWDGRSTF  : 1;
				uint32_t LPWRRSTF  : 1;
			} BITS;
		} RCC_CSR;
    
} RCC_TypeDef;


typedef union{
		uint32_t REG;
		struct{
			uint32_t LATENCY : 3;
			uint32_t HLFCYA  : 1;
			uint32_t PRFTBE  : 1;
			uint32_t PRFTBS  : 1;
			uint32_t Reserved  : 26;
		}BITS;
}FLASH_ACR;	

//---------------------------------------ADDREGS-----------------------------------------------

#define ADDREGS_RCC         0x40021000UL
#define ADDREGS_FLASH_ACR   0x40022000UL


//---------------------------------------VARIABLE-----------------------------------------------

#define RCC      				((volatile RCC_TypeDef*) ADDREGS_RCC)
#define ACR       			((volatile FLASH_ACR*) ADDREGS_FLASH_ACR)

//-----------------------------------------API--------------------------------------------------

// Max fre = 72Mhz
void RCC_Config_72Mhz();
void RCC_Enable_PortA();
void RCC_Enable_PortB();
void RCC_Enable_PortC();

#endif