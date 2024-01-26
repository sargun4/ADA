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
            str.push_back('(');
            comb(open-1,close,res,str);
            str.pop_back();
        }
        if (close > 0 && close>open){
            str.push_back('(');
            comb(open,close-1,res,str);
            str.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string val="";
        comb(n,n,res,val);
        return res;
    }
};