; Addition of two 16-bit numbers

ORG 0000H

; ROR1 forms 2000H
MOV R0, #20H
MOV R1, #00H

; R2R3 forms 3000H
MOV R2, #30H
MOV R3, #00H

; Addition of lower byte
MOV A, R1
ADD A, R3
MOV R5, A ; Lower byte of result stored in R5

; Addition of upper byte
MOV A, R0
ADDC A, R2
MOV R4, A ; Upper byte of result stored in R4

END

