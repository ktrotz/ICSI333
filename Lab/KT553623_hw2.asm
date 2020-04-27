
.data #variable declarations follow 

msg1: .asciiz "Enter size of array: "
msg2: .asciiz "Enter values based on size of array: "

.text #instructions follow this line

main: # main identifies the start of the code (.text)
add $t2, $zero, $sp # Save the sp address to t2
add $t1, $zero, $zero  #end loop

#Prompt the user for a number that defines the size of an array/stack
#Msg1 
li $v0, 4 #print string 
la $a0, msg1 #load address of msg1 into a0
syscall 

#User initialized array size
addi $v0, $zero, 5 #read int
syscall 
add $t1, $zero, $v0 #end loop = user input size
add $t0, $t1, $zero #t0 = end loop value

#Prompt the user to enter n integers based on the size of the array
#Msg2
LoopMsg2:
li $v0, 4 #print string 
la $a0, msg2 #load address of msg2 into a0
syscall 

#Store all integer values in an array/stack in memory
addi $v0, $zero, 5 #read int
syscall 

sw $v0, 0($t2) #stack pointer
subi $t1, $t1, 1 #end loop decreases by 1 
addi $t2, $t2, 4 #sp increments by four 
bne $t1, $zero, LoopMsg2


#Sort all integer values
bubbleSort:
# t0 = size of table 

add $t3, $zero, $zero # counter1
add $t4, $zero, $zero #counter2 = size of array 

add $s1, $t0, 1 # s1 = table size + 1

outerLoop: 
addi $t3, $t3, 1 # increment loop
bgt $t3, $t0, Print #if counter1 is more than the array size go to Print

add $t4, $t0, $zero # t4 = size of array
subi $s1, $s1, 1 #decrement table size to not check last sorted value
addi $s0, $zero, 1 #restart innerLoop counter

# stack pointers used to compare values
add $t5, $zero, $sp 
add $t6, $zero, $sp
addi $t5, $t5, 4

innerLoop:
bge $s0, $s1, outerLoop # if counter3 is more than or equal to array size then go to outerLoop
lw $t7, 0($t5) # load t5: 4 + base into t7
lw $t8, 0($t6) # load t6: 0 + base into t8

# move to next two values
addi $t5, $t5, 4 #sp
addi $t6, $t6, 4

addi $s0, $s0, 1 #increment innerLoop
bgt $t7, $t8, innerLoop #if t7 > t8 go to innerLoop and use updated sp values

# swap values if t8 > t7
addi $t5, $t5, -4 # move down to previous sp values
addi $t6, $t6, -4

sw $t8, 0($t5) # save 0 + base value into 4 + base address
sw $t7, 0($t6) # save 4 + base value into 0 + base address

# update sp value to point to next two values
addi $t5, $t5, 4 
addi $t6, $t6, 4
j innerLoop


Print:
#Print out the sorted integer list 
add $t2, $zero, $sp

Display:
lw $a0, 0($t2)
li $v0, 1 #print integer
syscall

addi $t2, $t2, 4 #t2 increments by four
subi $t0, $t0, 1 #end decreases by 1
bne $t0, $zero, Display
