
#include <bits/stdc++.h>
using namespace std;
//spaceopt
class Solution{
public: 
    int cutRod(int price[], int n) {
        // vector<vector<int>> dp(n,vector<int>(n+1,0));
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int j=0;j<=n;j++){
            prev[j]=j*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int skip=0+prev[j];
                int take=INT_MIN;
                int rodlen=i+1;
                if(rodlen<=j){
                    take=price[i]+curr[j-rodlen];
                }
                curr[j]=max(take,skip);
            }
            prev=curr;
        }
        return prev[n];
    }
};
 