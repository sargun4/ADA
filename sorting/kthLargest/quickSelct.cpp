#include <bits/stdc++.h>
using namespace std; 
// QUICKSELECT using MEDIAN of MEDIANS algo
class Solution {
public:
    int choosePivot(vector<int>& nums, int n) {
        // Split nums into groups of 5 and sort each group
        vector<int> medians;

        for (int i = 0; i < n; i += 5) {
            vector<int> group(nums.begin() + i, nums.begin() + min(i + 5, n));
            // for (int i = 0; i < n; i++) {
            //     cout<<group[i];
            // }
            sort(group.begin(), group.end());
            medians.push_back(group[group.size() / 2]);
        }

        // Recursively call choosePivot on the medians array
        if (medians.size() <= 5) {
            sort(medians.begin(), medians.end());
            return medians[medians.size() / 2];
        } else {
            return choosePivot(medians, medians.size()/2);
        }
    }


    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int p = choosePivot(nums, n);

        vector<int> left, right;

        for (int i = 0; i < n; i++) {
            if (nums[i] < p) {
                left.push_back(nums[i]);
            } else if (nums[i] > p) {
                right.push_back(nums[i]);
            }
        }

        int len = right.size();

        if (len == k - 1) {
            return p;
        } else if (len >= k) {
            return findKthLargest(right, k);
        } else {
// Here, we should search in the left part for the (k - len - 1)-th largest element
            return findKthLargest(left, k - left.size() - 1);
        }
    }
};


// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>> pq; //min heap
//         for(int &num:nums){
//             pq.push(num);
//             if(pq.size()>k){
//                 pq.pop();
//             }
//         }
//         return pq.top(); //O(n*logk)
//     }
// };
// // class Solution {
// // public:
// //     int findKthLargest(vector<int>& nums, int k) {
// //         sort(begin(nums),end(nums),greater<int>());
// //         return nums[k-1];
// //     }
// // };