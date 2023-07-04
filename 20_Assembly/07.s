.global _start

.equ endlist, 0xaaaaaaaa // constant, end of list flag in memory

_start:
	LDR R0,=list
	LDR R3,=endlist // end of list marker
	LDR R1,[R0]
	ADD R2,R2,R1 // add first element to sum, initialize

loop:
	LDR R1,[R0,#4]!
	CMP R1,R3
	BEQ exit // if ==R3, i.e. reach end of list, then go to exit label
	ADD R2,R2,R1
	BAL loop // branch back to loop

exit:
	// exit list
	

.data
list:
	.word 1,2,3,4,5,6,7,8,9,10

