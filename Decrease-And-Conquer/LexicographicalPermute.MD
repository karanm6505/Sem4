# Lexicographic Permute

### Algorithm
```
ALGORITHM LexicographicPermute(n)
    //Generates permutations in lexicographic order
    //Input: A positive integer n
    //Output: A list of all permutations of {1, . . . , n} in lexicographic order
initialize the first permutation with 12 . . . n
while last permutation has two consecutive elements in increasing order do
    let i be its largest index such that ai < ai+1 //ai+1 > ai+2 > . . . > an
    find the largest index j such that ai < aj //j ≥ i + 1 since ai < ai+1
    swap ai with aj //ai+1ai+2 . . . an will remain in decreasing order
    reverse the order of the elements from ai+1 to an inclusive
add the new permutation to the list
```