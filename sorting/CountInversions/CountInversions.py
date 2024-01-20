class Solution:
    def inversionCount(self, arr, n):
        def mergeAndCountSplitInversions(left, right):
            i = j = ctr = 0
            res = []

            while i < len(left) and j < len(right):
                if left[i] <= right[j]:
                    res.append(left[i])
                    i += 1
                else:
                    res.append(right[j])
                    ctr += len(left) - i
                    j += 1

            res.extend(left[i:])
            res.extend(right[j:])
            return res, ctr

        def countInversions(arr):
            if len(arr) <= 1:
                return arr, 0

            mid = len(arr) // 2
            left, leftCount = countInversions(arr[:mid])
            right, rightCount = countInversions(arr[mid:])
            merged, splitCount = mergeAndCountSplitInversions(left, right)

            return merged, leftCount + rightCount + splitCount

        _, inversion_count = countInversions(arr)
        return inversion_count
 