.global _start
_start:
	MOV R0,#1
	MOV R1,#3
	BL add2 // Branch Linked, store in lr (link register)
	// after add2 done, lr stored counter, returns to after BL
	MOV R3,#4
	

add2:
	ADD R2,R0,R1
	bx lr // branch back to lr (link register)
	