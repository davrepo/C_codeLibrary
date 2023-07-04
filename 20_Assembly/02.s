.global _start
_start:
	LDR R0, =list  // assign the address of list to R0
	LDR R1, [R0]  // load the first element of list to R1
	LDR R2, [R0,#4]  // load the second element of list to R2
	LDR R3, [R0,#8]  // load the third element of list to R3
	LDR R4, [R0,#4]! // load the second element of list to R4 and increment the address by 4 (Preincrement)
	LDR R5, [R0],#4 // load the first element of list to R5 and increment the address by 4 (Postincrement)

.data // switches the assembler to the data section
list: // label, a name given to a certain point in the program, also acts as base address
	.word 4,5,-9,1,0,2,-3  // list of numbers stored in memory, each number uses 1 word (4 bytes)

