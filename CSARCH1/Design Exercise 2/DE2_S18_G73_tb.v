`timescale 1ns / 1ps

module BoBingScoring_tb;

    // Parameters
    parameter CLK_PERIOD = 10;  // Clock period in nanoseconds

    // Signals
    reg [2:0] D1, D2, D3, D4, D5, D6;  // Input signals for dice values
    wire P1, P2, P3, P4, P5, P6;           // Output signals for prizes

    // Instantiate the module
    BoBingScoring uut (
        .D1(D1),
        .D2(D2),
        .D3(D3),
        .D4(D4),
        .D5(D5),
        .D6(D6),
        .P1(P1),
        .P2(P2),
        .P3(P3),
        .P4(P4),
        .P5(P5),
        .P6(P6)
    );

    // Clock generation
    reg clk = 0;
    always #((CLK_PERIOD)/2) clk = ~clk;

    // Test stimuli
    initial begin
        // Reset inputs
        $dumpfile("DE2_GTK.vcd");
        $dumpvars(0, BoBingScoring_tb);
        
        //INVALID INPUTS
        $display("Project by Group #73");
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Invalid (0 and/or 7 on any dice input): ");
        D1 = 3'b111; D2 = 3'b100; D3 = 3'b100; D4 = 3'b100; D5 = 0; D6 = 0;                 //111 
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b000; D2 = 3'b100; D3 = 3'b100; D4 = 3'b100; D5 = 0; D6 = 0;                 //000 
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);


        //PRIZE 1
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Prize 1 (4 four-face or 5 of any number): ");
        D1 = 3'b100; D2 = 3'b100; D3 = 3'b100; D4 = 3'b100; D5 = 3'b010; D6 = 3'b010;            // 4-Four face
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b001; D2 = 3'b001; D3 = 3'b001; D4 = 3'b001; D5 = 3'b001; D6 = 3'b010;            // 5-One face
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b010; D2 = 3'b001; D3 = 3'b001; D4 = 3'b001; D5 = 3'b001; D6 = 3'b001;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b010; D2 = 3'b010; D3 = 3'b010; D4 = 3'b010; D5 = 3'b010; D6 = 3'b001;            // 5-Two face
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b010; D4 = 3'b010; D5 = 3'b010; D6 = 3'b010;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b011; D2 = 3'b011; D3 = 3'b011; D4 = 3'b011; D5 = 3'b011; D6 = 3'b010;            // 5-Three face
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b010; D2 = 3'b011; D3 = 3'b011; D4 = 3'b011; D5 = 3'b011; D6 = 3'b011;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b101; D2 = 3'b101; D3 = 3'b101; D4 = 3'b101; D5 = 3'b101; D6 = 3'b010;            // 5-Fives
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b010; D2 = 3'b101; D3 = 3'b101; D4 = 3'b101; D5 = 3'b101; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b110; D2 = 3'b110; D3 = 3'b110; D4 = 3'b110; D5 = 3'b110; D6 = 3'b010;            // 5-Sixes
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b010; D2 = 3'b110; D3 = 3'b110; D4 = 3'b110; D5 = 3'b110; D6 = 3'b110;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        

        //PRIZE 2
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Prize 2 (all numbers or 3 of the same number and 3 of another same number): ");
        
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b100; D5 = 3'b101; D6 = 3'b110;           
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b110; D2 = 3'b101; D3 = 3'b100; D4 = 3'b011; D5 = 3'b010; D6 = 3'b001;           
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);

        D1 = 3'b001; D2 = 3'b001; D3 = 3'b001; D4 = 3'b010; D5 = 3'b010; D6 = 3'b010;         
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b011; D2 = 3'b011; D3 = 3'b011; D4 = 3'b100; D5 = 3'b100; D6 = 3'b100;           
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b101; D2 = 3'b101; D3 = 3'b101; D4 = 3'b110; D5 = 3'b110; D6 = 3'b110;           
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);


        //PRIZE 3
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Prize 3 (3-Four face, any # for the rest): ");
        D1 = 3'b100; D2 = 3'b100; D3 = 3'b100; D4 = 3'b001; D5 = 3'b010; D6 = 3'b011;      
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b100; D3 = 3'b100; D4 = 3'b100; D5 = 3'b010; D6 = 3'b011;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b100; D4 = 3'b100; D5 = 3'b100; D6 = 3'b011;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6); 
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b100; D5 = 3'b100; D6 = 3'b100;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);


        //PRIZE 4
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Prize 4 (4 of the same number other than 4): ");
        D1 = 3'b001; D2 = 3'b001; D3 = 3'b001; D4 = 3'b001; D5 = 3'b010; D6 = 3'b011;    
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b010; D2 = 3'b010; D3 = 3'b010; D4 = 3'b010; D5 = 3'b011; D6 = 3'b100;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b011; D2 = 3'b011; D3 = 3'b011; D4 = 3'b011; D5 = 3'b100; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6); 
        D1 = 3'b101; D2 = 3'b101; D3 = 3'b101; D4 = 3'b101; D5 = 3'b110; D6 = 3'b110;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b110; D2 = 3'b110; D3 = 3'b110; D4 = 3'b110; D5 = 3'b001; D6 = 3'b001;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);


        //PRIZE 5
        $display("--------------------------------------------------------------------------------------------------------");
        $display("PRIZE 5 (2-Four Face, any # for the rest): ");
        D1 = 3'b100; D2 = 3'b100; D3 = 3'b001; D4 = 3'b010; D5 = 3'b011; D6 = 3'b101;  
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b100; D3 = 3'b100; D4 = 3'b010; D5 = 3'b011; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b100; D4 = 3'b100; D5 = 3'b011; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6); 
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b100; D5 = 3'b100; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b101; D5 = 3'b100; D6 = 3'b100;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);


        //PRIZE 6
        $display("--------------------------------------------------------------------------------------------------------");
        $display("PRIZE 6 (1-Four Face, any # for the rest): "); 
        D1 = 3'b100; D2 = 3'b001; D3 = 3'b010; D4 = 3'b011; D5 = 3'b101; D6 = 3'b101;           
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b100; D3 = 3'b010; D4 = 3'b011; D5 = 3'b101; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b100; D4 = 3'b011; D5 = 3'b011; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6); 
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b100; D5 = 3'b101; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6); 
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b101; D5 = 3'b100; D6 = 3'b101;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        D1 = 3'b001; D2 = 3'b010; D3 = 3'b011; D4 = 3'b101; D5 = 3'b101; D6 = 3'b100;
        #5;
        $display("P = %b%b%b%b%b%b", P1,P2,P3,P4,P5,P6);
        $display("--------------------------------------------------------------------------------------------------------");
        $display("Project by Group #73");
        $finish;
    end

endmodule
