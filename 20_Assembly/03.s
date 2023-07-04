.global _start
_start:
	MOV R0, #5
	MOV R1, #7
    // set flag of cpsr register
    SUBS R7,R0,R1 // R7 = R0 - R1 // 5 - 7 = 0xFFFFFFFE

	ADD R2,R0,R1 // R2 = R0 + R1 
	SUB R3,R0,R1 // R3 = R0 - R1 // 5 - 7 = 0xFFFFFFFE
    MUL R4,R0,R1 // R4 = R0 * R1
    MOV R5, #0xFFFFFFFF
    SUB R6,R5,#1 // R6 = R5 - 1 // 0xFFFFFFFF - 1 = 0xFFFFFFFE

    // set flag of cpsr register
    SUBS R6,R0,R1 // R7 = R0 - R1 // 5 - 7 = 0xFFFFFFFE

    // carrry
    MOV R0, #0xFFFFFFFF
	MOV R1, #3
	ADDS R2,R0,R1 // S sets the flag
	ADC R3,R0,R1 // R3 = R0+R1+carry 