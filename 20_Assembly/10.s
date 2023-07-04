.global _start
_start:
	MOV R0,#1
	MOV R1,#3
	PUSH {R0,R1} // push R0,R1 onto stack memory
	BL get_value
	POP {R9, R0,R1} // R0,R1 values are restored, preserving these values
		// R9 gets the value pushed by get_value function
	B end
	
get_value:
	MOV R0,#5
	MOV R1,#7
	ADD R2,R0,R1
	PUSH {R2} // push R2 value onto memory stack, 
	// can then be popped in main as return value
	BX lr

end:
	