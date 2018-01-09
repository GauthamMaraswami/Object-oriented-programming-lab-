`timescale 1ns/10ps

module t_Example;
wire [3:0] A_par;
reg [3:0] I_par;
reg s1,s0,MSB_in,LSB_in,CLK,Clear_b;
Example E1(A_par,I_par,s1,s0,MSB_in,LSB_in,CLK,Clear_b);




initial
begin
$dumpfile("Example.vcd");
$dumpvars(0,t_Example);
s1=1'b1;
s0=1'b1;
end

initial
begin
s1=1'b1;
repeat(7)
#100 s1=~s1;
end

initial
begin
s0=1'b1;
repeat(14)
#50 s0=~s0;
end

initial
begin
CLK=1'b0;
repeat(100)
#10 CLK=~CLK;
end

initial
begin
Clear_b=1'b1;
repeat(4)
#100 Clear_b=~Clear_b;
end

initial
begin
MSB_in=1'b1;
LSB_in=1'b0;
end

initial
begin 
I_par=4'b0000;
repeat(12)
#50 I_par=I_par+1;
end
/*initial 
begin
I_par=4'b0000;
#30; I_par=4'b0001;
#60; I_par=4'b0010;
#90; I_par=4'b0011;
#120; I_par=4'b0100;
#150; I_par=4'b0101;
#180; I_par=4'b0110;
#210; I_par=4'b0111;
#240; I_par=4'b1000;
#270; I_par=4'b1001;
#300; I_par=4'b1010;
#330; I_par=4'b1011;
#360; I_par=4'b1100;
#390; I_par=4'b1101;
#420; I_par=4'b1110;
#450; I_par=4'b1111;
end*/

initial #800 $finish;

endmodule




