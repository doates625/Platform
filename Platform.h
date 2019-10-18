/**
 * @file Platform.h
 * @brief Embedded system header for Arduino and Mbed projects
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This file is meant to replace <Arduino.h> and <mbed.h> in libraries which
 * span across both platforms. Instead of putting conditional includes in every
 * file, instead include this file with the following build flag options:
 * 
 * Embedded platform:
 * - PLATFORM_ARDUINO (Arduino platform)
 * - PLATFORM_MBED (Mbed platform)
 * 
 * Board operating voltage:
 * - PLATFORM_5V (5V boards)
 * - PLATFORM_3V3 (3.3V boards)
 * 
 * If both or neither is included for each option, this header throws an error
 * at compile time. This file also includes functions for global interrupt 
 * control, software delays, and a platform-specific pintype_t for use in multi-
 * platform libraries.
 * 
 * Additionally, when the Arduino platform is used, this file undefines some of
 * their bad macro functions such as min and max.
 */
#pragma once
#include <stdint.h>

/**
 * Platform Macro
 */
#if defined(PLATFORM_ARDUINO) && defined(PLATFORM_MBED)
	#error Cannot define both PLATFORM_ARDUINO and PLATFORM_MBED
#elif defined(PLATFORM_ARDUINO)
	#include <Arduino.h>
	#ifdef abs
		#undef abs
	#endif
	#ifdef min
		#undef min
	#endif
	#ifdef max
		#undef max
	#endif
#elif defined(PLATFORM_MBED)
	#include <mbed.h>
#else
	#error Must define PLATFORM_ARDUINO or PLATFORM_MBED
#endif

/**
 * Supply Voltage Macro
 */
#if defined(PLATFORM_5V) && defined(PLATFORM_3V3)
	#error Cannot define both PLATFORM_5V and PLATFORM_3V3
#elif !defined(PLATFORM_5V) && !defined(PLATFORM_3V3)
	#error Must define PLATFORM_5V or PLATFORM_3V3
#endif

/**
 * Namespace Declaration
 */
namespace Platform
{
	// Pin Type Definition
#if defined(PLATFORM_ARDUINO)
	typedef uint8_t pin_t;
#elif defined(PLATFORM_MBED)
	typedef PinName pin_t;
#endif

	// Operating Voltage
	extern const float vcc;

	// Methods
	void enable_interrupts();
	void disable_interrupts();
	void wait_ms(uint32_t ms);
	void wait_us(uint32_t us);
}