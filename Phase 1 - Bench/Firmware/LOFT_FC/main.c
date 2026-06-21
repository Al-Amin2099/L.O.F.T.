`#include <stdint.h>

#define PERIPHERAL_BASE		(0x4000000U)
#define AHB1_BASE		(PERIPHERAL_BASE + 0x20000U)
#define GPIOA_BASE		(AHB1_BASE + 0x0U)
#define RCC_BASE		(AHB1_BASE +0x3800U)

#define RC_AHB1ENR		((volatile uint32_t*)(RCC_BASE + 0x30U))
#define GPIOA_MODER		((volatile unit32_t*)(GPIO_BASE + 0x00U))
#define GPIO_ODR		((volatile unit32_t*)(GPIO_BASE + 0x14U))


/* IMU Module Function	
 *
 */

/* Barometer Module Function
 *
 */

/* Magnetometer Module Function
 *
 */

/* GPS Module Function 
 *
 */

void main(void)
{
	return 0;
}
