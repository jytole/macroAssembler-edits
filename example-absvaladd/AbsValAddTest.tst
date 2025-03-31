load AbsValAddTest.hack,
output-file AbsValAddTest.out,
compare-to AbsValAddTest.cmp,
output-list RAM[6]%D2.6.2 RAM[7]%D2.6.2 RAM[8]%D2.6.2 ;

set RAM[0] 1023,  // Set SP
set RAM[1] 0,

set RAM[6] 0,   // Set test arguments
set RAM[7] 0,
set RAM[8] -1;  // Test that program initialized result to 0
repeat 5000 {
  ticktock;
}
set RAM[6] 0,   // Restore arguments in case program used them as loop counter
set RAM[7] 0,
output;

set PC 0,
set RAM[6] 1,   // Set test arguments
set RAM[7] 1,
set RAM[8] -1;
repeat 5000 {
  ticktock;
}
set RAM[6] 1,   // Restore arguments in case program used them as loop counter
set RAM[7] 1,
output;

set PC 0,
set RAM[6] -1,   // Set test arguments
set RAM[7] 1,
set RAM[8] -1;
repeat 5000 {
  ticktock;
}
set RAM[6] -1,   // Restore arguments in case program used them as loop counter
set RAM[7] 1,
output;

set PC 0,
set RAM[6] -1,   // Set test arguments
set RAM[7] -1,
set RAM[8] -1;
repeat 5000 {
  ticktock;
}
set RAM[6] -1,   // Restore arguments in case program used them as loop counter
set RAM[7] -1,
output;

set PC 0,
set RAM[6] -223,   // Set test arguments
set RAM[7] 23,
set RAM[8] -1;
repeat 5000 {
  ticktock;
}
set RAM[6] -223,   // Restore arguments in case program used them as loop counter
set RAM[7] 23,
output;

set PC 0,
set RAM[6] -234,   // Set test arguments
set RAM[7] 2,
set RAM[8] -1;
repeat 5000 {
  ticktock;
}
set RAM[6] -234,   // Restore arguments in case program used them as loop counter
set RAM[7] 2,
output;