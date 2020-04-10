#include "bsp_adc.h"

/*
===========================
全局变量定义
=========================== 
*/

//定义并初始化
BSP_ADC1 bsp_adc_init={
	.channel={
		CONFIG_BSP_ADC1_CHANNEL_0,
		CONFIG_BSP_ADC1_CHANNEL_1,
		CONFIG_BSP_ADC1_CHANNEL_2,
		CONFIG_BSP_ADC1_CHANNEL_3,
		CONFIG_BSP_ADC1_CHANNEL_4,
		CONFIG_BSP_ADC1_CHANNEL_5,
		CONFIG_BSP_ADC1_CHANNEL_6,
		CONFIG_BSP_ADC1_CHANNEL_7,
	},
	.width_t={
		CONFIG_BSP_ADC1_BIT_WIDTH_T_0,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_1,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_2,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_3,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_4,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_5,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_6,
		CONFIG_BSP_ADC1_BIT_WIDTH_T_7,
	},
	.atten={
		CONFIG_BSP_ADC1_ATTEN_T_0,
		CONFIG_BSP_ADC1_ATTEN_T_1,
		CONFIG_BSP_ADC1_ATTEN_T_2,
		CONFIG_BSP_ADC1_ATTEN_T_3,
		CONFIG_BSP_ADC1_ATTEN_T_4,
		CONFIG_BSP_ADC1_ATTEN_T_5,
		CONFIG_BSP_ADC1_ATTEN_T_6,
		CONFIG_BSP_ADC1_ATTEN_T_7,
	},
	.raw={0,}
};
/*
===========================
函数定义
=========================== 
*/

void ADC1_INIT(void)
{
	for (int i = 0; i < 8; ++i)
	{
		//调试
		if(ADCDebug)
		{
			printf("[ADCDebug]:%d\n",bsp_adc_init.channel[i]);
			vTaskDelay(ADCDebugDelay/portTICK_PERIOD_MS);
		}
		if(bsp_adc_init.channel[i] != -1)
		{
			adc1_config_width(bsp_adc_init.width_t[i]);
			adc1_config_channel_atten(bsp_adc_init.channel[i],bsp_adc_init.atten[i]);
		}
	}
}

void adc1task(void * pvParameters)
{
    while(1)
    {
		for (int i = 0,j = 0; i < 8; ++i)
		{
			if(bsp_adc_init.channel[i] != -1)
			{
				bsp_adc_init.raw[i] = adc1_get_raw(bsp_adc_init.channel[i]);
				//数据对齐易分析
				if(ADCDebug)
			        for (int n = 0; n < j; n++)
			        {
			        	printf("\t");
			        	printf("\t");
			        	printf("\t");
			        	printf("\t");
			        }
				printf("The adc1 channel %d value:%d\n",bsp_adc_init.channel[i],bsp_adc_init.raw[i]);
		        vTaskDelay(1000/portTICK_PERIOD_MS);
		        ++j;
			}
		}
    }
}

