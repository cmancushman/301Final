<<<<<<< HEAD
slt $1, $3, $1
=======
<<<<<<< HEAD
slt $1, $2, $3
>>>>>>> 76330b0dc6d6e9f934465b12fbcebce94f752c2b
sw $2, 0($3)
lw $1, 0($3)
add $3, $4, $8
j      0x10006
beq $3, $4, 0x0
<<<<<<< HEAD
slt $6, $2, $3
=======
=======
j 0x10002
add $3, $4, $8
addi $1, $2, -100
sw $1, -2($2)
lw $1, 13($2)
beq $3, $4, 0xffff
>>>>>>> parent of a3705bc... asd
slt $1, $2, $3
>>>>>>> 76330b0dc6d6e9f934465b12fbcebce94f752c2b
