main:
    add $t0, $zero, $zero
    beq $zero, $zero, branch

branch:
    addi $t0, $t0, 5
    lea $t1, VALUE
    lw $t1, 0($t1)
    beq $zero, $zero, store

store:
    sw $t0, 0($t1)
    halt


VALUE: .fill 1