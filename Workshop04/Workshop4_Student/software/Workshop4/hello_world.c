#include "system.h"
#include "io.h"
#include "nios2_ctrl_reg_macros.h"

int val = 0;
int main()
{
	// ----===========================----
	//        STUDENT CODE HERE - if set up correctly expection handler should be called
	// ----===========================----

	// TODO 1: Turn on interrupts for the entire nios processor
	int current_status;
	NIOS2_READ_STATUS(current_status);
	NIOS2_WRITE_STATUS(current_status | 0x1);
	// TODO 2: Turn on the specific IRQ line for the keys [IRQ2]
	NIOS2_WRITE_IENABLE(0x4); // 0x4 = 100 enabling irq2 bit
	// TODO 3: Set the interrupt mask for the KEY PIO
	IOWR(KEY_BASE, 2, 0x1); // - see system.h file
	// TODO 4: Clear the edge capture register of the PIO to be safe
	IOWR(KEY_BASE, 3, 0x0);

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
			asm("nop"); // do nothing
		}
	}

    return 0;
}


