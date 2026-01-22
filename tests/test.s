.asciz "Hello!"

.byte 0x0A

main:
    add %ax, 32(%ax)
