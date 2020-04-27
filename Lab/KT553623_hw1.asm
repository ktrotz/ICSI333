#RECEIVE USER INPUT
addi $v0, $zero, 5 # 5 indicates read integer system call
syscall		# execute system call

# ask user to enter some value if they don't want to enter another value and 
# then jump to Exit

#OUTPUT 32 BIT BINARY
add $t0, $zero, $v0 # add user input in register
add $t1, $zero, $zero	# ouput variable
      
      # Create a mask to later loop through the system binary from left 
      # to right while performing the '&' operation to compare each value
      # at their position. 'Input & mask' produces the binary equivalent 
      # by changing each ouput of '&' one at a time.
      # thus 0&0=0, 1&0=0, 1&1=1
      
addi $t2, $zero, 1 # 1 placed as mask value in t2
sll $t2, $t2, 31 # shift mask value to position 31

addi $s0, $zero, 32 # index  = 32 so all positions can be printed
      
      
Loop:
and $t1, $t0, $t2	# input & mask = t1

#PRINT TO SCREEN
beq $t1, $zero, Print

Swap: # Necessary for binary output of 1
addi $t1, $zero, 1	# add value 1 to t1 

Print:
add $a0, $t1, $zero # Load binary output into register a0
li $v0, 1 # Print integer
syscall

srl $t2, $t2, 1 # Mask shifted right by 1
sub $s0, $s0, 1 # index decreases by 1 every iteration
bne $s0, $zero, Loop # if index != position '0' then go to Loop

#GO BACK TO INPUT
#j Input # check if users want to enter another value


