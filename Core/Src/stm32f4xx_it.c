#include "main.h"
#include "stm32f4xx_it.h"

extern volatile uint8_t adc_data_ready;
extern volatile uint16_t injected_adc_buffer;
extern volatile uint8_t injected_adc_data_ready;

void NMI_Handler(void)
{
  while (1)
  {

  }
}

void HardFault_Handler(void)
{
  while (1)
  {

  }
}

void MemManage_Handler(void)
{
  while (1)
  {

  }
}

void BusFault_Handler(void)
{
  while (1)
  {

  }
}

void UsageFault_Handler(void)
{
  while (1)
  {

  }
}

void SVC_Handler(void)
{

}

void DebugMon_Handler(void)
{

}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{

}

void DMA2_Stream0_IRQHandler(void)
{
	if (LL_DMA_IsActiveFlag_TC0(DMA2))
	{
		LL_DMA_ClearFlag_TC0(DMA2);

		adc_data_ready = 1;
	}
}

void ADC_IRQHandler(void)
{
	if (LL_ADC_IsActiveFlag_JEOS(ADC1))
	{
		LL_ADC_ClearFlag_JEOS(ADC1);

		injected_adc_buffer = LL_ADC_INJ_ReadConversionData12(ADC1, LL_ADC_INJ_RANK_1);
		injected_adc_data_ready = 1;
	}
}
