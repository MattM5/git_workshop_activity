module top_level (
	input CLOCK_50,
	input [1:0] KEY,
	
	output [9:0] LEDR,
	
	output [7:0] HEX0,
	output [7:0] HEX1,
	output [7:0] HEX2,
	output [7:0] HEX3,
	output [7:0] HEX4,
	output [7:0] HEX5
);
	
	
    nios_system u0 (
        .clk_clk       (CLOCK_50),       //    clk.clk
        .reset_reset_n (KEY[0]), //  reset.reset_n
        .hex3_5_export ({HEX5, HEX4, HEX3}), // hex3_5.export
        .hex0_2_export ({HEX2, HEX1, HEX0}), // hex0_2.export
        .key_export    (KEY[1]),     //    key.export
		  .ledr_export (LEDR)
    );

	 
endmodule
