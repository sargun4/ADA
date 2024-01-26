#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq; //min heap
        for(int &num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top(); //O(n*logk)
    }
};
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(begin(nums),end(nums),greater<int>());
//         return nums[k-1];
//     }
// };