;1. Add two sixteen-bit numbers.

MOV AX, [0300H]  ; Load the first 16-bit number from DS:0300H into AX
MOV BX, [0400H]  ; Load the second 16-bit number from DS:0400H into BX
ADD AX, BX       ; Add BX to AX
MOV [0500H], AX  ; Store the lower 16 bits of the result in DS:0500H
MOV [0501H], DX  ; Store the higher 16 bits (if any) in DS:0501H

;2. Subtract an 8-bit number using 2's complement.

MOV AL, [0300H]  ; Load the first 8-bit number from DS:0300H into AL
MOV BL, [0400H]  ; Load the second 8-bit number from DS:0400H into BL
SUB AL, BL       ; Subtract BL from AL
MOV [0500H], AL  ; Store the result in DS:0500H

;3. Transfer a block of 8 data bytes.

MOV SI, 0300H    ; Source index points to DS:0300H
MOV DI, 0400H    ; Destination index points to DS:0400H
MOV CX, 8        ; Counter for 8 bytes

REP MOVSB        ; Repeat moving bytes from SI to DI

;4. Add 7 eight-bit numbers.

MOV AL, 0        ; Clear AL register to accumulate the sum
MOV SI, 0300H    ; Load the starting address of the 7 numbers

MOV CX, 7        ; Counter for 7 numbers
ADD_LOOP:
ADD AL, [SI]     ; Add the number in memory to AL
INC SI           ; Move to the next number
LOOP ADD_LOOP    ; Repeat until CX becomes 0

MOV [0500H], AL  ; Store the result in DS:0500H

;5. Add 5 sixteen-bit numbers.

MOV AX, 0        ; Clear AX register to accumulate the sum
MOV SI, 0300H    ; Load the starting address of the 5 numbers

MOV CX, 5        ; Counter for 5 numbers
ADD_LOOP:
ADD AX, [SI]     ; Add the number in memory to AX
ADD SI, 2        ; Move to the next number (16-bit increment)
LOOP ADD_LOOP    ; Repeat until CX becomes 0

MOV [0500H], AX  ; Store the result in DS:0500H

;6. Add five BCD numbers.

MOV AL, 0        ; Clear AL register to accumulate the sum
MOV SI, 0300H    ; Load the starting address of the 5 numbers

MOV CX, 5        ; Counter for 5 numbers
ADD_LOOP:
ADD AL, [SI]     ; Add the BCD number in memory to AL
DAA              ; Decimal Adjust AL after addition
INC SI           ; Move to the next BCD number
LOOP ADD_LOOP    ; Repeat until CX becomes 0

MOV [0400H], AL  ; Store the result in DS:0400H

;7. Subtract a BCD number from another.

MOV AL, [0500H]  ; Load the BCD number from DS:0500H into AL
MOV BL, [0400H]  ; Load the BCD number from DS:0400H into BL
SUB AL, BL       ; Subtract BL from AL
DAS              ; Decimal Adjust AL after subtraction
MOV [0600H], AL  ; Store the result in DS:0600H

;8. Multiply two 8-bit numbers.

MOV AL, [0400H]  ; Load the first 8-bit number from DS:0400H into AL
MOV BL, [0500H]  ; Load the second 8-bit number from DS:0500H into BL
MUL BL           ; Multiply AL by BL (result in AX)
MOV [0600H], AX  ; Store the result in DS:0600H

;9. Multiply two 16-bit numbers.

MOV AX, [0400H]  ; Load the first 16-bit number from DS:0400H into AX
MOV BX, [0500H]  ; Load the second 16-bit number from DS:0500H into BX
MUL BX           ; Multiply AX by BX (result in DX:AX)
MOV [0600H], AX  ; Store the lower 16 bits of the result in DS:0600H
MOV [0602H], DX  ; Store the upper 16 bits of the result in DS:0602H


; 10. Divide 88H by 33H.

MOV AL, 88H      ; Load 88H into AL
MOV BL, 33H      ; Load 33H into BL
DIV BL           ; Divide AL by BL (quotient in AL, remainder in AH)
MOV [0600H], AL  ; Store the quotient in DS:0600H
MOV [0601H], AH  ; Store the remainder in DS:0601H

;11. Divide 2222H by 55H.

MOV AX, 2222H    ; Load 2222H into AX
MOV BL, 55H      ; Load 55H into BL
DIV BL           ; Divide AX by BL (quotient in AL, remainder in AH)
MOV [0600H], AL  ; Store the quotient in DS:0600H
MOV [0601H], AH  ; Store the remainder in DS:0601H