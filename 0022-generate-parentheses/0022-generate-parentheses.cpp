class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        rec(2*n,curr,res,0,0);
        return res;
    }
    void rec(int len,string& curr,vector<string>&res,int open,int close){
      
        if(curr.length()==len){
            res.push_back(curr);
            return;
        }
        if(open<len/2){
            curr.push_back('(');
            rec(len,curr,res,open+1,close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            rec(len,curr,res,open,close+1);
            curr.pop_back();
        }
    }
};