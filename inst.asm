add $3, $4, $8
addi $1, $2, 100
mult $2, $3
mflo $1
sra $1, $2, 10
j 0x1
slt $1, $2, $3
lb $1, 100($2)
beq $3, $4, 0x1
