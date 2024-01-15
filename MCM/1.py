# Dynamic Programming Solution for Matrix Chain Multiplication using Memoization:

# Build a matrix dp[][] of size N*N for memoization purposes.
# Use the same recursive call as done in the above approach:
# When we find a range (i, j) for which the value is already calculated, return the minimum value for that range (i.e., dp[i][j]).
# Otherwise, perform the recursive calls as mentioned earlier.
# The value stored at dp[0][N-1] is the required answer.
# Python program using memoization 
import sys
dp = [[-1 for i in range(100)] for j in range(100)]

# Function for matrix chain multiplication 
def matrixChainMemoised(p, i, j):
	if(i == j):
		return 0
	
	if(dp[i][j] != -1):
		return dp[i][j]
	
	dp[i][j] = sys.maxsize
	
	for k in range(i,j):
		dp[i][j] = min(dp[i][j], matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j)+ p[i - 1] * p[k] * p[j])
	
	return dp[i][j]

def MatrixChainOrder(p,n):
	i = 1
	j = n - 1
	return matrixChainMemoised(p, i, j)

# Driver Code
arr = [1, 2, 3, 4]
n = len(arr)
print("Minimum number of multiplications is",MatrixChainOrder(arr, n))
# Time Complexity: O(N3 )
# Auxiliary Space: O(N2) ignoring recursion stack space


# Dynamic Programming Solution for Matrix Chain Multiplication using Tabulation (Iterative Approach):

# Iterate from l = 2 to N-1 which denotes the length of the range:
# Iterate from i = 0 to N-1:
# Find the right end of the range (j) having l matrices.
# Iterate from k = i+1 to j which denotes the point of partition.
# Multiply the matrices in range (i, k) and (k, j).
# This will create two matrices with dimensions arr[i-1]*arr[k] and arr[k]*arr[j].
# The number of multiplications to be performed to multiply these two matrices (say X) are arr[i-1]*arr[k]*arr[j].
# The total number of multiplications is dp[i][k]+ dp[k+1][j] + X.
# The value stored at dp[1][N-1] is the required answer.
# Dynamic Programming Python implementation of Matrix
# Chain Multiplication. See the Cormen book for details
# of the following algorithm
import sys
maxint=int(1e9+7)
# Matrix Ai has dimension p[i-1] x p[i] for i = 1..n


def MatrixChainOrder(p, n):
	# For simplicity of the program, 
	# one extra row and one
	# extra column are allocated in m[][]. 
	# 0th row and 0th
	# column of m[][] are not used
	m = [[0 for x in range(n)] for x in range(n)]

	# m[i, j] = Minimum number of scalar 
	# multiplications needed
	# to compute the matrix A[i]A[i + 1]...A[j] = 
	# A[i..j] where
	# dimension of A[i] is p[i-1] x p[i]

	# cost is zero when multiplying one matrix.
	for i in range(1, n):
		m[i][i] = 0

	# L is chain length.
	for L in range(2, n):
		for i in range(1, n-L + 1):
			j = i + L-1
			m[i][j] = maxint
			for k in range(i, j):

				# q = cost / scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j]
				if q < m[i][j]:
					m[i][j] = q

	return m[1][n-1]


# Driver code
arr = [1, 2, 3, 4]
size = len(arr)

print("Minimum number of multiplications is " +
	str(MatrixChainOrder(arr, size)))
# Time Complexity: O(N3 )
# Auxiliary Space: O(N2)