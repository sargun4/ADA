 

// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(int i,int target,vector<int> &ans,vector<int> &arr){
        if(target==0) return 0;
        if(i==0){
            if(target%arr[i]==0){
                ans.push_back(arr[i]); // storing the values of coins
                return target/arr[i];
            }
            else return 1e8;
        }
        
        int nottake =INT_MAX;
        int take=INT_MAX;
        if(arr[i]<=target){
            ans.push_back(arr[i]); // storing the values of coins
            take=1+solve(i,target-arr[i],ans,arr); // for calculating the number of coins
        }
        else
            nottake=solve(i-1,target,ans,arr);
        return min(take,nottake);
    }
    vector<int> minPartition(int N){ 
        vector<int> ans;
        vector<int> arr ={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int mincoins=solve(9,N,ans,arr);
        //cout<< mincoins <<endl;
        return ans;
    }
};

 