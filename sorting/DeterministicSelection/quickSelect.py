def quick_select(arr, k):
    """
    Find the k-th smallest element in the array using QuickSelect algorithm.

    Parameters:
    - arr: The input array.
    - k: The index of the desired smallest element.

    Returns:
    - The k-th smallest element in the array.
    """
    if not arr:
        return None

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    right = [x for x in arr if x > pivot]
    equal = [x for x in arr if x == pivot]

    if k < len(left):
        # If k is in the left subarray, recursively call quick_select on the left subarray.
        return quick_select(left, k)
    elif k < len(left) + len(equal):
        # If k is equal to the length of the left subarray plus the length of the equal subarray,
        # then the pivot is the k-th smallest element.
        return equal[0]
    else:
        # If k is in the right subarray, recursively call quick_select on the right subarray.
        return quick_select(right, k - len(left) - len(equal))

# Example Usage:
arr = [3, 1, 9, 2, 7, 5, 6, 4, 8, 10]
k = 4
result = quick_select(arr, k - 1)  # Adjust k to 0-based index
print(f"The {k}-th smallest element is: {result}")
