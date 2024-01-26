class Solution:
    def merge(self, arr, l, m, r):
        lsize = m - l + 1
        rsize = r - m
        left = [0] * lsize
        right = [0] * rsize
        for i in range(lsize):
            left[i] = arr[l + i]
        for j in range(rsize):
            right[j] = arr[m + 1 + j]
        i = j = 0
        k = l
        while i < lsize and j < rsize:
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < lsize:
            arr[k] = left[i]
            i += 1
            k += 1
        while j < rsize:
            arr[k] = right[j]
            j += 1
            k += 1
    def mergeSort(self, arr, l, r):
        if l < r:
            mid = l + (r - l) // 2
            self.mergeSort(arr, l, mid)
            self.mergeSort(arr, mid + 1, r)
            self.merge(arr, l, mid, r)
