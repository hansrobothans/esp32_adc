克隆下来之后一定要使用make menuconfig命令选择打开adc通道
代码逻辑
1.通过make menuconfig选择打开adc通道
	未打开通道值为-1，打开通道则输入通道数。
	例如需要打开通道3,则在make menuconfig->ADC1 Configration->ADC1 Channel 3 (GPIO 39/SN)中填入3
	需要打开通道5,则在make menuconfig->ADC1 Configration->ADC1 Channel 5 (GPIO 33)中填入5
2.调用ADC1_INIT()函数进行初始化
	ADC1_INIT()函数会根据第一步设置进行判断初始化相应的通道
3.创建任务，进行打印adc通道采集到的值，并存放在bsp_adc_init结构体变量成员raw数组中，数组下标对应通道
