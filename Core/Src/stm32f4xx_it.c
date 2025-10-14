#include "main.h"
#include "stm32f4xx_it.h"

extern volatile uint8_t adc_data_ready;

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
