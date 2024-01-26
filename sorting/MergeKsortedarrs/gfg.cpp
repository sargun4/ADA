#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> merge(vector<int>& a1, vector<int>& a2) {
        int len1 = a1.size();
        int len2 = a2.size();
        int i = 0, j = 0;
        vector<int> merged;

        while (i < len1 && j < len2) {
            if (a1[i] < a2[j]) {
                merged.push_back(a1[i]);
                i++;
            } else {
                merged.push_back(a2[j]);
                j++;
            }
        } 
        while (i < len1) {
            merged.push_back(a1[i]);
            i++;
        } 
        while (j < len2) {
            merged.push_back(a2[j]);
            j++;
        } 
        return merged;
    }
    vector<int> mergeKArraysHelper(vector<vector<int>>& arr, int start, int end) {
        if (start == end) {
            return arr[start];
        }
        int mid = (start + end) / 2;
        vector<int> arr1 = mergeKArraysHelper(arr, start, mid);
        vector<int> arr2 = mergeKArraysHelper(arr, mid + 1, end);
        return merge(arr1, arr2);
    }
    vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {
        if (K == 0) return vector<int>();
        return mergeKArraysHelper(arr, 0, K - 1);
    }
};
