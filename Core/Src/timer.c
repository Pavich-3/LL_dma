#include "timer.h"

void TIMER_Init(LL_TIM_InitTypeDef* TIM_InitStruct)
{
	TIM_InitStruct->Autoreload = 24999;
	TIM_InitStruct->ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
	TIM_InitStruct->CounterMode = LL_TIM_COUNTERMODE_UP;
	TIM_InitStruct->Prescaler = 1;
	TIM_InitStruct->RepetitionCounter = 0;
	LL_TIM_Init(TIM1, TIM_InitStruct);

	LL_TIM_SetTriggerOutput(TIM1, LL_TIM_TRGO_UPDATE);

    LL_TIM_EnableCounter(TIM1);
    LL_TIM_EnableAllOutputs(TIM1);
}
