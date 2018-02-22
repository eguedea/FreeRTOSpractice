/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    tareaRTOS.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "FreeRTOS.h"
#include "task.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
#define FUNCTION_STACK_SIZE 100
#define TASK1_PRIORITY 1
#define TASK2_PRIORITY 2
#define TASK3_PRIORITY 3

/*
 * @brief   Application entry point.
 */
void dummy_task1(void)
{
	uint8_t counter = 0;
	for (;;)
	{
		printf("IN TASK 1: %i +++++++++++++++\r\n", counter);
		counter++;
		vTaskDelay( 2000 );

	}
}

void dummy_task2(void)
{
	uint8_t counter = 0;
	for (;;)
	{
		printf("IN TASK 2: %i ***************\r\n", counter);
		counter++;
		vTaskDelay( 1000 );

	}
}

void dummy_task3(void)
{
	uint8_t counter = 0;
	for (;;)
	{
		printf("IN TASK 3: %i ---------------\r\n", counter);
		counter++;
		vTaskDelay( 4000 );

	}
}

int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    printf("Hello World\n");
    TaskHandle_t xHandle;
    xTaskCreate(dummy_task1,"Tarea 1",FUNCTION_STACK_SIZE,NULL,TASK1_PRIORITY,&xHandle);
    xTaskCreate(dummy_task2,"Tarea 2",FUNCTION_STACK_SIZE,NULL,TASK2_PRIORITY,&xHandle);
    xTaskCreate(dummy_task3,"Tarea 3",FUNCTION_STACK_SIZE,NULL,TASK3_PRIORITY,&xHandle);
    vTaskStartScheduler( );
    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
    }
    return 0 ;
}
