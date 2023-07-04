.global _start
_start:
	MOV R0, #0xAA
	MOV R1, #22
	AND R2, R0, R1
	
	MVN R0, R0 // NOT R0 and store in R0

    // clear bits in the register
    AND R0, R0, #0x000000AA // AND R0 with 0xFF and store in R0