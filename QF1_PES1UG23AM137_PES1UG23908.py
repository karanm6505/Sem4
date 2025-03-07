import scipy
import scipy.linalg
import numpy as np

def plu_factorization(A):
    """
    Perform PLU factorization on the given square matrix A.

    Args:
        A (numpy.ndarray): A square matrix of size n x n.

    Returns:
        tuple: A tuple (P, L, U) where P is the permutation matrix, L is the lower triangular matrix and U is the upper triangular matrix.
    """

    #Implement your code here
    P, L, U = scipy.linalg.lu(A)
    return P, L, U

# Boilerplate code to handle input and output
def main():
    A = []
    while True:
        try:
            row = input().strip()  # Read a line of input
            if row:
                A.append(list(map(float, row.split())))
            else:
                break
        except EOFError:
            break
    A=np.array(A)
    P, L, U = plu_factorization(A)

    # Print results
    print("P =")
    for row in P:
        print(" ".join(f"{x:.1f}" for x in row))
    print("\nL =")
    for row in L:
        print(" ".join(f"{x:.1f}" for x in row))
    print("\nU =")
    for row in U:
        print(" ".join(f"{x:.1f}" for x in row))


if __name__ == "__main__":
    main()