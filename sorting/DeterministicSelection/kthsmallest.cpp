// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Using partition technique
#include <bits/stdc++.h>
using namespace std; 
class Solution{
    public: 
    int partition(int arr[], int l, int r) {
        int pivot = arr[l];
        int count = 0;
        for(int i = l+1; i <= r; ++i) {
            if(arr[i] <= pivot) {
                ++count;
            }
        }
        int pivotIndex = l + count;
        swap(arr[pivotIndex],arr[l]);
        int i = l, j = r;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }
        return pivotIndex;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        int pivotIndex = partition(arr,l,r);
        if(pivotIndex == k-1) {
            return arr[pivotIndex];
        }
        if(pivotIndex > k-1) {
            return kthSmallest(arr,l,pivotIndex,k);  
        }
        return kthSmallest(arr,pivotIndex+1,r,k);
    }
};
// //O(n*logk)
// class Solution{
//     public:
//     int kthSmallest(int arr[], int l, int r, int k) {
//         priority_queue<int> maxHeap;
//         for(int i=0; i<=r; i++){
//             maxHeap.push(arr[i]);
//             if(maxHeap.size()>k){ 
//                 maxHeap.pop(); 
//             }
//         }
//         return maxHeap.top();
//     }
// };