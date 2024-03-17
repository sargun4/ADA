class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> map;
        int res=0;
        int currsum=0;
        map[0]=1;//0 currsum exists once initally
        for(int &num : nums){
            currsum+=num;
            int remsum=currsum-goal;
            if(map.find(remsum)!=map.end()){ //if remmsum already exist in map
                res+=map[remsum];
            }
            map[currsum]++;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        res[0]=1;
        for(int i=1;i<n;i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int rightprod=1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*rightprod;
            rightprod*=nums[i];
        }
        return res;
    }
};