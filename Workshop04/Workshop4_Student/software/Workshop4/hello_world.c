#include "system.h"
#include "io.h"
#include "nios2_ctrl_reg_macros.h"

int val = 0;
int main()
{
	// ----===========================----
	//        STUDENT CODE HERE
	// ----===========================----

	// TODO 1: Turn on interrupts for the entire nios processor

	// TODO 2: Turn on the specific IRQ line for the keys [IRQ2]

	// TODO 3: Set the interrupt mask for the KEY PIO

	// TODO 4: Clear the edge capture register of the PIO to be safe

	// Increment value on the red LEDs.
	// YOU SHOULD NOT NEED TO EDIT CODE BELOW HERE.
	while (1) {

		// If value turns on all 10 bits, reset it
		if (++val > 1024) {
			val = 0;
		}

		// Set the PIO value
		IOWR(LEDR_BASE, 0, val);

		// Delay for a while to make LED increment readable.
		for (int i = 0; i < 10000; i++) {
			asm("nop");
		}
	}

    return 0;
}


