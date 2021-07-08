; Hex to decimal conversion
; Code from https://www.dnatechindia.com/Code-Library/8051-Assembly/8-bit-HEX-to-BCD-convertor.html

ORG 0000H

MOV R0, #55H
MOV R1, #00H
MOV R2, #00H

MOV A, R0
MOV B, #100
DIV AB

MOV R0, A
CLR C
MOV A, B
MOV B, #10
DIV AB

SWAP A

MOV R1, A
MOV A, B
ORL A, R1
MOV R1, A

END

END