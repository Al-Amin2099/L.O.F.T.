#include <stdint.h>

#define PERIPHERAL_BASE     (0x40000000U)
#define AHB1_BASE           (PERIPHERAL_BASE + 0x20000U)
#define GPIOA_BASE          (AHB1_BASE + 0x0U)
#define RCC_BASE            (AHB1_BASE + 0x3800U)

#define RCC_AHB1ENR         ((volatile uint32_t*)(RCC_BASE + 0x30U))
#define GPIOA_MODER         ((volatile uint32_t*)(GPIOA_BASE + 0x00U))
#define GPIOA_ODR           ((volatile uint32_t*)(GPIOA_BASE + 0x14U))

#define LED_PIN 5

void main(void)
{
    /* Enable GPIOA clock */
    *RCC_AHB1ENR |= (1 << 0);

    /* Two dummy reads after enabling clock (F446 errata) */
    volatile uint32_t dummy;
    dummy = *RCC_AHB1ENR;
    dummy = *RCC_AHB1ENR;
    (void)dummy;

    /* Set PA5 as general purpose output (MODER bits [11:10] = 01) */
    *GPIOA_MODER &= ~(3U << (LED_PIN * 2));
    *GPIOA_MODER |=  (1U << (LED_PIN * 2));

    while(1)
    {
        *GPIOA_ODR ^= (1 << LED_PIN);
        for (volatile uint32_t i = 0; i < 1000000; i++);
    }
}
