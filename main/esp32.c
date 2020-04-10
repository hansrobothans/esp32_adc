#include "bsp_adc.h"


void app_main()
{
    //adc初始化
    ADC1_INIT();
    // 创建任务打印测试值
    xTaskCreate(
        &adc1task,      /* 任务函数 */
        "adc1task",     /* 任务名称 */
        1024*3,         /* 任务的堆栈大小 */
        NULL,       /* 任务的参数 */
        10,             /* 任务的优先级 */
        NULL);          /* 跟踪创建的任务的任务句柄 */
}