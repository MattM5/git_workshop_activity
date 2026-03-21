module top_level (
	/* Add your inputs here */
	
	// Clock
	input CLOCK_50,
		
	// Keys
	input [0:0] KEY,
		
	// Leds
	output [9:0] LEDR,
	
	// Switches
	input [9:0] SW
	
);

    nios_system u0 (
        .clk_clk       (CLOCK_50),       
        .reset_reset_n (KEY[0]), 
        .ledr_export   (LEDR),   
        .sw_export     (SW)      
    );

	 
endmodule