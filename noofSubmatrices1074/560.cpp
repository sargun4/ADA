#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int res=0;
        int currsum=0;
        map.insert({0,1});
        for (int i = 0; i < nums.size(); i++){
            currsum+=nums[i];
            if (map.find(currsum-k) != map.end()){   // find the pair sum in hashmap
                res+=map[currsum-k];
            }
            map[currsum]++;
        }
        return res;
    }
};