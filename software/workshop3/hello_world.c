/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>

#include "io.h"
#include "system.h"

int main()
{

//  int *leds = LEDR_BASE; // points to the LEDS, we can use it to read and write to LEDS
//
//  *leds = 0x3FF; // switch on all leds

	while (1){

		int value = IORD(SW_BASE,0); // reading from switches using the io.h library

		IOWR(LEDR_BASE, 0, value); // 0 in each here is the memory offset
	}


  return 0;
}
