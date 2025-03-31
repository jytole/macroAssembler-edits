// Note for this the stack will be starting at the top of memory and building
// down.  These are the basic stack operations that will be implemented

//-----------------------------------------------------------------------------
// Push D register onto the stack, D remains unchanged by ths operation
$def pushD
// goes to SP
@SP
A=M
// pushes D onto stack
M=D
// decrements SP
@SP
M=M-1
$end

//-----------------------------------------------------------------------------




// Push A register onto the stack, D is value pushed on the stack after this
// operation
$def pushA
// saves A to D then pushes D
D=A
$pushD
$end

//-----------------------------------------------------------------------------




// Pop the top of stack into the A and D registers
$def popAD
// increments SP
@SP //call sp
M=M+1 // increase "iterator"
// goes to last value in the stack
A=M //select the value
// saves value to D reg and A reg
AD=M //Didn't know you could double variable like this previous to your video
// no need to delete the value thanks to pointers. value will be overridden 
$end

//-----------------------------------------------------------------------------


// Use push value, push ptr, setPTR pops these off of stack and
// sets *ptr=value
$def setPTR
// pop ptr (store in R15)
$popAD //pop data
@R15 //select pointer
M=D //store data in R15
// pop value (store in D reg)
$popAD // popAD function takes care of the storage as well
// saves the value (D reg) in the pointer (R15)
@R15 //select R15
A=M //Going to what R15 is pointing to. 
M=D //setting it equal to data
$end

//-----------------------------------------------------------------------------






// get pointer pops pointer off of the stack then push *ptr onto the
// stack
$def getPTR
// pops the stack into A and D
$popAD //get memory location
// sets the D reg to value at the pointer
D=M //grab value in location
// pushes the D reg onto the stack
$pushD //store in stack
$end

//-----------------------------------------------------------------------------




// store register D in the local variable id defined by *(LCL-id)
$def setLocal id
// saves D reg into stack
$pushD 
// saves the id num
@id //grab index
D=A //set D register equal to index 
// pushes to LCL-id onto stack
@LCL // grab LCL
D=M-D // D = value at index of LCL
$pushD //push onto stack

$setPTR
$end

//-----------------------------------------------------------------------------





// get the local variable id defined by *(LCL-id) into registers A and D
$def getLocal id
// saves the id num
@id
D=A
// goes to LCL-id
@LCL
A=M-D
// saves the value at LCL-id to AD
AD=M
$end

//-----------------------------------------------------------------------------




// set the argument id (defined by *(ARG-id)) to the value stored in register D
$def setArgument id
// saves D reg into stack
$pushD
// saves the id num
@id
D=A
// pushes to ARG-id onto stack
@ARG
D=M-D
$pushD
// sets the value
$setPTR
$end

//-----------------------------------------------------------------------------


// get argument id (defined by *(ARG-id)) and store in registers A and D
$def getArgument id
// saves the id num
@id
D=A
// goes to ARG-id
@ARG
A=M-D
// saves the value at ARG-id to AD
AD=M
$end