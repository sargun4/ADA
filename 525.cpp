#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;//{currsum:idx}
        int currsum = 0;
        map[0]=-1;
        int res=0;
        for(int i=0;i<n;i++){
            currsum+=(nums[i]==1)?1:-1;
            if(map.find(currsum)!=map.end()){
                res=max(res,i-map[currsum]);
            }else{
                map[currsum]=1;
            }
        }
        return res;
    }
};