# def count_less_equal(mid, arr):
#     count = 0
#     for num in arr:
#         if num <= mid:
#             count += 1
#     return count

# def count_elmnts_less_equal(mid, A, B, C):
#     count = 0
#     print([A,B,C])
#     for arr in [A, B, C]:
#         count += count_less_equal(mid, arr)
#     return count
 
# def kth_smallestelmtn(A, B, C, k):
#     low, high = min(A[0], B[0], C[0]), max(A[-1], B[-1], C[-1])

#     while low < high:
#         mid = (low + high) // 2
#         count = count_elmnts_less_equal(mid, A, B, C)

#         if count < k:
#             low = mid + 1
#         else:
#             high = mid

#     return low 
# # Example usage
# A = [1, 3, 5, 7, 9]
# B = [2, 4, 6, 8, 10]
# C = [0, 11, 12, 13, 14]
# k = 5 

# # Convert to 1-indexing
# A.insert(0, 0)
# B.insert(0, 0)
# C.insert(0, 0)

# print("A =", A[1:])
# print("B =", B[1:])
# print("C =", C[1:])
# print("k =", k)

# result = kth_smallestelmtn(A, B, C, k)
# print(f"The {k}-th smallest element is: {result}")
def count_less_equal(mid, arr):
    count = 0
    for num in arr:
        if num <= mid:
            count += 1
    return count

def count_elements_less_equal_recursive(mid, arr_list):
    if not arr_list:
        return 0

    current_arr = arr_list[0]
    remaining_arrs = arr_list[1:]

    return count_less_equal(mid, current_arr) + count_elements_less_equal_recursive(mid, remaining_arrs)

def kth_smallest_element_recursive_helper(A, B, C, low, high, k):
    if low <= high:
        mid = (low + high) // 2
        count = count_elements_less_equal_recursive(mid, [A, B, C])

        if count == k:
            if mid in A and mid in B and mid in C:
                return mid
            else:
                # Adjust the search range and continue the search
                result_left = kth_smallest_element_recursive_helper(A, B, C, low, mid - 1, k)
                result_right = kth_smallest_element_recursive_helper(A, B, C, mid + 1, high, k)
                return result_left if result_left != -1 else result_right

        elif count < k:
            return kth_smallest_element_recursive_helper(A, B, C, mid + 1, high, k)
        else:
            return kth_smallest_element_recursive_helper(A, B, C, low, mid - 1, k)

    return -1

def kth_smallest_element_recursive(A, B, C, k):
    low = min(A[0], B[0], C[0])
    high = max(A[-1], B[-1], C[-1])

    result = kth_smallest_element_recursive_helper(A, B, C, low, high, k)
    if result == -1:
        print(f"The {k}-th smallest element is not present.")
    else:
        print(f"The {k}-th smallest element is: {result}")

# Example usage
A = [1, 3, 5, 7, 9]
B = [2, 4, 6, 8, 10]
C = [0, 11, 12, 13, 14]
k = 5

kth_smallest_element_recursive(A, B, C, k)
