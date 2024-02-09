// /tle
// class Solution {
//   public:
//     int nthFibonacci(int n){
//         if(n==0||n==1){
//             return n;
//         }
//         return nthFibonacci(n-1)+nthFibonacci(n-2);
//     }
// };

#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int nthFibonacci(int n){
        vector<int> DP(n+1,0);
        DP[0]=0;
        DP[1]=1;
        for(int i=2;i<=n;i++)
        DP[i]=(DP[i-1]+DP[i-2])%mod;
        
        return DP[n];
    }
};