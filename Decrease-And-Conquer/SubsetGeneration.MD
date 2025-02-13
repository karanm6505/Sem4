# Subset Generation (Using Binary Reflected Gray Code)

### Algorithm
```
ALGORITHM BRGC(n)
    //Generates recursively the binary reflected Gray code of order n
    //Input: A positive integer n
    //Output: A list of all bit strings of length n composing the Gray code
if n = 1 make list L containing bit strings 0 and 1 in this order
else generate list L1 of bit strings of size n− 1 by calling BRGC(n− 1)
    copy list L1 to list L2 in reversed order
    add 0 in front of each bit string in list L1
    add 1 in front of each bit string in list L2
    append L2 to L1 to get list L
return L

```