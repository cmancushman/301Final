slt $1, $2, $3
sw $2, 0($3)
lw $1, 0($3)
add $3, $4, $8
j      0x10005
beq $3, $9, 0x1
slt $6, $2, $3