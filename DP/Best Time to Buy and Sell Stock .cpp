
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprof=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-mini;
            maxprof=max(maxprof,cost);
            mini=min(mini,prices[i]);
        }
        return maxprof;
    }
};