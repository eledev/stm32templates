#include "init.h"

void init(void){
    RCC_DeInit();
    RCC_HSEConfig(RCC_HSE_ON);
    if(RCC_WaitForHSEStartUp() == SUCCESS){
        RCC_PLLConfig(RCC_PLLSource_HSE, PLLM_VALUE, PLLN_VALUE, PLLP_VALUE, PLLQ_VALUE);
        RCC_PLLCmd(ENABLE);
        while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET){
        } 
        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        RCC_PCLK1Config(RCC_HCLK_Div2);
        RCC_PCLK2Config(RCC_HCLK_Div1);   
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
//        SystemCoreClockUpdate();
    }


    

}