// The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
// Create a function merge that counts the number of inversions when two halves of the array are merged, 
// Create two indices i and j, i is the index for the first half, and j is an index of the second half. 
// If a[i] is greater than a[j], then there are (mid – i) inversions because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// Create a recursive function to divide the array into halves and find the answer by summing the number of inversions in the first half, the number of inversions in the second half and the number of inversions by merging the two.
// The base case of recursion is when there is only one element in the given half.
#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		int right);

// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		// Divide the array into two parts and
		// call _mergeSortAndCountInv()
		// for each of the parts
		mid = (right + left) / 2;

		// Inversion count will be sum of
		// inversions in left-part, right-part
		// and number of inversions in merging
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		// Merge the two parts
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			// this is tricky -- see above
			// explanation/diagram for merge()
			inv_count = inv_count + (mid - i);
		}
	}

	// Copy the remaining elements of left subarray
	// (if there are any) to temp
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	// Copy the remaining elements of right subarray
	// (if there are any) to temp
	while (j <= right)
		temp[k++] = arr[j++];

	// Copy back the merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

// Driver code
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}

// This is code is contributed by rathbhupendra
