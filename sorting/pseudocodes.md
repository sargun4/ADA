```py
1. Merge Sort:

merge_sort(arr, l, r):
  if l < r:
    mid = (l + r) // 2
    merge_sort(arr, l, mid)
    merge_sort(arr, mid + 1, r)
    merge(arr, l, mid, r)

merge(arr, l, mid, r):
  temp = []
  i = l
  j = mid + 1
  while i <= mid and j <= r:
    if arr[i] <= arr[j]:
      temp.append(arr[i])
      i += 1
    else:
      temp.append(arr[j])
      j += 1
  while i <= mid:
    temp.append(arr[i])
    i += 1
  while j <= r:
    temp.append(arr[j])
    j += 1
  for i in range(l, r + 1):
    arr[i] = temp[i - l]


2. Quick Sort:

quick_sort(arr, l, r):
  if l < r:
    pivot = partition(arr, l, r)
    quick_sort(arr, l, pivot - 1)
    quick_sort(arr, pivot + 1, r)

partition(arr, l, r):
  pivot = arr[r]
  i = l - 1
  for j in range(l, r):
    if arr[j] <= pivot:
      i += 1
      arr[i], arr[j] = arr[j], arr[i]
  i += 1
  arr[i], arr[r] = arr[r], arr[i]
  return i

3. Bubble Sort:

bubble_sort(arr):
  for i in range(len(arr) - 1):
    swapped = False
    for j in range(len(arr) - 1 - i):
      if arr[j] > arr[j + 1]:
        swapped = True
        arr[j], arr[j + 1] = arr[j + 1], arr[j]
    if not swapped:
      break

4. Selection Sort:

selection_sort(arr):
  for i in range(len(arr)):
    min_index = i
    for j in range(i + 1, len(arr)):
      if arr[j] < arr[min_index]:
        min_index = j
    arr[i], arr[min_index] = arr[min_index], arr[i]

5. Insertion Sort:

insertion_sort(arr):
  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1
    arr[j + 1] = key
```

https://www.google.com/url?sa=i&url=https%3A%2F%2Fcs.stackexchange.com%2Fquestions%2F155052%2Fmergesorts-merge-function-loop-invariant&psig=AOvVaw27QxdYJ7liZw9lx7bUoqgg&ust=1702313757943000&source=images&cd=vfe&opi=89978449&ved=0CBIQjRxqFwoTCIiamYmrhYMDFQAAAAAdAAAAABAD