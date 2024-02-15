// Partition Equal Subset Sum

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool subsetSumtoK(int n,int k,int arr[]){//space optimization
        vector<bool> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=true;
        prev[arr[0]]=true;
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(arr[idx]<=target){
                    take=prev[target-arr[idx]];
                    curr[target]=take||nottake;
                }
                prev=curr;
            }
            return prev[k];
        }
    }
    int equalPartition(int N, int arr[]){
        int totsum=0;
        for (int i = 0; i < N; i++) totsum+=arr[i];
        if(totsum%2)return false;
        int target=totsum/2;
        return subsetSumtoK(N,target,arr);

    }
};