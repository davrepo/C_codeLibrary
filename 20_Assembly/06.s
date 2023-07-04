.global _start
_start:
	MOV R0,#1
	MOV R1,#2
	
	CMP R0,R1 // compare R0, R1, by R0-R1, give 0, pos, neg number
			// cpsr set based on result of substraction

    BGT label1 // if R0 > R1, then branch to label1
    BLT label2 // if R0 < R1, then branch to label2
    BEQ label3 // if R0 == R1, then branch to label3
    BAL default // branch always to label4

label1:
    MOV R2,#1

default:
    MOV R2,#2

