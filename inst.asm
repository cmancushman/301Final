j 0xffff
add $3, $4, $8
addi $1, $2, -100
sw $1, -2($2)
lw $1, 13($2)
beq $3, $4, 0xff
slt $1, $2, $3
