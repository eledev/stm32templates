#include "main.h"


int main(void) {
	assert_param(1>3);
    while(1) {	

    }
}


#ifdef  USE_FULL_ASSERT
/* 	assert_param(bool) */
void assert_failed(uint8_t* file, uint32_t line){
}
#endif
