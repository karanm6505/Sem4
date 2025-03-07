import numpy as np  
import scipy

def calibrate_sensor(A, b):  
    # Return: best-fit parameters (x), residual error vector
    
    #Implement your code here
    sqA = np.dot(A.T, A)  
    newb = np.dot(A.T, b)  
    x = np.linalg.solve(sqA, newb)  
    residual = np.dot(A, x) - b  

    return x, residual


# Boilerplate (do not modify)  
def main():  
    n = int(input())  # Number of experimental readings  
    A = []  
    for _ in range(n):  
        row = list(map(float, input().split()))  
        A.append(row)  
    b = np.array(list(map(float, input().split())))  
    A = np.array(A)  
    
    params, residual = calibrate_sensor(A, b)  
    
    print("Best-fit parameters:", np.round(params, 2))  
    print(f"Residual error: {np.round(residual, 2)}")  

if __name__ == "__main__":  
    main()  