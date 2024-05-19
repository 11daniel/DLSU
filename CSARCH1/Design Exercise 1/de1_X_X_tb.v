module TestBench();

  reg W, X, Y, Z;

  wire A, B, C, D, E, F, G;

  DE1  DUT1(A, B, C, D, E, F, G, W, X, Y, Z);

  initial begin
    W = 0;
    X = 0;
    Y = 0;
    Z = 0;
	
	$display("Group #X"); // Write your group number here

    #15
    $display("ABCDEFG = %b%b%b%b%b%b%b", A,B,C,D,E,F,G); //Correct answer is 1111110
	#15
	
	W = 0;
    X = 1;
    Y = 0;
    Z = 0;

    #10
    $display("ABCDEFG = %b%b%b%b%b%b%b", A,B,C,D,E,F,G); //Correct answer is 0110000
	#10
	
	W = 1;
    X = 0;
    Y = 0;
    Z = 0;
	
	#10
    $display("ABCDEFG = %b%b%b%b%b%b%b", A,B,C,D,E,F,G); // Correct answer is 1101101
	$finish;

  end
endmodule
