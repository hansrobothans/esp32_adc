#ifndef BSP_ADC_H
#define BSP_ADC_H "BSP_ADC_H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"
#include "driver/adc.h"

typedef struct _BSP_ADC1
{
    adc_channel_t channel[8];
    adc_bits_width_t width_t[8];
    adc_atten_t atten[8];
    int raw[8];
}BSP_ADC1;

extern BSP_ADC1 bsp_adc_init;
/*
===========================
宏定义
=========================== 
*/
//1开启调试;0关闭调试
#define ADCDebug 1 // for Debug
// if(ADCDebug)printf("[ADCDebug]:\n");
//调试延时时间
#define ADCDebugDelay 100

void ADC1_INIT(void);
void adc1task(void * pvParameters);


#endif//BSP_ADC_H