#include "dma.h"

void DMA_Init(uint32_t buffer_adress, uint32_t buffer_size)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA2);

	LL_DMA_InitTypeDef DMA_InitStruct = {
			.Channel = LL_DMA_CHANNEL_0,
			.Direction = LL_DMA_DIRECTION_PERIPH_TO_MEMORY,
			.FIFOMode = LL_DMA_FIFOMODE_DISABLE,
			.MemBurst = LL_DMA_MBURST_SINGLE,
			.MemoryOrM2MDstAddress = buffer_adress,
			.MemoryOrM2MDstDataSize = LL_DMA_MDATAALIGN_HALFWORD,
			.MemoryOrM2MDstIncMode = LL_DMA_MEMORY_INCREMENT,
			.Mode = LL_DMA_MODE_CIRCULAR,
			.NbData = buffer_size,
			.PeriphBurst = LL_DMA_PBURST_SINGLE,
			.PeriphOrM2MSrcAddress = (uint32_t)&ADC1->DR,
			.PeriphOrM2MSrcDataSize = LL_DMA_PDATAALIGN_HALFWORD,
			.PeriphOrM2MSrcIncMode = LL_DMA_PERIPH_NOINCREMENT,
			.Priority = LL_DMA_PRIORITY_LOW
	};
	LL_DMA_Init(DMA2, LL_DMA_STREAM_0, &DMA_InitStruct);
	LL_DMA_EnableStream(DMA2, LL_DMA_STREAM_0);

	LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_0);
	NVIC_SetPriority(DMA2_Stream0_IRQn, 0);
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}
