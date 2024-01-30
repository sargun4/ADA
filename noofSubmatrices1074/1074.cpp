#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        //first take row wise cumulative sum
        for(int row=0; row<rows; row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }
        //now find no of subarrs w sum==target(LC560)-downwards dirn
        int res=0;
        for(int startcol=0;startcol<cols;startcol++){
            for(int j=startcol; j<cols; j++){
                unordered_map<int,int> map;
                map.insert({0,1});
                int currsum=0;
                for(int row=0;row<rows;row++){
                    currsum+=matrix[row][j]-(startcol>0 ? matrix[row][startcol-1] : 0);
                    if(map.find(currsum-target)!=map.end()){
                        res+=map[currsum-target];
                    }
                    map[currsum]++; 
                }
            }
        }
        return res;
    }
};