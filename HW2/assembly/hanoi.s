!============================================================
! CS 2200 Homework 2 Part 2: Tower of Hanoi
!
! Apart from initializing the stack,
! please do not edit mains functionality. You do not need to
! save the return address before jumping to hanoi in
! main.
!============================================================

main:
    lea     $sp, stack
    lw      $sp, 0($sp)
    lea     $fp, stack
    lw      $fp, 0($fp)
    lea     $at, hanoi              
    lea     $a0, testNumDisks2      
    lw      $a0, 0($a0)             
    jalr    $at, $ra                
    halt                            

hanoi:
    addi    $sp, $sp, -1
    sw		$fp, 0($sp)
    addi    $fp, $sp, 0
    addi    $t0, $a0, -1
    bgt     $t0, $zero, else
    beq     $zero, $zero, base

else:
    addi    $a0, $a0, -1
    lea     $at, hanoi
    addi    $sp, $sp, -1
    sw      $ra, -1($fp)
    jalr    $at, $ra
    lw      $ra, -1($fp)
    addi    $sp, $sp, 1

    add     $v0, $v0, $v0
    addi    $v0, $v0, 1
    beq     $zero, $zero, teardown

base:
    addi     $v0, $zero, 1

teardown:
    lw      $fp, 0($fp)
    addi    $sp, $sp, 1
    jalr    $ra, $zero



stack: .word 0xFFFF                 ! the stack begins here


! Words for testing \/

! 1
testNumDisks1:
    .word 0x0001

! 10
testNumDisks2:
    .word 0x000a

! 20
testNumDisks3:
    .word 0x0014
