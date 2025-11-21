class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(first[curr]==-1){
                first[curr]=i;
            }
            last[curr]=i;
        }
        for(int i=0;i<26;i++){
            if(first[i]==-1)continue;
            unordered_set<char>bet;
            for(int k=first[i]+1;k<last[i];k++){
                bet.insert(s[k]);
            }
            ans+=bet.size();
        }
        return ans;
    }
};