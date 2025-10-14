#include "adc.h"

void ADC_Init(void)
{
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);

	LL_ADC_InitTypeDef ADC_InitStruct = {
			.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT,
			.Resolution = LL_ADC_RESOLUTION_12B,
			.SequencersScanMode = LL_ADC_SEQ_SCAN_ENABLE
	};
	LL_ADC_Init(ADC1, &ADC_InitStruct);

	LL_ADC_REG_InitTypeDef REG_InitStruct = {
			.ContinuousMode = LL_ADC_REG_CONV_CONTINUOUS,
			.DMATransfer = LL_ADC_REG_DMA_TRANSFER_UNLIMITED,
			.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE,
			.SequencerLength = LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS,
			.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE
	};
	LL_ADC_REG_Init(ADC1, &REG_InitStruct);

	LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_0, LL_ADC_SAMPLINGTIME_112CYCLES);
	LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_0);

	LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_1, LL_ADC_SAMPLINGTIME_112CYCLES);
	LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_1);

	LL_ADC_Enable(ADC1);
}
