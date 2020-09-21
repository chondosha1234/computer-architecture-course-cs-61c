
########
#    find the length of a null terminated string in bytes
#    a0 : (char *) pointer to a null terminated string
#    a0 : return int  
########

.text

strlen:
    lb t0, 0(a0)
    beq t0, zero, basecase
    addi a0, a0, 1   # move to next letter in string
    addi sp, sp, -4
    sw ra, 0(sp)
    jal strlen
    addi a0, a0, 1
    lw ra, 0(sp)
    addi sp, sp, 4
    ret
basecase:
    li a0, 0
    ret
    



