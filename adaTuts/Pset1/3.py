# 3. Given an array A of n distinct elements sorted in increasing order. Design an algo-
# that determines if there is an index i such that A[i] = i.

# Algorithm to Find A[i] = i:

# Given a sorted array A of n distinct elements, you can use a binary search based algorithm to determine 
# if there exists an index i such that A[i] = i.
 
def find_fixed_point(arr):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == mid:
            return True
        elif arr[mid] < mid:
            low = mid + 1
        else:
            high = mid - 1

    return False
 
array = [-10, -5, 1, 3, 7, 9, 12, 17]
result = find_fixed_point(array)
print(f"Does there exist an index i such that A[i] = i? {'Yes' if result else 'No'}")
 