class Solution {
public:
    int dp[101][101];
    int countsteps(int ringidx,int i,int n){
        int dist=abs(i-ringidx);
        int wraparound=n-dist;
        return min(dist,wraparound);
    }
    int solve(int ringidx,int keyidx,string&ring,string&key){
        if(keyidx==key.length()){
            return 0;
        }
        if(dp[ringidx][keyidx]!=-1){
            return dp[ringidx][keyidx];
        }
        int res=INT_MAX;
        for(int i=0;i<ring.length();i++){
            if(ring[i]==key[keyidx]){
                int totalsteps=countsteps(ringidx,i,ring.length())+1+
                                solve(i,keyidx+1,ring,key);
                res=min(res,totalsteps);
            }
        }
        return  dp[ringidx][keyidx]=res;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,ring ,key);
    }
};