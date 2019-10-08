/**
 * @file Platform.h
 * @brief Embedded system header for Arduino and Mbed projects.
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This file is meant to replace <Arduino.h> and <mbed.h> in
 * libraries which span across both platforms. Instead of
 * putting conditional includes in every file, instead include
 * this file with one of the following build flags:
 * 
 * - PLATFORM_ARDUINO
 * - PLATFORM_MBED
 * 
 * If both or neither is included, this header throws an error
 * at compile time. When the Arduino platform is used, this 
 * file also undefines some of their bad macro functions.
 */
#pragma once

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