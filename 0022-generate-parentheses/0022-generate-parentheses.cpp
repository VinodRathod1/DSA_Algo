class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        
        rec(2*n,res,"",0,0);
        return res;
    }
    void rec(int len,vector<string>&res,string curr,int open,int close){
        if(open>(len/2) || close>(len/2) || close>open)return;
        if(curr.length()==len){
            res.push_back(curr);
            return;
        }
        
        rec(len,res,curr+"(",open+1,close);
        rec(len,res,curr+")",open,close+1);
    }
};