#include "main.h"
#include "gpio.h"
#include "adc.h"
#include "dma.h"
#include "timer.h"

volatile uint8_t adc_data_ready = 0;
volatile uint16_t adc_buffer[2] = {0, 0};
volatile uint16_t injected_adc_buffer = 0;
volatile uint8_t injected_adc_data_ready = 0;
LL_TIM_InitTypeDef TIM_InitStruct = {0};

void SystemClock_Config(void);

int main(void)
{
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

  GPIO_Init();
  ADC_Init();
  DMA_Init((uint32_t)adc_buffer, 2);
  TIMER_Init(&TIM_InitStruct);

  while (1)
  {
	  if (adc_data_ready)
	  {
		  adc_data_ready = 0;

          printf("ADC data: Channel 0 = %u, Channel 1 = %u\r\n", adc_buffer[0], adc_buffer[1]);
	  }
	  if (injected_adc_data_ready)
	  {
		  injected_adc_data_ready = 0;
		  printf("Injected ADC data: Channel 3 = %u\r\n", injected_adc_buffer);

	  }
  }
}

void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_HSE_EnableCSS();
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSE);

  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSE)
  {

  }
  LL_Init1msTick(25000000);
  LL_SetSystemCoreClock(25000000);
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {

  }
}
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif
