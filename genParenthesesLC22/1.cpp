#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    void comb(int open,int close,vector<string> &res,string str){
        if (open == 0 and close == 0){
            res.push_back(str);
            return;
        }
        if (open > 0){
            comb(open-1,close,res,str+"(");
        }
        if (close > 0 && close>open){
            comb(open,close-1,res,str+")");
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        comb(n,n,res,"");
        return res;
    }
};