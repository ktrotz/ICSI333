# comment

add $t1, $zero, $zero   # initializes register $t1 by setting $t1 = 0 + 0
add $t1, $t1, 1 	# Adds 1 to $t1 by setting $t1 = $t1 + 1

# START LOOP
Loop1:
add $t1, $t1, 1 
ble $t1, 10, Loop1 # if t1 is less than or equal to 10; branch
# END LOOP
