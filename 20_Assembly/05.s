.global _start
_start:
	MOV R0, #10
	MOV R1, R0
	LSL R1, #1 // left shift 1 time, same as multiply by 2
	LSR R1, #1 // right shift 1 time, same as divide by 2

    // short hand version
    MOV R1,R0,LSL #1 // move R0 to R1, left shift R1 by 1 time
	