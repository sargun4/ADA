# 5. Finding the Smallest Element in a Bitonic Array:

# To find the smallest element in a bitonic array, you can use a modified binary search algorithm.

def find_min_in_bitonic_array(arr):
    n = len(arr)
    low, high = 0, n - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] < arr[(mid + 1) % n] and arr[mid] < arr[(mid - 1) % n]:
            return arr[mid]
        elif arr[mid] < arr[(mid + 1) % n]:
            high = mid - 1
        else:
            low = mid + 1
 
bitonic_array = [4, 6, 9, 8, 7, 5, 1, 2, 3]
result = find_min_in_bitonic_array(bitonic_array)
print(f"The smallest element in the bitonic array is: {result}")
# Running Time Analysis:

# The algorithm performs a modified binary search in O(log2(n)) time.
# At each step, it narrows down the search space by half, resulting in a logarithmic complexity.
# Justification:

# The algorithm takes advantage of the bitonic property to determine whether the minimum element is in the left or right half at each step.
# The termination condition ensures correctness by identifying the minimum element.