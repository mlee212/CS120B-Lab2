# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
# test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
# setPINA 0x00
# setPINB 0x00
# Continue for several ticks
# continue 2
# Set expect values
# expectPORTC 0
# Check pass/fail
# checkResult

# Add tests below
test "PINA: 0x50, PINB: 0x50, PINC: 0x50 PORTC: 0xBC"
setPINA 0x50
setPINB 0x50
setPINC 0x50
continue 5
expectPORTD 0xBC
checkResult

test "PINA: 0x28, PINB: 0x28, PINC: 0x28 PORTC: 0x1E"
setPINA 0x28
setPINB 0x28
setPINC 0x28
continue 5
expectPORTD 0x1E
checkResult

test "PINA: 0x5A, PINB: 0x50, PINC: 0x00 PORTC: 0xEA"
setPINA 0x5A
setPINB 0x50
setPINC 0x00
continue 5
expectPORTD 0xEA
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
