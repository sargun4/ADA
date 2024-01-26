#include <bits/stdc++.h>
using namespace std; 
const int mod = 1e9 + 7; 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<pair<int, int>> sLeft, sRight; // store index and value of array

        for (int i = 0; i < n; i++) {
            int ctr = 1;
            while (!sLeft.empty() && arr[i] < sLeft.top().first) {
                ctr += sLeft.top().second;
                sLeft.pop();
            }
            sLeft.push({ arr[i], ctr });
            left[i] = ctr;
        } 
        for (int i = n - 1; i >= 0; i--) {
            int ctr = 1;
            while (!sRight.empty() && arr[i] <= sRight.top().first) {
                ctr += sRight.top().second;
                sRight.pop();
            }
            sRight.push({ arr[i], ctr });
            right[i] = ctr;
        } 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (arr[i] * static_cast<long long>(left[i] * right[i]) % mod) % mod) % mod;
        } 
        return ans;
    }
};
