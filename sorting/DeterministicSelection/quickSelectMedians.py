

def select(arr, n, k):
    # Base Case: If the array size is 1, return the only element.
    if n == 1:
        return arr[0]

    # Choose a pivot using the ChoosePivot function.
    pivot = choose_pivot(arr, n)

    # Partition the array into Aleft and Aright.
    a_left = [el for el in arr if el < pivot]
    a_right = [el for el in arr if el > pivot]

    # Recursive calls based on the size of Aleft.
    if len(a_left) == k:
        return pivot
    elif len(a_left) > k:
        return select(a_left, len(a_left), k)
    else:
        return select(a_right, len(a_right), k - len(a_left))

def choose_pivot(arr, n):
    # Split the array into groups of size g = floor(n/5).
    g = n // 5
    groups = [arr[i:i + 5] for i in range(0, n, 5)]

    # Sort each group using Merge Sort.
    sorted_groups = [sorted(group) for group in groups]

    # Find the medians of each group and create a new array C.
    medians = [group[len(group) // 2] for group in sorted_groups]
    c = select(medians, len(medians), len(medians) // 2)

    # Return the pivot obtained from the recursive call to Select.
    return c

# Example Usage:
arr = [3, 1, 9, 2, 7, 5, 6, 4, 8, 10]
n = len(arr)
k = 4
result = select(arr, n, k)
print(f"The {k}-th smallest element is: {result}")
