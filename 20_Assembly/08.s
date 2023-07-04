.global _start
_start:
	MOV R0,#2
	MOV R1,#4
	CMP R0,R1
	ADDLT R2,#1 // will only trigger, if CMP result is LT
    MOVLT R2,#2 // will only trigger, if CMP result is LT
	
