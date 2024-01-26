class Solution: 
    def merge(self, a1, a2):
        len1 = len(a1)
        len2 = len(a2)
        merged = []
        i = 0
        j = 0
        while i < len1 and j < len2:
            if a1[i] < a2[j]:
                merged.append(a1[i])
                i += 1
            else:
                merged.append(a2[j])
                j += 1
        while i < len1:
            merged.append(a1[i])
            i += 1
        while j < len2:
            merged.append(a2[j])
            j += 1
        return merged
    def mergeKArrays(self, arr, K):
        if K == 1:
            return arr[0]
        mid = K // 2
        b1 = self.mergeKArrays(arr[:mid], mid)
        b2 = self.mergeKArrays(arr[mid:], K - mid)
        result = self.merge(b1, b2)
        return result
# # Combine k sorted arrays
# def combine(arrays, k, n):
#     if k == 1:
#         return arrays[0]

#     mid = k // 2

#     # Recursive calls to combine the first half and second half of arrays
#     (b1, np) = combine(arrays[:mid], mid, n)
#     (b2, nk) = combine(arrays[mid:], k - mid, n)

#     # Merge the two halves
#     (b, nk) = merge(b1, b2, np, nk, n * (k - mid))

#     return b, nk

# # Merge two sorted arrays
# def merge(arr1, arr2, np, nk, n):
#     result = []
#     i = j = 0

#     while i < np and j < nk:
#         if arr1[i] < arr2[j]:
#             result.append(arr1[i])
#             i += 1
#         else:
#             result.append(arr2[j])
#             j += 1

#     # Add remaining elements from arr1, if any
#     while i < np:
#         result.append(arr1[i])
#         i += 1

#     # Add remaining elements from arr2, if any
#     while j < nk:
#         result.append(arr2[j])
#         j += 1

#     return result, n

# def merge_sorted_arrays(arrs):
#     """
#     Merge k sorted arrays using divide and conquer.

#     Parameters:
#     - arrs: A list of k sorted arrays.

#     Returns:
#     - A single sorted array containing all elements from the input arrays.
#     """
#     if not arrs:
#         return []

#     k = len(arrs)
    
#     # Base case: If there's only one array, return it.
#     if k == 1:
#         return arrs[0]

#     # Divide the list of arrays into two halves.
#     mid = k // 2
#     left_half = arrs[:mid]
#     right_half = arrs[mid:]

#     # Recursively merge the two halves.
#     left_merged = merge_sorted_arrays(left_half)
#     right_merged = merge_sorted_arrays(right_half)

#     # Merge the two sorted halves.
#     return merge(left_merged, right_merged)



# def merge(arr1, arr2):
#     """
#     Merge two sorted arrays.

#     Parameters:
#     - arr1: First sorted array.
#     - arr2: Second sorted array.

#     Returns:
#     - A single sorted array containing all elements from arr1 and arr2.
#     """
#     merged = []
#     i = j = 0

#     while i < len(arr1) and j < len(arr2):
#         if arr1[i] < arr2[j]:
#             merged.append(arr1[i])
#             i += 1
#         else:
#             merged.append(arr2[j])
#             j += 1

#     # Append remaining elements from both arrays (if any).
#     merged.extend(arr1[i:])
#     merged.extend(arr2[j:])

#     return merged
 