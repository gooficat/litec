.globl main
.text

main:
    movq $32 + (32*2/~32), %rax
    ret