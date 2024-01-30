 
#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public:
    int matrixMultiplication(int n, int arr[]){
        // 0th row and 0th column of m[][] are not used
        int m[n][n];
     
        int i, j, k, L, q;
     
        // m[i, j] = Minimum number of scalar multiplications needed to compute the
        // matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is arr[i-1] x arr[i] 
     
        // cost is zero when multiplying one matrix.
        for (i = 1; i < n; i++)
            m[i][i] = 0;
     
        // L is chain length.
        for (L = 2; L < n; L++) {
            for (i = 1; i < n - L + 1; i++) {
                j = i + L - 1;
                m[i][j] = INT_MAX;
                for (k = i; k <= j - 1; k++) {
                    // q = cost or scalar multiplications
                    q = m[i][k] + m[k + 1][j]
                        + arr[i - 1] * arr[k] * arr[j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
        return m[1][n - 1];
    }
};
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(n, arr)<<endl;
    }
    return 0;
} 