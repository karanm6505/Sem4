# Johnson-Trotter Algorithm

### Algorithm
```
ALGORITHM JohnsonTrotter(n)
    //Implements Johnson-Trotter algorithm for generating permutations
    //Input: A positive integer n
    //Output: A list of all permutations of {1, . . . , n}
initialize the first permutation with 1←2←...n
while the last permutation has a mobile element do
    find its largest mobile element k
    swap k with the adjacent element k’s arrow points to
    reverse the direction of all the elements that are larger than k
    add the new permutation to the list
```
