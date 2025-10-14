#include "gpio.h"

void GPIO_Init(void)
{
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

	LL_GPIO_InitTypeDef GPIO_InitStruct = {
			.Mode = LL_GPIO_MODE_ANALOG,
			.Pin = LL_GPIO_PIN_0 | LL_GPIO_PIN_1,
			.Pull = LL_GPIO_PULL_NO,
			.Speed = LL_GPIO_SPEED_FREQ_HIGH
	};
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
