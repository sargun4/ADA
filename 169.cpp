
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityctr=nums.size()/2;
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto &it :freq){
            int fr=it.second;
            int key=it.first;
            if(fr>majorityctr){
                return key;
            }
        }
        return -1;
    }
};