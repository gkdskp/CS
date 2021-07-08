; Find the factorial of a number

; Code from https://www.codesexplorer.com/2016/12/8051-code-to-find-factorial-of-n.html
; Runs for numbers upto 5 only :(

ORG 0000H

MOV R0, #5 ; Number to find factorial

MOV A, R0

FACT:
    DEC R0
    CJNE R0, #01, REL ; value of R0 is compared with 1
    JMP stop ; if R0=1, stop execution

REL:
    MOV B, R0
    MUL AB
    JMP FACT

STOP:
    END