# To efficiently merge k sorted arrays, you can use a min heap (priority queue) to keep track of the smallest element from each array
import heapq

def merge_k_sorted_arrays(arrays):
    result = []
    heap = []

    # Initialize the heap with the first element from each array
    for i, arr in enumerate(arrays):
        if arr:  # Ensure the array is not empty
            heapq.heappush(heap, (arr[0], i, 0))

    while heap:
        val, arr_idx, element_idx = heapq.heappop(heap)

        # Add the smallest element to the result
        result.append(val)

        # Move to the next element in the same array
        if element_idx + 1 < len(arrays[arr_idx]):
            next_element = arrays[arr_idx][element_idx + 1]
            heapq.heappush(heap, (next_element, arr_idx, element_idx + 1))

    return result

# Example usage:
arrays = [
    [1, 3, 5],
    [2, 4, 6],
    [0, 7, 8, 9]
]

result = merge_k_sorted_arrays(arrays)
print(result)
