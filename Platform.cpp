/**
 * @brief Platform.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include <Platform.h>

/**
 * @brief Global interrupt enable
 */
void Platform::enable_interrupts()
{
#if defined(PLATFORM_ARDUINO)
	interrupts();
#elif defined(PLATFORM_MBED)
	__enable_irq();
#endif
}

/**
 * @brief Global interrupt disable
 */
void Platform::disable_interrupts()
{
#if defined(PLATFORM_ARDUINO)
	noInterrupts();
#elif defined(PLATFORM_MBED)
	__disable_irq();
#endif
}

/**
 * @brief Millisecond software delay
 * @param ms Time to wait [ms]
 */
void Platform::wait_ms(uint32_t ms)
{
#if defined(PLATFORM_ARDUINO)
	delay(ms);
#elif defined(PLATFORM_MBED)
	::wait_ms(ms);
#endif
}

/**
 * @brief Microsecond software delay
 * @param us Time to wait [us]
 */
void Platform::wait_us(uint32_t us)
{
#if defined(PLATFORM_ARDUINO)
	delayMicroseconds(us);
#elif defined(PLATFORM_MBED)
	::wait_us(us);
#endif
}