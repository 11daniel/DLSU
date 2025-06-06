/**
 * This is an autogenerated netlist code from CircuitVerse. Verilog Code can be
 * tested on https://www.edaplayground.com/ using Icarus Verilog 0.9.7. This is an
 * experimental module and some manual changes make need to be done in order for
 * this to work.
 *
 * If you have any ideas/suggestions or bug fixes, raise an issue
 * on https://github.com/CircuitVerse/CircuitVerse/issues/new/choose
 */

/*
  Element Usage Report
    Input - 55 times
    Decoder - 19 times
    Multiplexer - 1 times
    OrGate - 40 times
    DigitalLed - 14 times
    AndGate - 75 times
    Output - 17 times
    NotGate - 30 times
    SubCircuit - 31 times
    NandGate - 6 times
*/

/*
  Usage Instructions and Tips
    Labels - Ensure unique label names and avoid using verilog keywords
    Warnings - Connect all optional inputs to remove warnings
*/

// Sample Testbench Code - Uncomment to use

/*
module TestBench();

  reg [2:0] D2, D6, D3, D4, D1, D5, inp_6;

  wire P6, P1, P2, P3, P4, P5;

  main DUT0(D2, D6, D3, D4, D1, D5, inp_6);

  try DUT1(D2, D6, D3, D4, D1, D5);

  another_try_x2 DUT2(P6, P1, P2, P3, P4, P5, D2, D1, D4, D3, D6, D5);

  initial begin
    D2 = 0;
    D6 = 0;
    D3 = 0;
    D4 = 0;
    D1 = 0;
    D5 = 0;
    inp_6 = 0;

    #15
    $display("P6 = %b", P6);
    $display("P1 = %b", P1);
    $display("P2 = %b", P2);
    $display("P3 = %b", P3);
    $display("P4 = %b", P4);
    $display("P5 = %b", P5);

    #10
    $display("P6 = %b", P6);
    $display("P1 = %b", P1);
    $display("P2 = %b", P2);
    $display("P3 = %b", P3);
    $display("P4 = %b", P4);
    $display("P5 = %b", P5);

    $finish;

  end
endmodule

*/

module main(D2, D6, D3, D4, D1, D5, inp_6);
  input [2:0] D2, D6, D3, D4, D1, D5, inp_6;
  wire Decoder_6_out_0, Decoder_6_out_1, Decoder_6_out_2, Decoder_6_out_3, Decoder_6_out_4, Decoder_6_out_5, Decoder_6_out_6, Decoder_6_out_7, Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, or_1_out, or_2_out, or_3_out, or_4_out, or_5_out, or_6_out, or_7_out, or_8_out, \6_out , \5_out , \4_out , \3_out , \2_out , \1_out , Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, or_0_out, Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_6, Decoder_3_out_7, Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7;
  Decoder8 #() Decoder_6(Decoder_6_out_0, Decoder_6_out_1, Decoder_6_out_2, Decoder_6_out_3, Decoder_6_out_4, Decoder_6_out_5, Decoder_6_out_6, Decoder_6_out_7, inp_6);
  Multiplexer8 Multiplexer_0(, Decoder_6_out_0, Decoder_6_out_1, Decoder_6_out_2, Decoder_6_out_3, Decoder_6_out_4, Decoder_6_out_5, Decoder_6_out_6, Decoder_6_out_7, );
  Decoder8 #() Decoder_4(Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, D5);
  assign or_1_out = Decoder_3_out_0 | Decoder_3_out_7 | Decoder_4_out_0 | Decoder_4_out_7 | Decoder_5_out_0 | Decoder_5_out_7;
  assign or_2_out = or_0_out | or_1_out;
  assign or_3_out = \1_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P1=%d", or_3_out);
  assign or_4_out = \2_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P2=%d", or_4_out);
  assign or_5_out = \3_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P3=%d", or_5_out);
  assign or_6_out = \4_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P4=%d", or_6_out);
  assign or_7_out = \5_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P5=%d", or_7_out);
  assign or_8_out = \6_out  | or_2_out;
  
      always @ (*)
        $display("DigitalLed:P6=%d", or_8_out);
  assign \6_out  = Decoder_2_out_6 & Decoder_0_out_6 & Decoder_1_out_6 & Decoder_3_out_7 & Decoder_4_out_6 & Decoder_5_out_6;
  assign \5_out  = Decoder_2_out_5 & Decoder_0_out_5 & Decoder_1_out_5 & Decoder_3_out_5 & Decoder_4_out_5 & Decoder_5_out_5;
  assign \4_out  = Decoder_2_out_4 & Decoder_0_out_4 & Decoder_1_out_4 & Decoder_3_out_4 & Decoder_4_out_4 & Decoder_5_out_4;
  assign \3_out  = Decoder_2_out_3 & Decoder_0_out_3 & Decoder_1_out_3 & Decoder_3_out_3 & Decoder_4_out_3 & Decoder_5_out_3;
  assign \2_out  = Decoder_2_out_2 & Decoder_0_out_2 & Decoder_1_out_2 & Decoder_3_out_2 & Decoder_4_out_2 & Decoder_5_out_2;
  assign \1_out  = Decoder_2_out_1 & Decoder_0_out_1 & Decoder_1_out_1 & Decoder_3_out_1 & Decoder_4_out_1 & Decoder_5_out_1;
  Decoder8 #() Decoder_1(Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, D1);
  assign or_0_out = Decoder_1_out_0 | Decoder_1_out_7 | Decoder_0_out_0 | Decoder_0_out_7 | Decoder_2_out_0 | Decoder_2_out_7;
  Decoder8 #() Decoder_3(Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_7, Decoder_3_out_7, D4);
  Decoder8 #() Decoder_2(Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, D3);
  Decoder8 #() Decoder_5(Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, D6);
  Decoder8 #() Decoder_0(Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7, D2);
endmodule

module \1_INPUT_CHECKER (out_0, D1, D2, D3, D4, D5, D6);
  output out_0;
  input D1, D2, D3, D4, D5, D6;
  wire D6_out, or_0_out, not_5_out, and_5_out, and_4_out, D3_out, D4_out, D5_out, not_4_out, not_3_out, not_2_out, not_1_out, not_0_out;
  assign D6_out = not_2_out & not_1_out & not_0_out & not_3_out & not_4_out & D6;
  assign or_0_out = D6_out | D5_out | D4_out | D3_out | and_4_out | and_5_out;
  assign out_0 = or_0_out;
  
      always @ (*)
        $display("DigitalLed:or_0_out=%d", or_0_out);
  assign not_5_out = ~D6;
  assign and_5_out = not_2_out & not_1_out & D1 & not_3_out & not_4_out & not_5_out;
  assign and_4_out = not_2_out & D2 & not_0_out & not_3_out & not_4_out & not_5_out;
  assign D3_out = D3 & not_1_out & not_0_out & not_3_out & not_4_out & not_5_out;
  assign D4_out = not_2_out & not_1_out & not_0_out & D4 & not_4_out & not_5_out;
  assign D5_out = not_2_out & not_1_out & not_0_out & not_3_out & D5 & not_5_out;
  assign not_4_out = ~D5;
  assign not_3_out = ~D4;
  assign not_2_out = ~D3;
  assign not_1_out = ~D2;
  assign not_0_out = ~D1;
endmodule

module \2_INPUT_CHECKER (out_0, D1, D2, D3, D4, D5, D6);
  output out_0;
  input D1, D2, D3, D4, D5, D6;
  wire \D1,_D6_out , or_3_out, or_2_out, \D3,_D6_out , or_1_out, \D2,_D6_out , \D4,_D6_out , or_0_out, \D5,_D6_out , not_5_out, \D1,_D4_out , \D1,_D5_out , \D2,_D4_out , \D2,_D5_out , \D3,_D4_out , \D3,_D5_out , \D1,_D2_out , \D1,_D3_out , \D2,_D3_out , \D4,_D5_out , not_4_out, not_3_out, not_2_out, not_1_out, not_0_out;
  assign \D1,_D6_out  = not_2_out & not_1_out & D1 & not_3_out & not_4_out & D6;
  assign or_3_out = \D1,_D6_out  | \D1,_D5_out  | \D1,_D4_out ;
  assign or_2_out = or_0_out | or_1_out | or_3_out;
  assign out_0 = or_2_out;
  
      always @ (*)
        $display("DigitalLed:or_2_out=%d", or_2_out);
  assign \D3,_D6_out  = D3 & not_1_out & not_0_out & not_3_out & not_4_out & D6;
  assign or_1_out = \D2,_D6_out  | \D3,_D5_out  | \D3,_D4_out  | \D3,_D6_out  | \D2,_D5_out  | \D2,_D4_out ;
  assign \D2,_D6_out  = not_2_out & D2 & not_0_out & not_3_out & not_4_out & D6;
  assign \D4,_D6_out  = not_2_out & not_1_out & not_0_out & D4 & not_4_out & D6;
  assign or_0_out = \D5,_D6_out  | \D4,_D6_out  | \D4,_D5_out  | \D2,_D3_out  | \D1,_D3_out  | \D1,_D2_out ;
  assign \D5,_D6_out  = not_2_out & not_1_out & not_0_out & not_3_out & D5 & D6;
  assign not_5_out = ~D6;
  assign \D1,_D4_out  = not_2_out & not_1_out & D1 & D4 & not_4_out & not_5_out;
  assign \D1,_D5_out  = not_2_out & not_1_out & D1 & not_3_out & D5 & not_5_out;
  assign \D2,_D4_out  = not_2_out & D2 & not_0_out & D4 & not_4_out & not_5_out;
  assign \D2,_D5_out  = not_2_out & D2 & not_0_out & not_3_out & D5 & not_5_out;
  assign \D3,_D4_out  = D3 & not_1_out & not_0_out & D4 & not_4_out & not_5_out;
  assign \D3,_D5_out  = D3 & not_1_out & not_0_out & not_3_out & D5 & not_5_out;
  assign \D1,_D2_out  = not_2_out & D2 & D1 & not_3_out & not_4_out & not_5_out;
  assign \D1,_D3_out  = D3 & not_1_out & D1 & not_3_out & not_4_out & not_5_out;
  assign \D2,_D3_out  = D3 & D2 & not_0_out & not_3_out & not_4_out & not_5_out;
  assign \D4,_D5_out  = not_2_out & not_1_out & not_0_out & D4 & D5 & not_5_out;
  assign not_4_out = ~D5;
  assign not_3_out = ~D4;
  assign not_2_out = ~D3;
  assign not_1_out = ~D2;
  assign not_0_out = ~D1;
endmodule

module PRIZE_3_CHECKER(out_0, D1, D2, D3, D4, D5, D6);
  output out_0;
  input D1, D2, D3, D4, D5, D6;
  wire \D1,_D4,_D6_out , or_3_out, or_4_out, \D1,_D5,_D6_out , \D1,_D3,_D6_out , or_2_out, \D1,_D2,_D6_out , \D2,_D4,_D6_out , \D2,_D5,_D6_out , or_1_out, \D2,_D3,_D6_out , \D3,_D4,D6_out , or_0_out, \D3,_D5,_D6_out , \D4,_D5,_D6_out , not_5_out, \D1,_D4,_D5_out , \D1,_D3,_D4_out , \D1,_D3,_D5_out , \D1,_D2,_D4_out , \D1,_D2,_D5_out , \D2,_D4,_D5_out , \D2,_D3,_D4_out , \D2,_D3,_D5_out , \D3,_D4,D5_out , \D1,_D2,_D3_out , not_4_out, not_3_out, not_2_out, not_1_out, not_0_out;
  assign \D1,_D4,_D6_out  = not_2_out & not_1_out & D1 & D4 & not_4_out & D6;
  assign or_3_out = \D1,_D3,_D5_out  | \D1,_D3,_D4_out  | \D1,_D5,_D6_out  | \D1,_D4,_D5_out  | \D1,_D4,_D6_out ;
  assign or_4_out = or_0_out | or_1_out | or_2_out | or_3_out;
  assign out_0 = or_4_out;
  
      always @ (*)
        $display("DigitalLed:or_4_out=%d", or_4_out);
  assign \D1,_D5,_D6_out  = not_2_out & not_1_out & D1 & not_3_out & D5 & D6;
  assign \D1,_D3,_D6_out  = D3 & not_1_out & D1 & not_3_out & not_4_out & D6;
  assign or_2_out = \D2,_D4,_D6_out  | \D1,_D2,_D6_out  | \D1,_D2,_D5_out  | \D1,_D2,_D4_out  | \D1,_D3,_D6_out ;
  assign \D1,_D2,_D6_out  = not_2_out & D2 & D1 & not_3_out & not_4_out & D6;
  assign \D2,_D4,_D6_out  = not_2_out & D2 & not_0_out & D4 & not_4_out & D6;
  assign \D2,_D5,_D6_out  = not_2_out & D2 & not_0_out & not_3_out & D5 & D6;
  assign or_1_out = \D2,_D3,_D6_out  | \D2,_D3,_D5_out  | \D2,_D3,_D4_out  | \D2,_D5,_D6_out  | \D2,_D4,_D5_out ;
  assign \D2,_D3,_D6_out  = D3 & D2 & not_0_out & not_3_out & not_4_out & D6;
  assign \D3,_D4,D6_out  = D3 & not_1_out & not_0_out & D4 & not_4_out & D6;
  assign or_0_out = \D1,_D2,_D3_out  | \D4,_D5,_D6_out  | \D3,_D5,_D6_out  | \D3,_D4,D5_out  | \D3,_D4,D6_out ;
  assign \D3,_D5,_D6_out  = D3 & not_1_out & not_0_out & not_3_out & D5 & D6;
  assign \D4,_D5,_D6_out  = not_2_out & not_1_out & not_0_out & D4 & D5 & D6;
  assign not_5_out = ~D6;
  assign \D1,_D4,_D5_out  = not_2_out & not_1_out & D1 & D4 & D5 & not_5_out;
  assign \D1,_D3,_D4_out  = D3 & not_1_out & D1 & D4 & not_4_out & not_5_out;
  assign \D1,_D3,_D5_out  = D3 & not_1_out & D1 & not_3_out & D5 & not_5_out;
  assign \D1,_D2,_D4_out  = not_2_out & D2 & D1 & D4 & not_4_out & not_5_out;
  assign \D1,_D2,_D5_out  = not_2_out & D2 & D1 & not_3_out & D5 & not_5_out;
  assign \D2,_D4,_D5_out  = not_2_out & D2 & not_0_out & D4 & D5 & not_5_out;
  assign \D2,_D3,_D4_out  = D3 & D2 & not_0_out & D4 & not_4_out & not_5_out;
  assign \D2,_D3,_D5_out  = D3 & D2 & not_0_out & not_3_out & D5 & not_5_out;
  assign \D3,_D4,D5_out  = D3 & not_1_out & not_0_out & D4 & D5 & not_5_out;
  assign \D1,_D2,_D3_out  = D3 & D2 & D1 & not_3_out & not_4_out & not_5_out;
  assign not_4_out = ~D5;
  assign not_3_out = ~D4;
  assign not_2_out = ~D3;
  assign not_1_out = ~D2;
  assign not_0_out = ~D1;
endmodule




module try(D2, D6, D3, D4, D1, D5);
  input [2:0] D2, D6, D3, D4, D1, D5;
  wire Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, PRIZE_3_CHECKER_2_out, \2_INPUT_CHECKER_1_out , \1_INPUT_CHECKER_0_out , \1_out , Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_6, Decoder_3_out_7, Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7;
  Decoder8 #() Decoder_4(Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, D5);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_2(PRIZE_3_CHECKER_2_out, Decoder_4_out_4, Decoder_0_out_4, Decoder_1_out_4, Decoder_5_out_4, Decoder_2_out_4, Decoder_3_out_4);
  
      always @ (*)
        $display("DigitalLed:PRIZE_3_CHECKER_2_out=%d", PRIZE_3_CHECKER_2_out);
  \2_INPUT_CHECKER  \2_INPUT_CHECKER_1 (\2_INPUT_CHECKER_1_out , Decoder_5_out_4, Decoder_1_out_4, Decoder_0_out_4, Decoder_2_out_4, Decoder_3_out_4, Decoder_4_out_4);
  
      always @ (*)
        $display("DigitalLed:\2_INPUT_CHECKER_1_out =%d", \2_INPUT_CHECKER_1_out );
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_0 (\1_INPUT_CHECKER_0_out , Decoder_1_out_4, Decoder_0_out_4, Decoder_2_out_4, Decoder_3_out_4, Decoder_4_out_4, Decoder_5_out_4);
  
      always @ (*)
        $display("DigitalLed:\1_INPUT_CHECKER_0_out =%d", \1_INPUT_CHECKER_0_out );
  \1_INPUT_CHECKER  \1 (\1_out , Decoder_1_out_1, Decoder_0_out_1, Decoder_2_out_1, Decoder_3_out_1, Decoder_4_out_1, Decoder_5_out_1);
  Decoder8 #() Decoder_1(Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, D1);
  Decoder8 #() Decoder_3(Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_7, Decoder_3_out_7, D4);
  Decoder8 #() Decoder_2(Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, D3);
  Decoder8 #() Decoder_5(Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, D6);
  Decoder8 #() Decoder_0(Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7, D2);
endmodule

module \4_INPUT_CHECKER (out_0, D1, D2, D3, D4, D5, D6);
  output out_0;
  input D1, D2, D3, D4, D5, D6;
  wire \D1,_D2,_D3,_D6_out , or_3_out, or_1_out, \D1,_D2,_D4,_D6_out , or_2_out, \D1,_D2,_D5,_D6_out , \D1,_D3,_D4,_D6_out , \D1,_D3,_D5,_D6_out , \D1,_D4,_D5,_D6_out , or_0_out, \D2,_D3,_D4,_D6_out , \D2,_D3,_D5,_D6_out , \D2,_D4,_D5,_D6_out , \D3,_D4,_D5,_D6_out , not_5_out, \D1,_D2,_D3,_D4_out , \D1,_D2,_D3,_D5_out , \D1,_D2,_D4,_D5_out , \D1,_D3,_D4,_D5_out , \D2,_D3,_D4,_D5_out , not_4_out, not_3_out, not_2_out, not_1_out, not_0_out;
  assign \D1,_D2,_D3,_D6_out  = D3 & D2 & D1 & not_3_out & not_4_out & D6;
  assign or_3_out = \D1,_D2,_D3,_D6_out  | \D1,_D2,_D3,_D5_out  | \D1,_D2,_D3,_D4_out ;
  assign or_1_out = or_0_out | or_2_out | or_3_out;
  assign out_0 = or_1_out;
  
      always @ (*)
        $display("DigitalLed:or_1_out=%d", or_1_out);
  assign \D1,_D2,_D4,_D6_out  = not_2_out & D2 & D1 & D4 & not_4_out & D6;
  assign or_2_out = \D1,_D3,_D5,_D6_out  | \D1,_D3,_D4,_D6_out  | \D1,_D3,_D4,_D5_out  | \D1,_D2,_D5,_D6_out  | \D1,_D2,_D4,_D6_out  | \D1,_D2,_D4,_D5_out ;
  assign \D1,_D2,_D5,_D6_out  = not_2_out & D2 & D1 & not_3_out & D5 & D6;
  assign \D1,_D3,_D4,_D6_out  = D3 & not_1_out & D1 & D4 & not_4_out & D6;
  assign \D1,_D3,_D5,_D6_out  = D3 & not_1_out & D1 & not_3_out & D5 & D6;
  assign \D1,_D4,_D5,_D6_out  = not_2_out & not_1_out & D1 & D4 & D5 & D6;
  assign or_0_out = \D3,_D4,_D5,_D6_out  | \D2,_D4,_D5,_D6_out  | \D2,_D3,_D5,_D6_out  | \D2,_D3,_D4,_D6_out  | \D2,_D3,_D4,_D5_out  | \D1,_D4,_D5,_D6_out ;
  assign \D2,_D3,_D4,_D6_out  = D3 & D2 & not_0_out & D4 & not_4_out & D6;
  assign \D2,_D3,_D5,_D6_out  = D3 & D2 & not_0_out & not_3_out & D5 & D6;
  assign \D2,_D4,_D5,_D6_out  = not_2_out & D2 & not_0_out & D4 & D5 & D6;
  assign \D3,_D4,_D5,_D6_out  = D3 & not_1_out & not_0_out & D4 & D5 & D6;
  assign not_5_out = ~D6;
  assign \D1,_D2,_D3,_D4_out  = D3 & D2 & D1 & D4 & not_4_out & not_5_out;
  assign \D1,_D2,_D3,_D5_out  = D3 & D2 & D1 & not_3_out & D5 & not_5_out;
  assign \D1,_D2,_D4,_D5_out  = not_2_out & D2 & D1 & D4 & D5 & not_5_out;
  assign \D1,_D3,_D4,_D5_out  = D3 & not_1_out & D1 & D4 & D5 & not_5_out;
  assign \D2,_D3,_D4,_D5_out  = D3 & D2 & not_0_out & D4 & D5 & not_5_out;
  assign not_4_out = ~D5;
  assign not_3_out = ~D4;
  assign not_2_out = ~D3;
  assign not_1_out = ~D2;
  assign not_0_out = ~D1;
endmodule

module \5_INPUT_CHECKER (out_0, D1, D2, D3, D4, D5, D6);
  output out_0;
  input D1, D2, D3, D4, D5, D6;
  wire \D1,_D2,_D3,_D4,_D6_out , or_0_out, \D1,_D2,_D3,_D5,_D6_out , \D1,_D2,_D4,_D5,_D6_out , \D1,_D3,_D4,_D5,_D6_out , \D2,_D3,_D4,_D5,_D6_out , not_5_out, \D1,_D2,_D3,_D4,_D5_out , not_4_out, not_3_out, not_2_out, not_1_out, not_0_out;
  assign \D1,_D2,_D3,_D4,_D6_out  = D3 & D2 & D1 & D4 & not_4_out & D6;
  assign or_0_out = \D2,_D3,_D4,_D5,_D6_out  | \D1,_D3,_D4,_D5,_D6_out  | \D1,_D2,_D4,_D5,_D6_out  | \D1,_D2,_D3,_D5,_D6_out  | \D1,_D2,_D3,_D4,_D6_out  | \D1,_D2,_D3,_D4,_D5_out ;
  assign out_0 = or_0_out;
  
      always @ (*)
        $display("DigitalLed:or_0_out=%d", or_0_out);
  assign \D1,_D2,_D3,_D5,_D6_out  = D3 & D2 & D1 & not_3_out & D5 & D6;
  assign \D1,_D2,_D4,_D5,_D6_out  = not_2_out & D2 & D1 & D4 & D5 & D6;
  assign \D1,_D3,_D4,_D5,_D6_out  = D3 & not_1_out & D1 & D4 & D5 & D6;
  assign \D2,_D3,_D4,_D5,_D6_out  = D3 & D2 & not_0_out & D4 & D5 & D6;
  assign not_5_out = ~D6;
  assign \D1,_D2,_D3,_D4,_D5_out  = D3 & D2 & D1 & D4 & D5 & not_5_out;
  assign not_4_out = ~D5;
  assign not_3_out = ~D4;
  assign not_2_out = ~D3;
  assign not_1_out = ~D2;
  assign not_0_out = ~D1;
endmodule

module PRIORITY_ENCODER(out_0, out_1, out_2, out_3, out_4, out_5, inp_0, inp_1, inp_2, inp_3, inp_4, inp_5);
  output out_0,  out_1,  out_2,  out_3,  out_4,  out_5;
  input inp_0, inp_1, inp_2, inp_3, inp_4, inp_5;
  wire and_5_out, nand_5_out, or_3_out, and_4_out, nand_4_out, and_3_out, nand_3_out, or_2_out, and_2_out, nand_2_out, or_1_out, or_0_out, and_1_out, nand_1_out, nand_0_out, and_0_out;
  assign and_5_out = nand_5_out & inp_5;
  assign out_5 = and_5_out;
  assign nand_5_out = ~(or_3_out & inp_5);
  assign or_3_out = or_2_out | inp_4;
  assign and_4_out = nand_4_out & inp_4;
  assign out_4 = and_4_out;
  assign nand_4_out = ~(or_2_out & inp_4);
  assign and_3_out = nand_3_out & inp_3;
  assign out_3 = and_3_out;
  assign nand_3_out = ~(or_1_out & inp_3);
  assign or_2_out = or_1_out | inp_3;
  assign and_2_out = nand_2_out & inp_2;
  assign out_2 = and_2_out;
  assign nand_2_out = ~(or_0_out & inp_2);
  assign or_1_out = or_0_out | inp_2;
  assign or_0_out = inp_0 | inp_1;
  assign and_1_out = nand_1_out & inp_1;
  assign out_1 = and_1_out;
  assign nand_1_out = ~(inp_0 & inp_1);
  assign nand_0_out = ~( & inp_0);
  assign and_0_out = nand_0_out & inp_0;
  assign out_0 = and_0_out;
endmodule







module BoBingScoring(D1,D2,D3,D4,D5,D6,P1,P2,P3,P4,P5,P6);
  output P1,  P2,  P3,  P4,  P5,  P6;
  input [2:0] D1, D2, D3, D4, D5, D6;
  wire Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, or_4_out, or_5_out, or_11_out, or_10_out, or_9_out, or_8_out, or_7_out, or_6_out, \5_INPUT_CHECKER_24_out , or_2_out, PRIORITY_ENCODER_26_out_0, PRIORITY_ENCODER_26_out_1, PRIORITY_ENCODER_26_out_2, PRIORITY_ENCODER_26_out_3, PRIORITY_ENCODER_26_out_4, PRIORITY_ENCODER_26_out_5, \4_INPUT_CHECKER_23_out , or_1_out, PRIZE_3_CHECKER_10_out, \2_INPUT_CHECKER_25_out , or_0_out, \1_INPUT_CHECKER_9_out , and_0_out, \5_INPUT_CHECKER_22_out , \4_INPUT_CHECKER_21_out , PRIZE_3_CHECKER_8_out, \1_INPUT_CHECKER_7_out , \5_INPUT_CHECKER_20_out , \4_INPUT_CHECKER_19_out , PRIZE_3_CHECKER_11_out, \2_INPUT_CHECKER_6_out , \1_INPUT_CHECKER_5_out , \4_INPUT_CHECKER_17_out , \5_INPUT_CHECKER_18_out , PRIZE_3_CHECKER_4_out, \1_INPUT_CHECKER_3_out , \5_INPUT_CHECKER_16_out , \4_INPUT_CHECKER_14_out , PRIZE_3_CHECKER_15_out, \1_INPUT_CHECKER_1_out , \5_INPUT_CHECKER_13_out , \4_INPUT_CHECKER_12_out , PRIZE_3_CHECKER_2_out, \1_INPUT_CHECKER_0_out , Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_6, Decoder_3_out_7, or_3_out, Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7;
  Decoder8 #() Decoder_5(Decoder_5_out_0, Decoder_5_out_1, Decoder_5_out_2, Decoder_5_out_3, Decoder_5_out_4, Decoder_5_out_5, Decoder_5_out_6, Decoder_5_out_7, D5);
  assign or_4_out = Decoder_2_out_0 | Decoder_2_out_7 | Decoder_5_out_0 | Decoder_5_out_7 | Decoder_4_out_0 | Decoder_4_out_7;
  assign or_5_out = or_3_out | or_4_out;
  assign or_11_out = or_5_out | PRIORITY_ENCODER_26_out_5;
  assign P6 = or_11_out;
  assign or_10_out = or_5_out | PRIORITY_ENCODER_26_out_4;
  assign P4 = or_10_out;
  assign or_9_out = or_5_out | PRIORITY_ENCODER_26_out_3;
  assign P5 = or_9_out;
  assign or_8_out = or_5_out | PRIORITY_ENCODER_26_out_2;
  assign P3 = or_8_out;
  assign or_7_out = or_5_out | PRIORITY_ENCODER_26_out_1;
  assign P2 = or_7_out;
  assign or_6_out = or_5_out | PRIORITY_ENCODER_26_out_0;
  assign P1 = or_6_out;
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_24 (\5_INPUT_CHECKER_24_out , Decoder_1_out_6, Decoder_0_out_6, Decoder_3_out_6, Decoder_2_out_6, Decoder_5_out_6, Decoder_4_out_6);
  assign or_2_out = \5_INPUT_CHECKER_13_out  | \5_INPUT_CHECKER_16_out  | \5_INPUT_CHECKER_18_out  | \5_INPUT_CHECKER_20_out  | \4_INPUT_CHECKER_19_out  | \5_INPUT_CHECKER_22_out  | \5_INPUT_CHECKER_24_out ;
  PRIORITY_ENCODER PRIORITY_ENCODER_26(PRIORITY_ENCODER_26_out_0, PRIORITY_ENCODER_26_out_1, PRIORITY_ENCODER_26_out_2, PRIORITY_ENCODER_26_out_3, PRIORITY_ENCODER_26_out_4, PRIORITY_ENCODER_26_out_5, or_2_out, or_0_out, PRIZE_3_CHECKER_11_out, or_1_out, \2_INPUT_CHECKER_6_out , \1_INPUT_CHECKER_5_out );
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_23 (\4_INPUT_CHECKER_23_out , Decoder_1_out_6, Decoder_0_out_6, Decoder_3_out_6, Decoder_2_out_6, Decoder_5_out_6, Decoder_4_out_6);
  assign or_1_out = \4_INPUT_CHECKER_12_out  | \4_INPUT_CHECKER_14_out  | \4_INPUT_CHECKER_17_out  | \4_INPUT_CHECKER_19_out  | \4_INPUT_CHECKER_21_out  | \4_INPUT_CHECKER_23_out ;
  PRIZE_3_CHECKER PRIZE_3_CHECKER_10(PRIZE_3_CHECKER_10_out, Decoder_1_out_6, Decoder_0_out_6, Decoder_3_out_6, Decoder_2_out_6, Decoder_5_out_6, Decoder_4_out_6);
  \2_INPUT_CHECKER  \2_INPUT_CHECKER_25 (\2_INPUT_CHECKER_25_out , PRIZE_3_CHECKER_2_out, PRIZE_3_CHECKER_15_out, PRIZE_3_CHECKER_4_out, PRIZE_3_CHECKER_11_out, PRIZE_3_CHECKER_8_out, PRIZE_3_CHECKER_10_out);
  assign or_0_out = \2_INPUT_CHECKER_25_out  | and_0_out;
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_9 (\1_INPUT_CHECKER_9_out , Decoder_1_out_6, Decoder_0_out_6, Decoder_3_out_6, Decoder_2_out_6, Decoder_5_out_6, Decoder_4_out_6);
  assign and_0_out = \1_INPUT_CHECKER_3_out  & \1_INPUT_CHECKER_1_out  & \1_INPUT_CHECKER_0_out  & \1_INPUT_CHECKER_5_out  & \1_INPUT_CHECKER_7_out  & \1_INPUT_CHECKER_9_out ;
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_22 (\5_INPUT_CHECKER_22_out , Decoder_1_out_5, Decoder_0_out_5, Decoder_3_out_5, Decoder_2_out_5, Decoder_5_out_5, Decoder_4_out_5);
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_21 (\4_INPUT_CHECKER_21_out , Decoder_1_out_5, Decoder_0_out_5, Decoder_3_out_5, Decoder_2_out_5, Decoder_4_out_5, Decoder_5_out_5);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_8(PRIZE_3_CHECKER_8_out, Decoder_1_out_5, Decoder_0_out_5, Decoder_3_out_5, Decoder_2_out_5, Decoder_5_out_5, Decoder_4_out_5);
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_7 (\1_INPUT_CHECKER_7_out , Decoder_1_out_5, Decoder_0_out_5, Decoder_3_out_5, Decoder_2_out_5, Decoder_5_out_5, Decoder_4_out_5);
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_20 (\5_INPUT_CHECKER_20_out , Decoder_1_out_4, Decoder_0_out_4, Decoder_3_out_4, Decoder_2_out_4, Decoder_5_out_4, Decoder_4_out_4);
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_19 (\4_INPUT_CHECKER_19_out , Decoder_1_out_4, Decoder_0_out_4, Decoder_3_out_4, Decoder_2_out_4, Decoder_5_out_4, Decoder_4_out_4);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_11(PRIZE_3_CHECKER_11_out, Decoder_1_out_4, Decoder_0_out_4, Decoder_3_out_4, Decoder_2_out_4, Decoder_5_out_4, Decoder_4_out_4);
  \2_INPUT_CHECKER  \2_INPUT_CHECKER_6 (\2_INPUT_CHECKER_6_out , Decoder_1_out_4, Decoder_0_out_4, Decoder_3_out_4, Decoder_2_out_4, Decoder_5_out_4, Decoder_4_out_4);
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_5 (\1_INPUT_CHECKER_5_out , Decoder_1_out_4, Decoder_0_out_4, Decoder_3_out_4, Decoder_2_out_4, Decoder_5_out_4, Decoder_4_out_4);
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_17 (\4_INPUT_CHECKER_17_out , Decoder_1_out_3, Decoder_0_out_3, Decoder_3_out_3, Decoder_2_out_3, Decoder_5_out_3, Decoder_4_out_3);
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_18 (\5_INPUT_CHECKER_18_out , Decoder_1_out_3, Decoder_0_out_3, Decoder_3_out_3, Decoder_4_out_3, Decoder_5_out_3, Decoder_2_out_3);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_4(PRIZE_3_CHECKER_4_out, Decoder_1_out_3, Decoder_0_out_3, Decoder_3_out_3, Decoder_2_out_3, Decoder_5_out_3, Decoder_4_out_3);
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_3 (\1_INPUT_CHECKER_3_out , Decoder_1_out_3, Decoder_0_out_3, Decoder_3_out_3, Decoder_2_out_3, Decoder_5_out_3, Decoder_4_out_3);
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_16 (\5_INPUT_CHECKER_16_out , Decoder_1_out_2, Decoder_0_out_2, Decoder_3_out_2, Decoder_2_out_2, Decoder_5_out_2, Decoder_4_out_2);
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_14 (\4_INPUT_CHECKER_14_out , Decoder_1_out_2, Decoder_0_out_2, Decoder_3_out_2, Decoder_2_out_2, Decoder_4_out_2, Decoder_5_out_2);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_15(PRIZE_3_CHECKER_15_out, Decoder_1_out_2, Decoder_0_out_2, Decoder_3_out_2, Decoder_2_out_2, Decoder_5_out_2, Decoder_4_out_2);
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_1 (\1_INPUT_CHECKER_1_out , Decoder_1_out_2, Decoder_0_out_2, Decoder_3_out_2, Decoder_2_out_2, Decoder_5_out_2, Decoder_4_out_2);
  \5_INPUT_CHECKER  \5_INPUT_CHECKER_13 (\5_INPUT_CHECKER_13_out , Decoder_1_out_1, Decoder_0_out_1, Decoder_3_out_1, Decoder_2_out_1, Decoder_5_out_1, Decoder_4_out_1);
  \4_INPUT_CHECKER  \4_INPUT_CHECKER_12 (\4_INPUT_CHECKER_12_out , Decoder_1_out_1, Decoder_0_out_1, Decoder_3_out_1, Decoder_2_out_1, Decoder_5_out_1, Decoder_4_out_1);
  PRIZE_3_CHECKER PRIZE_3_CHECKER_2(PRIZE_3_CHECKER_2_out, Decoder_1_out_1, Decoder_0_out_1, Decoder_3_out_1, Decoder_2_out_1, Decoder_5_out_1, Decoder_4_out_1);
  \1_INPUT_CHECKER  \1_INPUT_CHECKER_0 (\1_INPUT_CHECKER_0_out , Decoder_1_out_1, Decoder_0_out_1, Decoder_3_out_1, Decoder_2_out_1, Decoder_5_out_1, Decoder_4_out_1);
  Decoder8 #() Decoder_4(Decoder_4_out_0, Decoder_4_out_1, Decoder_4_out_2, Decoder_4_out_3, Decoder_4_out_4, Decoder_4_out_5, Decoder_4_out_6, Decoder_4_out_7, D6);
  Decoder8 #() Decoder_3(Decoder_3_out_0, Decoder_3_out_1, Decoder_3_out_2, Decoder_3_out_3, Decoder_3_out_4, Decoder_3_out_5, Decoder_3_out_6, Decoder_3_out_7, D3);
  assign or_3_out = Decoder_1_out_0 | Decoder_1_out_7 | Decoder_0_out_0 | Decoder_0_out_7 | Decoder_3_out_0 | Decoder_3_out_7;
  Decoder8 #() Decoder_2(Decoder_2_out_0, Decoder_2_out_1, Decoder_2_out_2, Decoder_2_out_3, Decoder_2_out_4, Decoder_2_out_5, Decoder_2_out_6, Decoder_2_out_7, D4);
  Decoder8 #() Decoder_1(Decoder_1_out_0, Decoder_1_out_1, Decoder_1_out_2, Decoder_1_out_3, Decoder_1_out_4, Decoder_1_out_5, Decoder_1_out_6, Decoder_1_out_7, D1);
  Decoder8 #() Decoder_0(Decoder_0_out_0, Decoder_0_out_1, Decoder_0_out_2, Decoder_0_out_3, Decoder_0_out_4, Decoder_0_out_5, Decoder_0_out_6, Decoder_0_out_7, D2);
endmodule

module Decoder8(out0, out1, out2, out3, out4, out5, out6, out7, sel);
  output reg out0, out1, out2, out3, out4, out5, out6, out7;
  input [2:0] sel;
  
  always @ (*) begin
    out0 = 0;
    out1 = 0;
    out2 = 0;
    out3 = 0;
    out4 = 0;
    out5 = 0;
    out6 = 0;
    out7 = 0;
    case (sel)
      0 : out0 = 1;
      1 : out1 = 1;
      2 : out2 = 1;
      3 : out3 = 1;
      4 : out4 = 1;
      5 : out5 = 1;
      6 : out6 = 1;
      7 : out7 = 1;
    endcase
  end
endmodule

module Multiplexer8(out, in0, in1, in2, in3, in4, in5, in6, in7, sel);
  parameter WIDTH = 1;
  output reg [WIDTH-1:0] out;
  input [WIDTH-1:0] in0, in1, in2, in3, in4, in5, in6, in7;
  input [2:0] sel;
  
  always @ (*)
    case (sel)
      0 : out = in0;
      1 : out = in1;
      2 : out = in2;
      3 : out = in3;
      4 : out = in4;
      5 : out = in5;
      6 : out = in6;
      7 : out = in7;
    endcase
endmodule

