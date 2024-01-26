 
def binary_search(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return low

def count_elements_less_equal(mid, A, B, C):
    count = 0
    for arr in [A, B, C]:
        count += binary_search(arr, mid) + 1
    return count
def kth_smallest_element(A, B, C, k):
    low, high = min(A[0], B[0], C[0]), max(A[-1], B[-1], C[-1])

    while low < high:
        mid = low + (high - low) // 2
        count = 0

        for arr in [A, B, C]:
            count += binary_search(arr, mid)

        if count < k:
            low = mid + 1
        else:
            high = mid

    return low

# Example usage
A = [1, 3, 5, 7, 9]
B = [2, 4, 6, 8, 10]
C = [0, 11, 12, 13, 14]
k = 0

result = kth_smallest_element(A, B, C, k)
print(f"The {k}-th smallest element is: {result}")
